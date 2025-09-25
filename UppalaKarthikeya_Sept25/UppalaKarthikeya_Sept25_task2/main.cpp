#include <iostream>
#include "DeckOfCards.h"

int main()
{
    DeckOfCards deck;     // Create deck
    deck.shuffle();       // Shuffle cards

    std::cout << "Shuffled deck of cards:\n" << std::endl;

    // Deal all 52 cards
    while (deck.moreCards())
    {
        Card c = deck.dealCard();
        std::cout << c.toString() << std::endl;
    }

    return 0;
}
