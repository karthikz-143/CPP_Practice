#include <iostream>
#include "TicTacToe.h"

int main() {
    TicTacToe game;
    int currentPlayer = 1;
    int row, col;

    std::cout << "Welcome to Tic-Tac-Toe!\n";
    game.printBoard();

    while (true) {
        std::cout << "Player " << currentPlayer 
                  << " (" << (currentPlayer == 1 ? 'X' : 'O') << ") - Enter row and column (0-2): ";
        std::cin >> row >> col;

        if (!game.makeMove(currentPlayer, row, col)) {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        game.printBoard();

        int winner = game.checkWin();
        if (winner != 0) {
            std::cout << "Player " << winner << " wins!\n";
            break;
        }

        if (game.isDraw()) {
            std::cout << "The game is a draw!\n";
            break;
        }

        // switch players
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}
