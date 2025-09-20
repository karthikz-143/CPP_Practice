#include "CarUtils.h"
#include <algorithm>

double averagePrice(const Car* arr, size_t n) {
    if (n == 0) return 0.0;
    double sum = 0;
    for (size_t i = 0; i < n; ++i) sum += arr[i].getPrice();
    return sum / n;
}

bool compareByPriceAsc(const Car& a, const Car& b) { return a.getPrice() < b.getPrice(); }
bool compareByPriceDesc(const Car& a, const Car& b) { return a.getPrice() > b.getPrice(); }
bool areCarsEqual(const Car& a, const Car& b) { return a.getVIN() == b.getVIN(); }

const Car* maxPriceCar(const Car* arr, size_t n) {
    if (n == 0) return nullptr;
    const Car* maxCar = &arr[0];
    for (size_t i = 1; i < n; ++i)
        if (arr[i].getPrice() > maxCar->getPrice()) maxCar = &arr[i];
    return maxCar;
}

const Car* findCarByVIN(const Car* arr, size_t n, const std::string& vin) {
    for (size_t i = 0; i < n; ++i)
        if (arr[i].getVIN() == vin) return &arr[i];
    return nullptr;
}

size_t countCarsWithDamage(const Car* arr, size_t n, int code) {
    size_t count = 0;
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < arr[i].getDamageCount(); ++j)
            if (arr[i].getDamageCodes()[j] == code) ++count;
    return count;
}

void swapCars(Car& a, Car& b) { swap(a, b); }
