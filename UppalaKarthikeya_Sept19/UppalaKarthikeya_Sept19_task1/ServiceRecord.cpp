#include "ServiceRecord.h"
#include <iostream>
#include <stdexcept>

ServiceRecord::ServiceRecord() : date_(""), mileage_(0), description_("") {}

ServiceRecord::ServiceRecord(const std::string& date, int mileage, const std::string& description)
    : date_(date), mileage_(mileage), description_(description) {
    if (mileage < 0) throw std::invalid_argument("Mileage cannot be negative");
}

ServiceRecord::ServiceRecord(const ServiceRecord& other)
    : date_(other.date_), mileage_(other.mileage_), description_(other.description_) {}

ServiceRecord& ServiceRecord::operator=(const ServiceRecord& other) {
    if (this != &other) {
        date_ = other.date_;
        mileage_ = other.mileage_;
        description_ = other.description_;
    }
    return *this;
}

const std::string& ServiceRecord::getDate() const { return date_; }
int ServiceRecord::getMileage() const { return mileage_; }
const std::string& ServiceRecord::getDescription() const { return description_; }

void ServiceRecord::print() const {
    std::cout << "Date: " << date_ << ", Mileage: " << mileage_
              << ", Description: " << description_ << "\n";
}
