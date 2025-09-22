#include "Invoice.h"

// Constructor
Invoice::Invoice(std::string number, std::string description, int qty, int price) {
    setPartNumber(number);
    setPartDescription(description);
    setQuantity(qty);
    setPricePerItem(price);
}

// Set and get for part number
void Invoice::setPartNumber(std::string number) {
    partNumber = number;
}
std::string Invoice::getPartNumber() const {
    return partNumber;
}

// Set and get for part description
void Invoice::setPartDescription(std::string description) {
    partDescription = description;
}
std::string Invoice::getPartDescription() const {
    return partDescription;
}

// Set and get for quantity
void Invoice::setQuantity(int qty) {
    if (qty > 0)
        quantity = qty;
    else
        quantity = 0;
}
int Invoice::getQuantity() const {
    return quantity;
}

// Set and get for price per item
void Invoice::setPricePerItem(int price) {
    if (price > 0)
        pricePerItem = price;
    else
        pricePerItem = 0;
}
int Invoice::getPricePerItem() const {
    return pricePerItem;
}

// Calculate invoice amount
int Invoice::getInvoiceAmount() const {
    return quantity * pricePerItem;
}
