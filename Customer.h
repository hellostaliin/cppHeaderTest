#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>

class Customer {
private:
    int customerID;
    std::string name;
    std::string contactInfo;

public:
    Customer(int customerID, const std::string& name, const std::string& contactInfo);

    int getCustomerID() const;
    void displayDetails() const;
};

#endif // CUSTOMER_H
