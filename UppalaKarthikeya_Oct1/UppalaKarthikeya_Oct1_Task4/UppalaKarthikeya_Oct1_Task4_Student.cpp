#include "UppalaKarthikeya_Oct1_Task4_Student.h"

// Base Student
Student::Student(const std::string& n, const std::string& id, const std::string& dept)
    : name(n), studentID(id), department(dept) {}

void Student::displayInfo() const
{
    std::cout << "Name: " << name << ", ID: " << studentID << ", Dept: " << department;
}

std::string Student::getLevel() const { return "Student"; }

// UndergraduateStudent
UndergraduateStudent::UndergraduateStudent(const std::string& n, const std::string& id,
                                           const std::string& dept, int y, int credits)
: Student(n,id,dept), year(y), creditsEarned(credits) {}

void UndergraduateStudent::displayInfo() const
{
    Student::displayInfo();
    std::cout << ", Year: " << year << ", Credits: " << creditsEarned;
}
std::string UndergraduateStudent::getLevel() const { return "Undergraduate"; }

// Freshman
Freshman::Freshman(const std::string& n, const std::string& id, const std::string& dept,
                   int y, int credits)
: UndergraduateStudent(n,id,dept,y,credits) {}

void Freshman::displayInfo() const { std::cout << "Freshman - "; UndergraduateStudent::displayInfo(); }
std::string Freshman::getLevel() const { return "Freshman"; }

// Sophomore
Sophomore::Sophomore(const std::string& n, const std::string& id, const std::string& dept,
                     int y, int credits)
: UndergraduateStudent(n,id,dept,y,credits) {}

void Sophomore::displayInfo() const { std::cout << "Sophomore - "; UndergraduateStudent::displayInfo(); }
std::string Sophomore::getLevel() const { return "Sophomore"; }

// Junior
Junior::Junior(const std::string& n, const std::string& id, const std::string& dept,
               int y, int credits)
: UndergraduateStudent(n,id,dept,y,credits) {}

void Junior::displayInfo() const { std::cout << "Junior - "; UndergraduateStudent::displayInfo(); }
std::string Junior::getLevel() const { return "Junior"; }

// Senior
Senior::Senior(const std::string& n, const std::string& id, const std::string& dept,
               int y, int credits)
: UndergraduateStudent(n,id,dept,y,credits) {}

void Senior::displayInfo() const { std::cout << "Senior - "; UndergraduateStudent::displayInfo(); }
std::string Senior::getLevel() const { return "Senior"; }

// HonorsSenior
HonorsSenior::HonorsSenior(const std::string& n, const std::string& id, const std::string& dept,
                           int y, int credits, const std::string& thesis)
: Senior(n,id,dept,y,credits), thesisTitle(thesis) {}

void HonorsSenior::displayInfo() const
{
    std::cout << "HonorsSenior - "; Senior::displayInfo();
    std::cout << ", Thesis: " << thesisTitle;
}
std::string HonorsSenior::getLevel() const { return "HonorsSenior"; }

// ExchangeSenior
ExchangeSenior::ExchangeSenior(const std::string& n, const std::string& id, const std::string& dept,
                               int y, int credits, const std::string& homeUni)
: Senior(n,id,dept,y,credits), homeUniversity(homeUni) {}

void ExchangeSenior::displayInfo() const
{
    std::cout << "ExchangeSenior - "; Senior::displayInfo();
    std::cout << ", Home University: " << homeUniversity;
}
std::string ExchangeSenior::getLevel() const { return "ExchangeSenior"; }

// GraduateStudent
GraduateStudent::GraduateStudent(const std::string& n, const std::string& id, const std::string& dept,
                                 const std::string& adv)
: Student(n,id,dept), advisor(adv) {}

void GraduateStudent::displayInfo() const
{
    std::cout << "GraduateStudent - "; Student::displayInfo();
    std::cout << ", Advisor: " << advisor;
}
std::string GraduateStudent::getLevel() const { return "GraduateStudent"; }

// MastersStudent
MastersStudent::MastersStudent(const std::string& n, const std::string& id, const std::string& dept,
                               const std::string& adv)
: GraduateStudent(n,id,dept,adv) {}

void MastersStudent::displayInfo() const
{
    std::cout << "MastersStudent - "; GraduateStudent::displayInfo();
}
std::string MastersStudent::getLevel() const { return "MastersStudent"; }

// ThesisMastersStudent
ThesisMastersStudent::ThesisMastersStudent(const std::string& n, const std::string& id, const std::string& dept,
                                           const std::string& adv, const std::string& thesis)
: MastersStudent(n,id,dept,adv), thesisTitle(thesis) {}

void ThesisMastersStudent::displayInfo() const
{
    std::cout << "ThesisMastersStudent - "; MastersStudent::displayInfo();
    std::cout << ", Thesis: " << thesisTitle;
}
std::string ThesisMastersStudent::getLevel() const { return "ThesisMastersStudent"; }

// NonThesisMastersStudent
NonThesisMastersStudent::NonThesisMastersStudent(const std::string& n, const std::string& id, const std::string& dept,
                                                 const std::string& adv, const std::string& project)
: MastersStudent(n,id,dept,adv), projectTitle(project) {}

void NonThesisMastersStudent::displayInfo() const
{
    std::cout << "NonThesisMastersStudent - "; MastersStudent::displayInfo();
    std::cout << ", Project: " << projectTitle;
}
std::string NonThesisMastersStudent::getLevel() const { return "NonThesisMastersStudent"; }

// DoctoralStudent
DoctoralStudent::DoctoralStudent(const std::string& n, const std::string& id, const std::string& dept,
                                 const std::string& adv, const std::string& dissertation, int years)
: GraduateStudent(n,id,dept,adv), dissertationTitle(dissertation), yearsInProgram(years) {}

void DoctoralStudent::displayInfo() const
{
    std::cout << "DoctoralStudent - "; GraduateStudent::displayInfo();
    std::cout << ", Dissertation: " << dissertationTitle << ", Years: " << yearsInProgram;
}
std::string DoctoralStudent::getLevel() const { return "DoctoralStudent"; }

// PhDCandidate
PhDCandidate::PhDCandidate(const std::string& n, const std::string& id, const std::string& dept,
                           const std::string& adv, const std::string& dissertation, int years)
: DoctoralStudent(n,id,dept,adv,dissertation,years) {}

void PhDCandidate::displayInfo() const
{
    std::cout << "PhDCandidate - "; DoctoralStudent::displayInfo();
}
std::string PhDCandidate::getLevel() const { return "PhDCandidate"; }

// PostDocFellow
PostDocFellow::PostDocFellow(const std::string& n, const std::string& id, const std::string& dept,
                             const std::string& adv, const std::string& grant)
: DoctoralStudent(n,id,dept,adv,"",0), researchGrant(grant) {}

void PostDocFellow::displayInfo() const
{
    std::cout << "PostDocFellow - "; GraduateStudent::displayInfo();
    std::cout << ", Research Grant: " << researchGrant;
}
std::string PostDocFellow::getLevel() const { return "PostDocFellow"; }
