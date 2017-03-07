/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
TEST(TicTacToeBoardTest, XwinsCol)
{
	TicTacToeBoard Tic;
	Piece actual;
	actual = Tic.placePiece(0,0);
	actual = Tic.placePiece(2,2);
	actual = Tic.placePiece(1,0);
	actual = Tic.placePiece(2,2);
	actual = Tic.placePiece(2,0);
	actual = Tic.getWinner();
	ASSERT_EQ(actual,X);
}
TEST(TicTacToeBoardTest, XwinsRow)
{
	TicTacToeBoard Tic;
	Piece actual;
	actual = Tic.placePiece(0,0);
	actual = Tic.placePiece(2,2);
	actual = Tic.placePiece(0,1);
	actual = Tic.placePiece(2,2);
	actual = Tic.placePiece(0,2);
	actual = Tic.getWinner();
	ASSERT_EQ(actual,X);
}
TEST(TicTacToeBoardTest, NoWinner)
{
	TicTacToeBoard Tic;
	Piece actual;
	actual = Tic.placePiece(0,0);
	actual = Tic.placePiece(0,1);
	actual = Tic.placePiece(0,2);
	actual = Tic.placePiece(2,0);
	actual = Tic.placePiece(2,1);
	actual = Tic.placePiece(2,2);
	actual = Tic.placePiece(1,0);
	actual = Tic.placePiece(1,1);
	actual = Tic.placePiece(1,2);
	actual = Tic.getWinner();
	ASSERT_EQ(actual,Blank);
}
TEST(TicTacToeBoardTest, ToggleX)
{
	TicTacToeBoard Tic;
	Piece actual;
	actual = Tic.getPiece(0,0);
	ASSERT_EQ(actual,Blank);
}

TEST(TicTacToeBoardTest, GetPieceBlank)
{
	TicTacToeBoard Tic;
	Piece actual;
	actual = Tic.getPiece(0,0);
	ASSERT_EQ(actual,Blank);
}
TEST(TicTacToeBoardTest, GetPieceOutofBoundCol)
{
	TicTacToeBoard Tic;
	Piece actual;
	actual = Tic.getPiece(0,5);
	ASSERT_EQ(actual,Invalid);
}
TEST(TicTacToeBoardTest, GetPieceOutofBoundRow)
{
	TicTacToeBoard Tic;
	Piece actual;
	actual = Tic.getPiece(5,0);
	ASSERT_EQ(actual,Invalid);
}

TEST(TicTacToeBoardTest, PlaceX)
{
	TicTacToeBoard Tic;
	Piece actual;
	actual = Tic.placePiece(0,0);
	ASSERT_EQ(actual, X);
}
TEST(TicTacToeBoardTest, PlaceO)
{
	TicTacToeBoard Tic;
	Piece actual;
	actual = Tic.placePiece(0,0);
	actual = Tic.placePiece(0,1);
	ASSERT_EQ(actual, O);
}
TEST(TicTacToeBoardTest, PlaceOnX)
{
	TicTacToeBoard Tic;
	Piece actual;
	actual = Tic.placePiece(0,0);
	actual = Tic.placePiece(0,0);
	ASSERT_EQ(actual, X);
}
TEST(TicTacToeBoardTest, PlaceOnO)
{
	TicTacToeBoard Tic;
	Piece actual;
	actual = Tic.placePiece(0,0);
	actual = Tic.placePiece(0,1);
	actual = Tic.placePiece(0,1);
	ASSERT_EQ(actual, O);
}
TEST(TicTacToeBoardTest, PlaceOutofBoundRow)
{
	TicTacToeBoard Tic;
	Piece actual;
	actual = Tic.placePiece(5,0);
	ASSERT_EQ(actual, Invalid);
}
TEST(TicTacToeBoardTest, PlaceOutofBoundCol)
{
	TicTacToeBoard Tic;
	Piece actual;
	actual = Tic.placePiece(0,5);
	ASSERT_EQ(actual, Invalid);
}

TEST(TicTacToeBoardTest, IncorrectPlacing)
{
	TicTacToeBoard Tic;
	Piece actual;
	actual = Tic.placePiece(4,5);
	ASSERT_EQ(actual,Invalid); 
}
TEST(TicTacToeBoardTest, ClearBoardPass)
{
	TicTacToeBoard Tic;
	Piece actual;
	Tic.placePiece(0,0);
	Tic.clearBoard();
	actual = Tic.getPiece(0,0);
	ASSERT_EQ(actual,Blank);
}
