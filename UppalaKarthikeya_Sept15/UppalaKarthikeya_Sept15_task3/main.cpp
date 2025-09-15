#include "AerospaceComponent.h"
#include <iostream>

int main() {
    AerospaceComponent components[3] = {
        AerospaceComponent(101, 92.5, "GE Aviation", COMPONENT_TYPE_ENGINE, COMPONENT_STATUS_OPERATIONAL),
        AerospaceComponent(102, 45.0, "Honeywell", COMPONENT_TYPE_AVIONICS, COMPONENT_STATUS_FAILED),
        AerospaceComponent()
    };

    int choice;
    do {
        std::cout << "\n--- Aerospace Component Menu ---\n"
                  << "1. Display All Components\n"
                  << "2. Simulate Usage\n"
                  << "3. Boost Efficiency\n"
                  << "4. Maintenance Check\n"
                  << "5. Search by ID\n"
                  << "6. Exit\n"
                  << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            printFormattedComponentList(components, 3);
        }
        else if (choice == 2) {
            int index, hours;
            std::cout << "Enter component index (0-2): "; std::cin >> index;
            std::cout << "Enter usage hours: "; std::cin >> hours;
            components[index].simulateUsage(hours);
        }
        else if (choice == 3) {
            int index;
            std::cout << "Enter component index (0-2): "; std::cin >> index;
            components[index].boostEfficiency();
        }
        else if (choice == 4) {
            int index;
            std::cout << "Enter component index (0-2): "; std::cin >> index;
            components[index].performMaintenanceCheck();
        }
        else if (choice == 5) {
            int id;
            std::cout << "Enter component ID: "; std::cin >> id;
            int pos = searchComponentByIdentifier(components, 3, id);
            if (pos != -1) components[pos].displayDetails();
            else std::cout << "Component not found.\n";
        }

    } while (choice != 6);

    std::cout << "Exiting system.\n";
    return 0;
}
