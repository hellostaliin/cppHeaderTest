#include "Booking.h"

Booking::Booking(int bookingID, int roomNumber, int customerID, const std::string& checkInDate, const std::string& checkOutDate)
    : bookingID(bookingID), roomNumber(roomNumber), customerID(customerID), checkInDate(checkInDate), checkOutDate(checkOutDate) {}

int Booking::getBookingID() const { return bookingID; }
int Booking::getRoomNumber() const { return roomNumber; }
int Booking::getCustomerID() const { return customerID; }
void Booking::displayDetails() const {
    std::cout << "Booking ID: " << bookingID << "\n"
              << "Room number: " << roomNumber << "\n"
              << "Customer ID: " << customerID << "\n"
              << "Check-in date: " << checkInDate << "\n"
              << "Check-out date: " << checkOutDate << std::endl;
}
