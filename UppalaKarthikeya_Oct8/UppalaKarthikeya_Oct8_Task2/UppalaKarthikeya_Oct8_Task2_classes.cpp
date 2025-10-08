#include "UppalaKarthikeya_Oct8_Task2_classes.h"

//  Utility Function 
std::string severityToString(SeverityLevel level) {
    switch (level) {
        case SeverityLevel::Low: return "Low";
        case SeverityLevel::Medium: return "Medium";
        case SeverityLevel::High: return "High";
        case SeverityLevel::Critical: return "Critical";
    }
    return "Unknown";
}

// SensorReading Implementation
SensorReading::SensorReading(const std::string& name, double val, SeverityLevel sev)
    : sensorName(name), value(val), severity(sev) {}

void SensorReading::display() const {
    std::cout << "Sensor: " << sensorName
              << " | Value: " << value
              << " | Severity: " << severityToString(severity)
              << std::endl;
}

SeverityLevel SensorReading::getSeverity() const {
    return severity;
}

const std::string& SensorReading::getName() const {
    return sensorName;
}

// DiagnosticReport Implementation 
void DiagnosticReport::addReading(const SensorReading& reading) {
    readings.push_back(reading);
}

void DiagnosticReport::displayAll() const {
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

// Filter readings by exact severity
std::vector<SensorReading> DiagnosticReport::filterBySeverity(SeverityLevel level) const {
    std::vector<SensorReading> result;
    for (const auto& r : readings) {
        if (r.getSeverity() == level) {
            result.push_back(r);
        }
    }
    return result;
}

// Sort readings by severity descending
void DiagnosticReport::sortBySeverityDescending() {
    std::sort(readings.begin(), readings.end(),
        [](const SensorReading& a, const SensorReading& b) {
            return static_cast<int>(a.getSeverity()) > static_cast<int>(b.getSeverity());
        });
}

// Display severity distribution map
void DiagnosticReport::displaySeverityDistribution() const {
    std::map<SeverityLevel, int> distribution;
    for (const auto& r : readings) {
        distribution[r.getSeverity()]++;
    }
    for (const auto& pair : distribution) {
        std::cout << severityToString(pair.first) << ": " << pair.second << std::endl;
    }
}

// Find reading by sensor name
SensorReading* DiagnosticReport::findReadingByName(const std::string& name) {
    for (auto& r : readings) {
        if (r.getName() == name) {
            return &r;
        }
    }
    return nullptr;
}
