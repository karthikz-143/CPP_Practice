#include "Turtle.h"

int main() {
    // Commands to test the turtle graphics
    int commands[][2] = {
        {2, 0},   
        {5, 12},  
        {3, 0},   
        {5, 12},
        {3, 0},
        {5, 12},
        {3, 0},
        {5, 12},
        {1, 0},   
        {6, 0},   
        {9, 0}    
    };

    int numCommands = sizeof(commands) / sizeof(commands[0]);
    processCommands(commands, numCommands);

    return 0;
}
