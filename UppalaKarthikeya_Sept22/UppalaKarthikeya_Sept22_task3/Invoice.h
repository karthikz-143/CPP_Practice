// Invoice.h
// Invoice class definition

#ifndef INVOICE_H
#define INVOICE_H

#include <string>

class Invoice {
public:
    // Constructor
    Invoice(std::string number, std::string description, int qty, int price);

    // Set and get for part number
    void setPartNumber(std::string number);
    std::string getPartNumber() const;

    // Set and get for part description
    void setPartDescription(std::string description);
    std::string getPartDescription() const;

    // Set and get for quantity
    void setQuantity(int qty);
    int getQuantity() const;

    // Set and get for price per item
    void setPricePerItem(int price);
    int getPricePerItem() const;

    // Function to calculate invoice amount
    int getInvoiceAmount() const;

private:
    std::string partNumber;
    std::string partDescription;
    int quantity;
    int pricePerItem;
};

#endif
