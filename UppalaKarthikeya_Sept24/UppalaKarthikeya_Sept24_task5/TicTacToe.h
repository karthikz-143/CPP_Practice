#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

class TicTacToe {
private:
    int board[3][3];  // 0 = empty, 1 = player1, 2 = player2

public:
    TicTacToe(); // constructor

    void printBoard() const;         // show board
    bool makeMove(int player, int row, int col); // attempt move
    int checkWin() const;            // 0 = no win, 1 = P1, 2 = P2
    bool isDraw() const;             // true if draw
};

#endif
