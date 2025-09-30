#include "Simpletron.h"
#include <iomanip>
#include <stdexcept>

Simpletron::Simpletron() {
    for (int i = 0; i < MEMORY_SIZE; i++)
        memory[i] = 0;
    accumulator = 0;
    instructionCounter = 0;
    instructionRegister = 0;
    operationCode = 0;
    operand = 0;
}

void Simpletron::loadProgram(const std::vector<int>& program) {
    for (size_t i = 0; i < program.size() && i < MEMORY_SIZE; i++) {
        memory[i] = program[i];
    }
}

void Simpletron::execute() {
    bool running = true;

    while (running) {
        instructionRegister = memory[instructionCounter];
        operationCode = instructionRegister / 100;
        operand = instructionRegister % 100;

        switch (operationCode) {
            case READ:
                std::cout << "Enter value: ";
                std::cin >> memory[operand];
                instructionCounter++;
                break;

            case WRITE:
                std::cout << "Output: " << memory[operand] << std::endl;
                instructionCounter++;
                break;

            case LOAD:
                accumulator = memory[operand];
                instructionCounter++;
                break;

            case STORE:
                memory[operand] = accumulator;
                instructionCounter++;
                break;

            case ADD:
                accumulator += memory[operand];
                instructionCounter++;
                break;

            case SUBTRACT:
                accumulator -= memory[operand];
                instructionCounter++;
                break;

            case DIVIDE:
                if (memory[operand] == 0)
                    throw std::runtime_error("Division by zero!");
                accumulator /= memory[operand];
                instructionCounter++;
                break;

            case MULTIPLY:
                accumulator *= memory[operand];
                instructionCounter++;
                break;

            case BRANCH:
                instructionCounter = operand;
                break;

            case BRANCHNEG:
                if (accumulator < 0)
                    instructionCounter = operand;
                else
                    instructionCounter++;
                break;

            case BRANCHZERO:
                if (accumulator == 0)
                    instructionCounter = operand;
                else
                    instructionCounter++;
                break;

            case HALT:
                std::cout << "*** Program execution ended ***" << std::endl;
                running = false;
                break;

            default:
                throw std::runtime_error("Invalid operation code!");
        }
    }
}

void Simpletron::dumpMemory() const {
    std::cout << "\nREGISTERS:\n";
    std::cout << "accumulator:            " << accumulator << "\n";
    std::cout << "instructionCounter:     " << instructionCounter << "\n";
    std::cout << "instructionRegister:    " << instructionRegister << "\n";
    std::cout << "operationCode:          " << operationCode << "\n";
    std::cout << "operand:                " << operand << "\n";

    std::cout << "\nMEMORY:\n     ";
    for (int i = 0; i < 10; i++)
        std::cout << std::setw(6) << i;
    std::cout << "\n";

    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (i % 10 == 0)
            std::cout << std::setw(2) << i << "  ";
        std::cout << std::setw(6) << memory[i];
        if ((i + 1) % 10 == 0)
            std::cout << "\n";
    }
}
