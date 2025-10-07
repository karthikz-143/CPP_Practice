#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package {
protected:
    std::string senderName, senderAddress, senderCity, senderState, senderZip;
    std::string recipientName, recipientAddress, recipientCity, recipientState, recipientZip;
    double weight;       // in ounces
    double costPerOunce; // cost per ounce

public:
    Package(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&,
            const std::string&, const std::string&, const std::string&, const std::string&, const std::string&,
            double, double);

    virtual double calculateCost() const;  // virtual for polymorphism
    void printInfo() const;
    virtual ~Package() {} // virtual destructor
};

class TwoDayPackage : public Package {
private:
    double flatFee;  // additional fixed fee
public:
    TwoDayPackage(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&,
                  const std::string&, const std::string&, const std::string&, const std::string&, const std::string&,
                  double, double, double);

    double calculateCost() const override;
};

class OvernightPackage : public Package {
private:
    double extraFeePerOunce; // additional per-ounce fee
public:
    OvernightPackage(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&,
                     const std::string&, const std::string&, const std::string&, const std::string&, const std::string&,
                     double, double, double);

    double calculateCost() const override;
};

#endif
