#include "UppalaKarthikeya_Oct1_Task4_Student.h"
#include <iostream>

int main()
{
    Student* students[10];

    students[0] = new Freshman("Amit","UG101","Computer Science",1,15);
    students[1] = new HonorsSenior("Neha","UG401","Physics",4,120,"Quantum Entanglement Thesis");
    students[2] = new ExchangeSenior("Luca","UG402","Mechanical",4,110,"Politecnico di Milano");
    students[3] = new ThesisMastersStudent("Priya","GR201","Electrical","Dr. Rao","Smart Grid Optimization");
    students[4] = new NonThesisMastersStudent("Raj","GR202","Civil","Dr. Mehta","Bridge Load Simulation");
    students[5] = new PhDCandidate("Sneha","GR301","Biotech","Dr. Kapoor","Gene Editing Ethics",3);
    students[6] = new PostDocFellow("Dr. Tanmay","GR401","AI Research","Dr. Bose","DARPA Grant");

    for(int i=0; i<7; i++) {
        students[i]->displayInfo();
        std::cout << "\nLevel: " << students[i]->getLevel() << "\n\n";
    }

    for(int i=0; i<7; i++) delete students[i];

    return 0;
}
