#include "RadarSignal.h"
#include <iostream>

int main() {
    
    const int numChannels = 4;
    float sampleSignals[] = {55.5f, 48.2f, 60.1f, 52.6f};

    std::cout << "--- Radar Signal Strength Management ---\n";

    // Create RadarSignal object on heap
    RadarSignal* radar = createRadarSignalHeap(numChannels, sampleSignals);

    // Show initial signals
    std::cout << "\nInitial Signals:\n";
    printRadarSignal(*radar);
    std::cout << "Average: " << radar->averageSignal() << "\n";

    // Boost by value (copy)
    std::cout << "\nApplying boostSignalByValue (copy):\n";
    boostSignalByValue(*radar); // original unchanged
    std::cout << "After boostSignalByValue (original stays same):\n";
    printRadarSignal(*radar);

    // Boost by reference (original)
    std::cout << "\nApplying boostSignalByReference (original):\n";
    boostSignalByReference(*radar); // original changed
    std::cout << "After boostSignalByReference (original changed):\n";
    printRadarSignal(*radar);

    // Clean up heap memory
    delete radar;
    radar = nullptr;

    std::cout << "\nProgram finished. Radar object deleted.\n";
    return 0;
}
