#ifndef PARCELANALYZER_H
#define PARCELANALYZER_H

#include <iostream>
#include <string>
using namespace std;

class ParcelAnalyzer {
public:
    string classifyWeight(int grams);
    string classifyWeight(float kilograms);
    string classifyWeight(double pounds);
};

void printClassification(const string& label);

#endif
