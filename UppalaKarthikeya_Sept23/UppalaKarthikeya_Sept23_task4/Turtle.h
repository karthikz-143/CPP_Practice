#ifndef TURTLE_H
#define TURTLE_H

const int SIZE = 20;

// Directions (0 = right, 1 = down, 2 = left, 3 = up)
enum Direction { RIGHT, DOWN, LEFT, UP };

// Function declarations
void processCommands(const int commands[][2], int numCommands);
void move(bool floor[SIZE][SIZE], int &row, int &col, Direction dir, bool penDown, int spaces);
void printFloor(bool floor[SIZE][SIZE]);

#endif
