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

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

/*Tests toggleTurn()*/
TEST(TicTacToeBoardTest, turn_is_o)
{
  TicTacToeBoard obj;
  ASSERT_EQ(O, obj.toggleTurn());
}

TEST(TicTacToeBoardTest, turn_is_x)
{
  TicTacToeBoard obj;
  obj.toggleTurn();
  ASSERT_EQ(X, obj.toggleTurn());
}

/*Tests placePiece()*/
TEST(TicTacToeBoardTest, place_valid)
{
   TicTacToeBoard obj;
   ASSERT_EQ(X, obj.placePiece(2, 2));
}

TEST(TicTacToeBoardTest, place_invalid_row)
{
   TicTacToeBoard obj;
   ASSERT_EQ(Invalid, obj.placePiece(4, 2));
}

TEST(TicTacToeBoardTest, place_invalid_col)
{
   TicTacToeBoard obj;
   ASSERT_EQ(Invalid, obj.placePiece(3, 4));
}

TEST(TicTacToeBoardTest, place_neg_row)
{
   TicTacToeBoard obj;
   ASSERT_EQ(Invalid, obj.placePiece(-1, 2));
}

TEST(TicTacToeBoardTest, place_neg_col)
{
   TicTacToeBoard obj;
   ASSERT_EQ(Invalid, obj.placePiece(3, -2));
}

TEST(TicTacToeBoardTest, place_zero_row)
{
   TicTacToeBoard obj;
   ASSERT_EQ(Invalid, obj.placePiece(0, 3));
}
TEST(TicTacToeBoardTest, place_zero_col)
{
   TicTacToeBoard obj;
   ASSERT_EQ(Invalid, obj.placePiece(2, 0));
}

TEST(TicTacToeBoardTest, place_on_occupied)
{
   TicTacToeBoard obj;
   ASSERT_EQ(X, obj.placePiece(2,2));
   ASSERT_EQ(X, obj.placePiece(2,2));
}

TEST(TicTacToeBoardTest, place_2_valid)     //place 2 valid pieces
{
   TicTacToeBoard obj;
   ASSERT_EQ(X, obj.placePiece(3,2));
   ASSERT_EQ(O, obj.placePiece(1,2));
}

/*Tests getPiece()*/
TEST(TicTacToeBoardTest, get_x)
{
   TicTacToeBoard obj;
   obj.placePiece(2,2);
   ASSERT_EQ(X, obj.getPiece(2, 2));
}

TEST(TicTacToeBoardTest, get_o)
{
   TicTacToeBoard obj;
   obj.placePiece(2,2);
   obj.placePiece(3, 2);
   ASSERT_EQ(O, obj.getPiece(3, 2));
}

TEST(TicTacToeBoardTest, get_full_board)
{
   TicTacToeBoard obj;
   obj.placePiece(1,1);
   obj.placePiece(1,2);
   obj.placePiece(1,3);
   obj.placePiece(3,1);
   obj.placePiece(2,2);
   obj.placePiece(3,3);
   obj.placePiece(3,2);
   obj.placePiece(2,3);
   obj.placePiece(2,1);
   ASSERT_EQ(X, obj.getPiece(1, 1));
   ASSERT_EQ(O, obj.getPiece(1, 2));
   ASSERT_EQ(X, obj.getPiece(1, 3));
   ASSERT_EQ(X, obj.getPiece(2, 1));
   ASSERT_EQ(X, obj.getPiece(2, 2));
   ASSERT_EQ(O, obj.getPiece(2, 3));
   ASSERT_EQ(O, obj.getPiece(3, 1));
   ASSERT_EQ(X, obj.getPiece(3, 2));
   ASSERT_EQ(O, obj.getPiece(3, 3));
}

TEST(TicTacToeBoardTest, place_same_piece_get)
{
   TicTacToeBoard obj;
   obj.placePiece(1,1);
   obj.placePiece(1,1);
   ASSERT_EQ(X, obj.getPiece(1, 1));
}

