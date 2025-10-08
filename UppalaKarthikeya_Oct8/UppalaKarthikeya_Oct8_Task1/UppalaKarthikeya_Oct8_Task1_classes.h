#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <vector>

// Enum class 
enum class SeverityLevel { Low, Medium, High, Critical };


class SensorReading {
private:
    std::string sensorName;
    double value;
    SeverityLevel severity;

public:
    SensorReading(const std::string& name, double val, SeverityLevel sev);
    void display() const;
    SeverityLevel getSeverity() const;
};


class DiagnosticReport {
private:
    std::vector<SensorReading> readings;

public:
    void addReading(const SensorReading& reading);
    void displayAll() const;
    int countSeverityOrHigher(SeverityLevel level) const;
};

#endif
