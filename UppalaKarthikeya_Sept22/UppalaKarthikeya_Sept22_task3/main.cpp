#include <iostream>
#include "Invoice.h"

int main() {
    // Create Invoice object
    Invoice invoice1("1001", "Hammer", 5, 20);
    // invalid quantity 
    Invoice invoice2("1002", "Nails", -3, 10); 

    std::cout << "Invoice 1: "
              << invoice1.getPartNumber() << " - "
              << invoice1.getPartDescription()
              << "\nQuantity: " << invoice1.getQuantity()
              << ", Price per item: $" << invoice1.getPricePerItem()
              << "\nTotal: $" << invoice1.getInvoiceAmount()
              << "\n\n";

    std::cout << "Invoice 2: "
              << invoice2.getPartNumber() << " - "
              << invoice2.getPartDescription()
              << "\nQuantity: " << invoice2.getQuantity()
              << ", Price per item: $" << invoice2.getPricePerItem()
              << "\nTotal: $" << invoice2.getInvoiceAmount()
              << std::endl;

    return 0;
}
