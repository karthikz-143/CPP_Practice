#include "UppalaKarthikeya_Oct8_Task2_classes.h"

int main() {
    DiagnosticReport report;

    report.addReading(SensorReading("EngineTemp", 105, SeverityLevel::High));
    report.addReading(SensorReading("OilPressure", 20, SeverityLevel::Medium));
    report.addReading(SensorReading("BrakeFluidLevel", 5, SeverityLevel::Critical));
    report.addReading(SensorReading("BatteryVoltage", 12.5, SeverityLevel::Low));
    report.addReading(SensorReading("CoolantLevel", 40, SeverityLevel::Medium));

    // Display all readings
    std::cout << "\n--- All Sensor Readings ---\n";
    report.displayAll();

    // Display severity distribution
    std::cout << "\n--- Severity Distribution ---\n";
    report.displaySeverityDistribution();

    // Sort and display readings by severity (descending)
    report.sortBySeverityDescending();
    std::cout << "\n--- Readings Sorted by Severity (Descending) ---\n";
    report.displayAll();

    // Filter and display only Critical readings
    std::vector<SensorReading> criticalReadings = report.filterBySeverity(SeverityLevel::Critical);
    std::cout << "\n--- Critical Readings ---\n";
    for (const auto& r : criticalReadings) {
        r.display();
    }

    // Lookup a specific sensor
    std::cout << "\n--- Lookup: BrakeFluidLevel ---\n";
    SensorReading* found = report.findReadingByName("BrakeFluidLevel");
    if (found) {
        found->display();
    } else {
        std::cout << "Sensor not found.\n";
    }

    return 0;
}
