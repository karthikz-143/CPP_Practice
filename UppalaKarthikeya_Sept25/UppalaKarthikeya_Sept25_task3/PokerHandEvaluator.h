#ifndef POKER_HAND_EVALUATOR_H
#define POKER_HAND_EVALUATOR_H

#include <vector>
#include "Card.h"

class PokerHandEvaluator
{
public:
    
    static int evaluateHand(const std::vector<Card>& hand);
    static std::string handRankToString(int rank);

private:
    static bool isFlush(const std::vector<Card>& hand);
    static bool isStraight(const std::vector<Card>& hand);
};

#endif // POKER_HAND_EVALUATOR_H
