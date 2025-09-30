#ifndef MAZE_H
#define MAZE_H

#include <iostream>

const int SIZE = 12;

enum Direction { RIGHT, DOWN, LEFT, UP };

// Function declarations
void printMaze(const char maze[SIZE][SIZE]);
void mazeTraverse(char maze[SIZE][SIZE], int row, int col, Direction dir);

#endif
