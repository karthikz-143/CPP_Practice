#ifndef SIMPLETRON_H
#define SIMPLETRON_H

#include <iostream>
#include <vector>

class Simpletron {
private:
    static const int MEMORY_SIZE = 100;
    int memory[MEMORY_SIZE];   
    int accumulator;           
    int instructionCounter;    
    int instructionRegister;   
    int operationCode;         
    int operand;               

public:
    // Operation codes
    static const int READ = 10;
    static const int WRITE = 11;
    static const int LOAD = 20;
    static const int STORE = 21;
    static const int ADD = 30;
    static const int SUBTRACT = 31;
    static const int DIVIDE = 32;
    static const int MULTIPLY = 33;
    static const int BRANCH = 40;
    static const int BRANCHNEG = 41;
    static const int BRANCHZERO = 42;
    static const int HALT = 43;

    Simpletron();  

    void loadProgram(const std::vector<int>& program);
    void execute();
    void dumpMemory() const;  // Debugging helper
};

#endif
