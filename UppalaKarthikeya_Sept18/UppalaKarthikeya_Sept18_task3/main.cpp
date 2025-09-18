#include "SatelliteData.h"
#include <iostream>

int main() {

    float signals1[] = {78.5f, 80.2f, 79.0f};
    float signals2[] = {75.0f, 76.5f};

    SatelliteData* s1 = new SatelliteData(101, 3, signals1, 550.0f, OPERATIONAL);
    SatelliteData* s2 = new SatelliteData(102, 2, signals2, 600.0f, MAINTENANCE);
    s1->boostSignal(1.1f); 
    s2->boostSignal(1.2f, 76.0f); 
    if (compareAltitude(*s1, *s2)) {
        std::cout << "Satellite " << s1->getId() << " is at higher altitude.\n\n";
    } else {
        std::cout << "Satellite " << s2->getId() << " is at higher altitude.\n\n";
    }

    
    SatelliteData* clone = nullptr;
    cloneSatellite(*s1, clone);
    printSatelliteData(*s1);
    printSatelliteData(*s2);
    printSatelliteData(*clone);
    updateStatusIfWeak(*s2, 77.0f);
    std::cout << "After status update:\n";
    printSatelliteData(*s2);
    printActiveSatelliteCount();
    delete s1;
    delete s2;
    delete clone;
    printActiveSatelliteCount();
    return 0;
}
