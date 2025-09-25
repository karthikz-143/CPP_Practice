#include "DeckOfCards.h"
#include <cstdlib>   // For rand()
#include <ctime>     // For time()

// Constructor:
DeckOfCards::DeckOfCards()
{
    currentCard = 0;

    for (int suit = 0; suit < 4; ++suit)
    {
        for (int face = 0; face < 13; ++face)
        {
            deck.push_back(Card(face, suit));
        }
    }
}

// Shuffle the deck 
void DeckOfCards::shuffle()
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    for (std::size_t i = 0; i < deck.size(); ++i)
    {
        int j = std::rand() % deck.size(); // Pick a random index
        std::swap(deck[i], deck[j]);       // Swap current card with random one
    }

    currentCard = 0; 
}

// Deal next card
Card DeckOfCards::dealCard()
{
    if (moreCards())
    {
        return deck[currentCard++];
    }
    else
    {
        // Return a dummy card if no cards left
        return Card(0, 0);
    }
}

// Check if more cards are available
bool DeckOfCards::moreCards() const
{
    return currentCard < static_cast<int>(deck.size());
}