TEST(TicTacToeBoardTest, get_empty)
{
   TicTacToeBoard obj;
   obj.placePiece(1,1);
   obj.placePiece(2,1);
   ASSERT_EQ(Blank, obj.getPiece(3, 3));
}

TEST(TicTacToeBoardTest, get_invalid)
{
   TicTacToeBoard obj;
   obj.placePiece(1,1);
   obj.placePiece(2,1);
   ASSERT_EQ(Invalid, obj.getPiece(3, 4));
}


/*getWinner()*/
TEST(TicTacToeBoardTest, x_win_row_1)
{
   TicTacToeBoard obj;
   obj.placePiece(1,1);
   obj.placePiece(2,1);
   obj.placePiece(1,2);
   obj.placePiece(2,2);
   obj.placePiece(1,3);
   ASSERT_EQ(X, obj.getWinner());
}

TEST(TicTacToeBoardTest, o_win_row_2)
{
   TicTacToeBoard obj;
   obj.placePiece(1,1);
   obj.placePiece(2,1);
   obj.placePiece(1,2);
   obj.placePiece(2,2);
   obj.placePiece(3,1);
   obj.placePiece(2,3);
   ASSERT_EQ(O, obj.getWinner());
}

TEST(TicTacToeBoardTest, x_win_row_3)
{
   TicTacToeBoard obj;
   obj.placePiece(3,1);
   obj.placePiece(2,1);
   obj.placePiece(3,2);
   obj.placePiece(2,2);
   obj.placePiece(3,3);
   ASSERT_EQ(X, obj.getWinner());
}

TEST(TicTacToeBoardTest, o_win_col_1)
{
   TicTacToeBoard obj;
   obj.placePiece(3,3);
   obj.placePiece(2,1);
   obj.placePiece(2,3);
   obj.placePiece(1,1);
   obj.placePiece(2,2);
   obj.placePiece(3,1);
   ASSERT_EQ(O, obj.getWinner());
}

TEST(TicTacToeBoardTest, x_win_col_2)
{
   TicTacToeBoard obj;
   obj.placePiece(1,2);
   obj.placePiece(2,1);
   obj.placePiece(2,2);
   obj.placePiece(3,1);
   obj.placePiece(3,2);
   ASSERT_EQ(X, obj.getWinner());
}

TEST(TicTacToeBoardTest, o_win_col_3)
{
   TicTacToeBoard obj;
   obj.placePiece(3,2);
   obj.placePiece(2,3);
   obj.placePiece(2,1);
   obj.placePiece(1,3);
   obj.placePiece(3,1);
   obj.placePiece(3,3);
   ASSERT_EQ(O, obj.getWinner());
}

TEST(TicTacToeBoardTest, X_win_diag_1)
{
   TicTacToeBoard obj;
   obj.placePiece(1,1);
   obj.placePiece(2,3);
   obj.placePiece(2,2);
   obj.placePiece(1,3);
   obj.placePiece(3,3);
   ASSERT_EQ(X, obj.getWinner());
}

TEST(TicTacToeBoardTest, o_win_diag_2)
{
   TicTacToeBoard obj;
   obj.placePiece(3,2);
   obj.placePiece(3,1);
   obj.placePiece(2,1);
   obj.placePiece(2,2);
   obj.placePiece(1,2);
   obj.placePiece(1,3);
   ASSERT_EQ(O, obj.getWinner());
}

TEST(TicTacToeBoardTest, game_still_going)
{
   TicTacToeBoard obj;
   obj.placePiece(3,2);
   obj.placePiece(3,1);
   obj.placePiece(2,1);
   ASSERT_EQ(Invalid, obj.getWinner());
}

TEST(TicTacToeBoardTest, cats_game)
{
   TicTacToeBoard obj;
   obj.placePiece(1,1);
   obj.placePiece(1,2);
   obj.placePiece(1,3);
   obj.placePiece(3,1);
   obj.placePiece(2,2);
   obj.placePiece(3,3);
   obj.placePiece(3,2);
   obj.placePiece(2,3);
   obj.placePiece(2,1);
   ASSERT_EQ(Blank, obj.getWinner());
}
