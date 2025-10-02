#include "Race.h"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    int tortoisePosition = 1;
    int harePosition = 1;

    std::cout << "BANG !!!!!\n";
    std::cout << "AND THEY'RE OFF !!!!!\n";

    // Main race loop
    while (tortoisePosition < TRACK_LENGTH && harePosition < TRACK_LENGTH)
    {
        moveTortoise(&tortoisePosition);
        moveHare(&harePosition);

        if (tortoisePosition > TRACK_LENGTH) tortoisePosition = TRACK_LENGTH;
        if (harePosition > TRACK_LENGTH) harePosition = TRACK_LENGTH;

        printRaceTrack(tortoisePosition, harePosition);
    }

    // Race result
    if (tortoisePosition >= TRACK_LENGTH && harePosition >= TRACK_LENGTH)
    {
        std::cout << "It's a tie. Tortoise wins by favor!!!\n";
    }
    else if (tortoisePosition >= TRACK_LENGTH)
    {
        std::cout << "TORTOISE WINS!!! YAY!!!\n";
    }
    else
    {
        std::cout << "Hare wins. Yuch.\n";
    }

    return 0;
}
