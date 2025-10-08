#include "UppalaKarthikeya_Oct6_Task5_Package.h"
#include <iostream>

// Base Package 
Package::Package(const std::string& sName, const std::string& sAddress, const std::string& sCity,
                 const std::string& sState, const std::string& sZip,
                 const std::string& rName, const std::string& rAddress, const std::string& rCity,
                 const std::string& rState, const std::string& rZip,
                 double w, double cpo)
    : senderName(sName), senderAddress(sAddress), senderCity(sCity), senderState(sState), senderZip(sZip),
      recipientName(rName), recipientAddress(rAddress), recipientCity(rCity), recipientState(rState), recipientZip(rZip)
{
    weight = (w > 0 ? w : 0);
    costPerOunce = (cpo > 0 ? cpo : 0);
}

double Package::calculateCost() const {
    return weight * costPerOunce;
}

void Package::printInfo() const {
    std::cout << "Sender: " << senderName << ", " << senderCity << ", " << senderState << " (" << senderZip << ")\n";
    std::cout << "Recipient: " << recipientName << ", " << recipientCity << ", " << recipientState << " (" << recipientZip << ")\n";
}

// TwoDayPackage 
TwoDayPackage::TwoDayPackage(const std::string& sName, const std::string& sAddress, const std::string& sCity,
                             const std::string& sState, const std::string& sZip,
                             const std::string& rName, const std::string& rAddress, const std::string& rCity,
                             const std::string& rState, const std::string& rZip,
                             double w, double cpo, double fee)
    : Package(sName, sAddress, sCity, sState, sZip, rName, rAddress, rCity, rState, rZip, w, cpo)
{
    flatFee = (fee > 0 ? fee : 0);
}

double TwoDayPackage::calculateCost() const {
    return Package::calculateCost() + flatFee;
}

// OvernightPackage
OvernightPackage::OvernightPackage(const std::string& sName, const std::string& sAddress, const std::string& sCity,
                                   const std::string& sState, const std::string& sZip,
                                   const std::string& rName, const std::string& rAddress, const std::string& rCity,
                                   const std::string& rState, const std::string& rZip,
                                   double w, double cpo, double extraFee)
    : Package(sName, sAddress, sCity, sState, sZip, rName, rAddress, rCity, rState, rZip, w, cpo)
{
    extraFeePerOunce = (extraFee > 0 ? extraFee : 0);
}

double OvernightPackage::calculateCost() const {
    return weight * (costPerOunce + extraFeePerOunce);
}
