#include <iostream>
#include <vector>
#include "DeckOfCards.h"
#include "PokerHandEvaluator.h"

int main()
{
    DeckOfCards deck;
    deck.shuffle();

    // Deal two hands of 5 cards each
    std::vector<Card> hand1, hand2;
    for (int i = 0; i < 5; i++) hand1.push_back(deck.dealCard());
    for (int i = 0; i < 5; i++) hand2.push_back(deck.dealCard());

    std::cout << "Player 1 Hand:\n";
    for (auto& c : hand1) std::cout << c.toString() << std::endl;

    std::cout << "\nPlayer 2 Hand:\n";
    for (auto& c : hand2) std::cout << c.toString() << std::endl;

    // Evaluate hands
    int score1 = PokerHandEvaluator::evaluateHand(hand1);
    int score2 = PokerHandEvaluator::evaluateHand(hand2);

    std::cout << "\nPlayer 1 has: " << PokerHandEvaluator::handRankToString(score1) << std::endl;
    std::cout << "Player 2 has: " << PokerHandEvaluator::handRankToString(score2) << std::endl;

    if (score1 > score2)
        std::cout << "Winner: Player 1\n";
    else if (score2 > score1)
        std::cout << "Winner: Player 2\n";
    else
        std::cout << "It's a Tie!\n";

    return 0;
}
