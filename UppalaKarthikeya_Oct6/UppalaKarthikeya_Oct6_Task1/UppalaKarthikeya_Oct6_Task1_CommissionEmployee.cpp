#include "UppalaKarthikeya_Oct6_Task1_CommissionEmployee.h"
#include <stdexcept>
#include <sstream>

// CommissionEmployee
CommissionEmployee::CommissionEmployee(const std::string& first, const std::string& last,
                                       const std::string& ssnValue, double sales, double rate)
    : firstName(first), lastName(last), ssn(ssnValue) {
    setGrossSales(sales);
    setCommissionRate(rate);
}

void CommissionEmployee::setFirstName(const std::string& first) { firstName = first; }
std::string CommissionEmployee::getFirstName() const { return firstName; }

void CommissionEmployee::setLastName(const std::string& last) { lastName = last; }
std::string CommissionEmployee::getLastName() const { return lastName; }

void CommissionEmployee::setSSN(const std::string& ssnValue) { ssn = ssnValue; }
std::string CommissionEmployee::getSSN() const { return ssn; }

void CommissionEmployee::setGrossSales(double sales) {
    if (sales < 0.0) throw std::invalid_argument("Gross sales must be >= 0.0");
    grossSales = sales;
}
double CommissionEmployee::getGrossSales() const { return grossSales; }

void CommissionEmployee::setCommissionRate(double rate) {
    if (rate <= 0.0 || rate >= 1.0) throw std::invalid_argument("Rate must be >0.0 and <1.0");
    commissionRate = rate;
}
double CommissionEmployee::getCommissionRate() const { return commissionRate; }

double CommissionEmployee::earnings() const { return commissionRate * grossSales; }

std::string CommissionEmployee::toString() const {
    std::ostringstream output;
    output << "Commission Employee: " << firstName << " " << lastName
           << "\nSSN: " << ssn
           << "\nGross Sales: " << grossSales
           << "\nCommission Rate: " << commissionRate;
    return output.str();
}

//  BasePlusCommissionEmployee 
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string& first, const std::string& last,
                                                       const std::string& ssnValue,
                                                       double sales, double rate, double base)
    : commissionEmp(first, last, ssnValue, sales, rate) {
    setBaseSalary(base);
}

void BasePlusCommissionEmployee::setBaseSalary(double base) {
    if (base < 0.0) throw std::invalid_argument("Base salary must be >= 0.0");
    baseSalary = base;
}
double BasePlusCommissionEmployee::getBaseSalary() const { return baseSalary; }

double BasePlusCommissionEmployee::earnings() const {
    return baseSalary + commissionEmp.earnings();
}

std::string BasePlusCommissionEmployee::toString() const {
    std::ostringstream output;
    output << commissionEmp.toString()
           << "\nBase Salary: " << baseSalary;
    return output.str();
}
