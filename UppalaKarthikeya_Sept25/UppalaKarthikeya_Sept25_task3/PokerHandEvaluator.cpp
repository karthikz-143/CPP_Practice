#include "PokerHandEvaluator.h"
#include <map>
#include <algorithm>

// Evaluate hand and return ranking score
int PokerHandEvaluator::evaluateHand(const std::vector<Card>& hand)
{
    // Count faces
    std::map<int, int> faceCount;
    for (auto& card : hand)
        faceCount[card.getFace()]++;

    bool flush = isFlush(hand);
    bool straight = isStraight(hand);

    // Four of a kind
    if (std::any_of(faceCount.begin(), faceCount.end(),
        [](auto& f){ return f.second == 4; }))
        return 7;

    // Full House
    bool three = false, pair = false;
    for (auto& f : faceCount)
    {
        if (f.second == 3) three = true;
        if (f.second == 2) pair = true;
    }
    if (three && pair) return 6;

    // Flush
    if (flush) return 5;

    // Straight
    if (straight) return 4;

    // Three of a kind
    if (three) return 3;

    // Two pair
    int pairs = 0;
    for (auto& f : faceCount)
        if (f.second == 2) pairs++;
    if (pairs == 2) return 2;

    // One pair
    if (pairs == 1) return 1;

    // High card
    return 0;
}

std::string PokerHandEvaluator::handRankToString(int rank)
{
    switch (rank)
    {
        case 7: return "Four of a Kind";
        case 6: return "Full House";
        case 5: return "Flush";
        case 4: return "Straight";
        case 3: return "Three of a Kind";
        case 2: return "Two Pair";
        case 1: return "One Pair";
        default: return "High Card";
    }
}

bool PokerHandEvaluator::isFlush(const std::vector<Card>& hand)
{
    int suit = hand[0].getSuit();
    for (auto& card : hand)
        if (card.getSuit() != suit) return false;
    return true;
}

bool PokerHandEvaluator::isStraight(const std::vector<Card>& hand)
{
    std::vector<int> faces;
    for (auto& card : hand) faces.push_back(card.getFace());
    std::sort(faces.begin(), faces.end());

    for (int i = 1; i < 5; i++)
        if (faces[i] != faces[0] + i) return false;
    return true;
}
