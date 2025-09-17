#include "ParcelAnalyzer.h"

string ParcelAnalyzer::classifyWeight(int grams) {
    if (grams < 500) return "Light";
    if (grams <= 2000) return "Medium";
    return "Heavy";
}

string ParcelAnalyzer::classifyWeight(float kilograms) {
    if (kilograms < 0.5f) return "Light";
    if (kilograms <= 2.0f) return "Medium";
    return "Heavy";
}

string ParcelAnalyzer::classifyWeight(double pounds) {
    if (pounds < 1.1) return "Light";
    if (pounds <= 4.4) return "Medium";
    return "Heavy";
}

void printClassification(const string& label) {
    cout << "Classification: " << label << "\n";
}
