#include "Simpletron.h"
#include <vector>
#include <iostream>

int main() {
    Simpletron sml;
    std::vector<int> program = {
        1007, 
        1008,
        2007, 
        3008, 
        2109, 
        1109, 
        4300, 
        0000, 
        0000, 
        0000  
    };

    sml.loadProgram(program);
    sml.execute();
    sml.dumpMemory(); // Optional: See memory state after run

    return 0;
}
