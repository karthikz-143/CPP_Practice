#include "Maze.h"

void printMaze(const char maze[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
}

// Helper: turn right
Direction turnRight(Direction dir) {
    return static_cast<Direction>((dir + 1) % 4);
}

// Helper: turn left
Direction turnLeft(Direction dir) {
    return static_cast<Direction>((dir + 3) % 4);
}

// Maze traversal using recursion
void mazeTraverse(char maze[SIZE][SIZE], int row, int col, Direction dir) {
    // Mark the current cell as visited
    maze[row][col] = 'X';
    printMaze(maze);

    
    if ((row == 0 || row == SIZE - 1 || col == 0 || col == SIZE - 1) && maze[row][col] == 'X') {
        std::cout << "Exit found at (" << row << ", " << col << ")" << std::endl;
        return;
    }

    // Possible movements: up, right, down, left
    int moveRow[] = {0, 1, 0, -1};
    int moveCol[] = {1, 0, -1, 0};

    // Try all 4 directions based on right-hand rule
    for (int i = 0; i < 4; i++) {
        // Check right-hand rule first
        dir = turnRight(dir);

        int nextRow = row + moveRow[dir];
        int nextCol = col + moveCol[dir];

        if (nextRow >= 0 && nextRow < SIZE &&
            nextCol >= 0 && nextCol < SIZE &&
            (maze[nextRow][nextCol] == '.' )) {
            
            mazeTraverse(maze, nextRow, nextCol, dir);
            return;
        }
    }
}
