#include "ParcelAnalyzer.h"

int main() {
    ParcelAnalyzer analyzer;

    printClassification(analyzer.classifyWeight(450));
    printClassification(analyzer.classifyWeight(1500));
    printClassification(analyzer.classifyWeight(2500));

    printClassification(analyzer.classifyWeight(0.3f));
    printClassification(analyzer.classifyWeight(1.5f));
    printClassification(analyzer.classifyWeight(3.0f));

    printClassification(analyzer.classifyWeight(0.9));
    printClassification(analyzer.classifyWeight(2.5));
    printClassification(analyzer.classifyWeight(5.0));

    return 0;
}
