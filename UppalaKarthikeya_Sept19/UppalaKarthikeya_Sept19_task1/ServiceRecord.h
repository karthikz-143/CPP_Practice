#ifndef SERVICERECORD_H
#define SERVICERECORD_H

#include <string>

class ServiceRecord {
private:
    std::string date_;
    int mileage_;
    std::string description_;

public:
    ServiceRecord();
    ServiceRecord(const std::string& date, int mileage, const std::string& description);
    ServiceRecord(const ServiceRecord& other);
    ServiceRecord& operator=(const ServiceRecord& other);

    const std::string& getDate() const;
    int getMileage() const;
    const std::string& getDescription() const;

    void print() const;
};

#endif
