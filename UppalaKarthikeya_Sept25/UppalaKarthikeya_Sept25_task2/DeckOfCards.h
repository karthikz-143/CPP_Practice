#ifndef DECK_OF_CARDS_H
#define DECK_OF_CARDS_H

#include <vector>
#include "Card.h"

class DeckOfCards
{
private:
    std::vector<Card> deck;   // Collection of 52 cards
    int currentCard;          // Index of the next card to deal

public:
    // Constructor:
    DeckOfCards();

    // Shuffle the deck
    void shuffle();

    // Deal the next card
    Card dealCard();

    // Check if there are more cards left
    bool moreCards() const;
};

#endif // DECK_OF_CARDS_H
