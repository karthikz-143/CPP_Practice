#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

enum class SeverityLevel { Low, Medium, High, Critical };
std::string severityToString(SeverityLevel level);


class SensorReading {
private:
    std::string sensorName;
    double value;
    SeverityLevel severity;

public:
    SensorReading(const std::string& name, double val, SeverityLevel sev);
    void display() const;
    SeverityLevel getSeverity() const;
    const std::string& getName() const;
};


class DiagnosticReport {
private:
    std::vector<SensorReading> readings;

public:
    void addReading(const SensorReading& reading);
    void displayAll() const;
    int countSeverityOrHigher(SeverityLevel level) const;

    // Task 2 Extensions
    std::vector<SensorReading> filterBySeverity(SeverityLevel level) const;
    void sortBySeverityDescending();
    void displaySeverityDistribution() const;
    SensorReading* findReadingByName(const std::string& name);
};

#endif
