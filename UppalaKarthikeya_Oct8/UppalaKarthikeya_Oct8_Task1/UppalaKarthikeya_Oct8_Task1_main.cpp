#include "UppalaKarthikeya_Oct8_Task1_classes.h"

int main() {
    DiagnosticReport report;

    // sample data
    report.addReading(SensorReading("EngineTemp", 105, SeverityLevel::High));
    report.addReading(SensorReading("OilPressure", 20, SeverityLevel::Medium));
    report.addReading(SensorReading("BrakeFluidLevel", 5, SeverityLevel::Critical));
    report.addReading(SensorReading("BatteryVoltage", 12.5, SeverityLevel::Low));

    // Display all readings
    report.displayAll();

    // Count and display readings with severity >= High
    int criticalCount = report.countSeverityOrHigher(SeverityLevel::High);
    std::cout << "\nNumber of High or Critical severity readings: " 
              << criticalCount << std::endl;

    return 0;
}
