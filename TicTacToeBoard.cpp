#include "TicTacToeBoard.h"
#include <iostream>
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  
  if(turn == X){
    turn = O;
    return turn;
  }else{
    turn = X;
    return turn;
  }
  
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if(row < 1 || row > BOARDSIZE || column < 1 || column > BOARDSIZE){
     return Invalid;
  }else if(board[row-1][column-1] == Blank && turn != Invalid){
     board[row-1][column-1] = turn;
     if(toggleTurn() == O){
        return X;
     }
     return O;
  }else{
     return board[row-1][column-1];
  }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row < 1 || row > BOARDSIZE || column < 1 || column > BOARDSIZE){
     return Invalid;
  }
  return board[row-1][column-1];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  int x1, o1, x2, o2, blank = 0;
   x1 = 0;
   o1 = 0;
   x2 = 0;
   o2 = 0;

  //check diagonals
  for(int i = 0; i < BOARDSIZE; i++){
     //check first diagonal
     if(board[i][i] == X){
        x1++;
     }else if(board[i][i] == O){
        o1++;
     }else if(board[i][i] == Blank){
        blank++;
     }
     //check opposite diagonal
     if(board[i][BOARDSIZE - i - 1] == X){
        x2++;
     }else if(board[i][BOARDSIZE - i - 1] == O){
        o2++;
     }else if(board[i][BOARDSIZE - i - 1] == Blank){
        blank++;
     }
     if(x1 == 3 || x2 == 3){
       turn = Invalid;
       return X;
     }
     if(o1 == 3 || o2 == 3){
       turn = Invalid;
       return O;
     }
  
  }
  //check rows
  for(int i = 0; i < BOARDSIZE; i++){    //no winner yet if executing
     x1 = 0;
     o1 = 0;
     x2 = 0;
     o2 = 0;
     for(int j = 0; j < BOARDSIZE; j++){
        //Check rows
        if(board[i][j] == X){
           x1++;
        }else if(board[i][j] == O){
           o1++;
        }else if(board[i][j] == Blank){
           blank++;
        }
        //Check columns
        if(board[j][i] == X){
           x2++;
        }else if(board[j][i] == O){
           o2++;
        }else if(board[j][i] == Blank){
           blank++;
        }
        if(x1 == 3 || x2 == 3){
          turn = Invalid;
          return X;
        }
        if(o1 == 3 || o2 == 3){
          turn = Invalid;
          return O;
        }
     }
  }
  if(blank == 0){      //if executing, no winner
     return Blank;  //game still going
  }
  return Invalid;     //cat's game
}

