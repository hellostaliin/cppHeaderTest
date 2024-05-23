#include "Customer.h"

Customer::Customer(int customerID, const std::string& name, const std::string& contactInfo)
    : customerID(customerID), name(name), contactInfo(contactInfo) {}

int Customer::getCustomerID() const { return customerID; }
void Customer::displayDetails() const {
    std::cout << "Customer ID: " << customerID << "\n"
              << "Name: " << name << "\n"
              << "Contact Info: " << contactInfo << std::endl;
}
