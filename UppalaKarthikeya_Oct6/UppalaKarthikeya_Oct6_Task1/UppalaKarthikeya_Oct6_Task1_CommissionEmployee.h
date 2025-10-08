#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include <string>

class CommissionEmployee {
private:
    std::string firstName;
    std::string lastName;
    std::string ssn; // social security number
    double grossSales;
    double commissionRate;

public:
    CommissionEmployee(const std::string&, const std::string&, const std::string&, double, double);

    void setFirstName(const std::string&);
    std::string getFirstName() const;

    void setLastName(const std::string&);
    std::string getLastName() const;

    void setSSN(const std::string&);
    std::string getSSN() const;

    void setGrossSales(double);
    double getGrossSales() const;

    void setCommissionRate(double);
    double getCommissionRate() const;

    double earnings() const;
    std::string toString() const;
};

class BasePlusCommissionEmployee {
private:
    CommissionEmployee commissionEmp; // composition
    double baseSalary;

public:
    BasePlusCommissionEmployee(const std::string&, const std::string&, const std::string&, 
                               double, double, double);

    void setBaseSalary(double);
    double getBaseSalary() const;

    double earnings() const;
    std::string toString() const;
};

#endif
