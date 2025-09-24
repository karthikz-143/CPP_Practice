#include "TicTacToe.h"

TicTacToe::TicTacToe() {
    // initialize board with 0
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = 0;
        }
    }
}

void TicTacToe::printBoard() const {
    std::cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            char symbol;
            if (board[i][j] == 1) symbol = 'X';
            else if (board[i][j] == 2) symbol = 'O';
            else symbol = ' ';
            std::cout << " " << symbol << " ";
            if (j < 2) std::cout << "|";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}

bool TicTacToe::makeMove(int player, int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        return false; // invalid index
    }
    if (board[row][col] != 0) {
        return false; // already occupied
    }
    board[row][col] = player;
    return true;
}

int TicTacToe::checkWin() const {
    // check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != 0 &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // check cols
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] != 0 &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // check diagonals
    if (board[0][0] != 0 &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        return board[0][0];
    }

    if (board[0][2] != 0 &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return 0; // no winner
}

bool TicTacToe::isDraw() const {
     // if someone won, not draw
    if (checkWin() != 0) return false;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 0) return false;
        }
    }
    return true;
}
