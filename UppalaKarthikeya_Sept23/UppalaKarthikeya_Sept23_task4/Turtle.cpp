#include <iostream>
#include "Turtle.h"

void move(bool floor[SIZE][SIZE], int &row, int &col, Direction dir, bool penDown, int spaces) {
    for (int step = 0; step < spaces; step++) {
        if (penDown) {
            floor[row][col] = true;
        }
        // Move in current direction
        switch (dir) {
            case RIGHT: if (col + 1 < SIZE) col++; break;
            case DOWN:  if (row + 1 < SIZE) row++; break;
            case LEFT:  if (col - 1 >= 0) col--; break;
            case UP:    if (row - 1 >= 0) row--; break;
        }
    }
}

void printFloor(bool floor[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (floor[r][c]) std::cout << "*";
            else std::cout << " ";
        }
        std::cout << "\n";
    }
}

void processCommands(const int commands[][2], int numCommands) {
    bool floor[SIZE][SIZE] = {false};
    int row = 0, col = 0;
    bool penDown = false;
    Direction dir = RIGHT;

    for (int i = 0; i < numCommands; i++) {
        int cmd = commands[i][0];
        int value = commands[i][1];

        switch (cmd) {
            case 1: // Pen up
                penDown = false;
                break;
            case 2: // Pen down
                penDown = true;
                break;
            case 3: // Turn right
                dir = static_cast<Direction>((dir + 1) % 4);
                break;
            case 4: // Turn left
                dir = static_cast<Direction>((dir + 3) % 4);
                break;
            case 5: // Move forward
                move(floor, row, col, dir, penDown, value);
                break;
            case 6: // Print floor
                printFloor(floor);
                break;
            case 9: // End of data
                return;
            default:
                std::cout << "Unknown command: " << cmd << "\n";
        }
    }
}
