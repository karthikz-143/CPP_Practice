#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
private:
    int face;   // 0-12 (Ace to King)
    int suit;   // 0-3 (Hearts, Diamonds, Clubs, Spades)

public:
    // Static arrays of faces and suits
    static const std::string faces[13];
    static const std::string suits[4];

    // Constructor
    Card(int cardFace, int cardSuit);
    int getFace() const { return face; }
    int getSuit() const { return suit; }


    std::string toString() const;
};

#endif // CARD_H
