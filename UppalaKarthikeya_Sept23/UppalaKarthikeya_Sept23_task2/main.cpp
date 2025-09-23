#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Craps.h"

int main() {
    const int GAMES = 1000;
    const int MAX_ROLLS = 20; 

    int wins[MAX_ROLLS + 1] = {0};   
    int losses[MAX_ROLLS + 1] = {0};

    int totalWins = 0, totalLosses = 0;
    long totalRolls = 0;

    // Seed random number generator
    std::srand(static_cast<unsigned>(std::time(0)));

    
    for (int i = 0; i < GAMES; i++) {
        int result = playGame();
        int rolls = (result > 0) ? result : -result; 
        totalRolls += rolls;

        if (rolls > MAX_ROLLS) rolls = MAX_ROLLS; 

        if (result > 0) { 
            wins[rolls]++;
            totalWins++;
        } else {
            losses[rolls]++;
            totalLosses++;
        }
    }

    // Display results
    std::cout << "Craps Statistics after " << GAMES << " games:\n\n";

    for (int i = 1; i <= MAX_ROLLS; i++) {
        std::cout << "Wins on roll " << i << ": " << wins[i] 
                  << " | Losses on roll " << i << ": " << losses[i] << "\n";
    }
    std::cout << "Wins after 20th roll: " << wins[MAX_ROLLS] 
              << " | Losses after 20th roll: " << losses[MAX_ROLLS] << "\n\n";

    std::cout << "Total Wins: " << totalWins << "\n";
    std::cout << "Total Losses: " << totalLosses << "\n";

    double winChance = (static_cast<double>(totalWins) / GAMES) * 100.0;
    std::cout << "Chance of Winning: " << winChance << "%\n";

    double avgLength = static_cast<double>(totalRolls) / GAMES;
    std::cout << "Average Game Length: " << avgLength << " rolls\n";

    std::cout << "Observation: Chances of winning do NOT improve with longer games.\n";
    std::cout << "Craps is considered fair because odds are close to 50-50.\n";

    return 0;
}
