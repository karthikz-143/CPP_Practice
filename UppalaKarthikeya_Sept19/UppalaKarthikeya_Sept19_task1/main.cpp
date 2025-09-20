#include "Car.h"
#include "CarUtils.h"
#include "ServiceRecord.h"
#include <iostream>

int main() {
    std::cout << "Initial Cars: " << Car::getTotalCars() << "\n";

    Car cDefault;
    cDefault.printInfo();

    Car cHonda("1HGCM", "Honda", "Accord", 19999.99);
    cHonda.addDamageCode(101);
    cHonda.addDamageCode(205);
    cHonda.addService(ServiceRecord("2022-03-15", 15000, "Oil change"));
    cHonda.addService(ServiceRecord("2023-01-10", 25000, "Brake pads replacement"));
    cHonda.printInfo();

    Car cCopy(cHonda);
    cCopy.printInfo();

    Car cAssign;
    cAssign = cHonda;
    cAssign.printInfo();

    const size_t N = 3;
    Car* garage = new Car[N];
    garage[0] = Car("JH4KA", "Acura", "TLX", 27999.49);
    garage[1] = Car("5YJ3E", "Tesla", "Model 3", 39999.00);
    garage[2] = Car("WBA4", "BMW", "3 Series", 34999.99);

    for (size_t i = 0; i < N; ++i) garage[i].printInfo();

    std::cout << "Average Price: " << averagePrice(garage, N) << "\n";
    const Car* expensive = maxPriceCar(garage, N);
    if (expensive) std::cout << "Most Expensive: " << expensive->getVIN() << "\n";

    const Car* found = findCarByVIN(garage, N, "5YJ3E");
    if (found) std::cout << "Found Tesla Price: " << found->getPrice() << "\n";

    std::cout << "Cars with damage code 101: " << countCarsWithDamage(garage, N, 101) << "\n";

    delete[] garage;
    std::cout << "Final Cars: " << Car::getTotalCars() << "\n";
    return 0;
}
