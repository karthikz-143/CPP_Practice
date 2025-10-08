#include "UppalaKarthikeya_Oct8_Task1_classes.h"

// SensorReading Implementation 
SensorReading::SensorReading(const std::string& name, double val, SeverityLevel sev)
    : sensorName(name), value(val), severity(sev) {}

void SensorReading::display() const {
    std::cout << "Sensor: " << sensorName
              << " | Value: " << value
              << " | Severity: ";
    switch (severity) {
        case SeverityLevel::Low: std::cout << "Low"; break;
        case SeverityLevel::Medium: std::cout << "Medium"; break;
        case SeverityLevel::High: std::cout << "High"; break;
        case SeverityLevel::Critical: std::cout << "Critical"; break;
    }
    std::cout << std::endl;
}

SeverityLevel SensorReading::getSeverity() const {
    return severity;
}

// DiagnosticReport Implementation 
void DiagnosticReport::addReading(const SensorReading& reading) {
    readings.push_back(reading);
}

void DiagnosticReport::displayAll() const {
    std::cout << "\n--- Diagnostic Report ---\n";
    for (const auto& r : readings) {
        r.display();
    }
}

int DiagnosticReport::countSeverityOrHigher(SeverityLevel level) const {
    int count = 0;
    for (const auto& r : readings) {
        if (static_cast<int>(r.getSeverity()) >= static_cast<int>(level)) {
            count++;
        }
    }
    return count;
}
