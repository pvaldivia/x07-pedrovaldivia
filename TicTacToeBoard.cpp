#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Switches turn member variable to represent whether it's X's or O's turn
void TicTacToeBoard::toggleTurn()
{
	if(turn == X)
	turn = O;
	else turn = X;
}

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
	turn = X;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			board[row][col] = Blank;
		}
	}
}

//Resets each board location to the Blank Piece value
void TicTacToeBoard::clearBoard()
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			board[row][col] = Blank;
		}
	}
	
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
	if ((row > 2 || row < 0) || (column > 2 || row < 0))
	return Invalid;
	Piece whoWon;
	if (turn == X)
	{
		if (board[row][column] != Blank)
		{
			toggleTurn();
			return board[row][column];
		}
		board[row][column] = X;
		toggleTurn();
	}
	else
	{		
		if (board[row][column] != Blank)
		{
			toggleTurn();
			return board[row][column];
		}
		board[row][column] = O;
		toggleTurn();
	}
	return board[row][column];
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
	if ((row > 2 || row < 0) || (column > 2 || row < 0))
	return Invalid;

	return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
	int check = 0;
	int winning = 0;
	Piece current;
	for (int row = 0; row < 3; row++)
	{
		current = board[row][0];
		for (int col = 0; col < 3; col++)
		{
			if (current == Blank || current != board[row][col])
			{
				col = 3;
				winning = 0;
				check++;
			}
			else
			winning++;		
		}
		if (winning == 3)
		{	
			clearBoard();
			return current;
		}
	}
	check = 0;
	winning = 0;
	for (int col = 0; col < 3; col++)
	{
		current = board[0][col];
		for (int row = 0; row < 3; row++)
		{
			if (current == Blank || current != board[row][col])
			{
				row = 3;
				winning = 0;
				check++;
			}
			else
			winning++;		
		}
		if (winning == 3)
		{	
			clearBoard();
			return current;
		}
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{	
		clearBoard();
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		clearBoard();
		return board[1][1];
	}

	check = 0;

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if(board[row][col] != Blank)
			check++;
		}
	}
	if (check == 9)
	{
		clearBoard();
		return Blank;
	}

	
  return Invalid;

}
