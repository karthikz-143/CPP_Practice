#include "FleetVehicle.h"
#include <vector>
#include <iostream>
#include <string>

int main() {
    std::vector<FleetVehicle> fleet(3);
    fleet[0] = FleetVehicle(101, 45, 120, 'A', true, "Raj");
    fleet[1] = FleetVehicle(102, 8, 300, 'A', true, "Priya");
    // fleet[2] is default: ID 0, "Unassigned"

    int choice, index;
    do {
        std::cout << "\n--- Fleet Menu ---\n";
        std::cout << "1. Add/Update Vehicle\n";
        std::cout << "2. Assign Driver\n";
        std::cout << "3. Refuel Vehicle\n";
        std::cout << "4. Update Status\n";
        std::cout << "5. Show Vehicle Info\n";
        std::cout << "6. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 5) {
            std::cout << "Select vehicle index (0-2): ";
            std::cin >> index;
        }

        switch (choice) {
            case 1: {
                int id; float fuel; double dist; char stat; bool avail; std::string driver;
                std::cout << "Enter ID, Fuel, Distance, Status(A/I), Available(1/0), Driver:\n";
                std::cin >> id >> fuel >> dist >> stat >> avail >> std::ws;
                std::getline(std::cin, driver);
                fleet[index] = FleetVehicle(id, fuel, dist, stat, avail, driver);
                break;
            }
            case 2: {
                std::string driver;
                std::cout << "Enter new driver: ";
                std::cin >> std::ws;
                std::getline(std::cin, driver);
                assignDriver(fleet[index], driver);
                break;
            }
            case 3: {
                float fuel;
                std::cout << "Enter fuel to add: ";
                std::cin >> fuel;
                refuelVehicle(fleet[index], fuel);
                break;
            }
            case 4:
                fleet[index].updateStatus();
                std::cout << "Status updated.\n";
                break;
            case 5:
                fleet[index].displayInfo();
                break;
            case 6:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
