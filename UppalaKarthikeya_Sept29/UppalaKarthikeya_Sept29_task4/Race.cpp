#include "Race.h"

// Updates tortoise's position based on random roll
void moveTortoise(int* tortoisePosition)
{
    int roll = 1 + std::rand() % 10;

    if (roll >= 1 && roll <= 5)         // Fast plod (50%)
    {
        *tortoisePosition += 3;
    }
    else if (roll == 6 || roll == 7)    // Slip (20%)
    {
        *tortoisePosition -= 6;
    }
    else                                // Slow plod (30%)
    {
        *tortoisePosition += 1;
    }

    if (*tortoisePosition < 1)
    {
        *tortoisePosition = 1;
    }
}
// Updates hare's position based on random roll
void moveHare(int* harePosition)
{
    int roll = 1 + std::rand() % 10;

    if (roll == 1 || roll == 2)         // Sleep (20%)
    {
        // No movement
    }
    else if (roll == 3 || roll == 4)    // Big hop (20%)
    {
        *harePosition += 9;
    }
    else if (roll == 5)                 // Big slip (10%)
    {
        *harePosition -= 12;
    }
    else if (roll >= 6 && roll <= 8)    // Small hop (30%)
    {
        *harePosition += 1;
    }
    else                                // Small slip (20%)
    {
        *harePosition -= 2;
    }

    if (*harePosition < 1)
    {
        *harePosition = 1;
    }
}

// Prints race track line for current tick
void printRaceTrack(int tortoisePosition, int harePosition)
{
    for (int i = 1; i <= TRACK_LENGTH; i++)
    {
        if (i == tortoisePosition && i == harePosition)
        {
            std::cout << "OUCH!!!";
            i += 5; // Skip next 5 positions
        }
        else if (i == tortoisePosition)
        {
            std::cout << "T";
        }
        else if (i == harePosition)
        {
            std::cout << "H";
        }
        else
        {
            std::cout << " ";
        }
    }
    std::cout << "\n";
}
