#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include <iostream>

class Booking {
private:
    int bookingID;
    int roomNumber;
    int customerID;
    std::string checkInDate;
    std::string checkOutDate;

public:
    Booking(int bookingID, int roomNumber, int customerID, const std::string& checkInDate, const std::string& checkOutDate);

    int getBookingID() const;
    int getRoomNumber() const;
    int getCustomerID() const;
    void displayDetails() const;
};

#endif // BOOKING_H
