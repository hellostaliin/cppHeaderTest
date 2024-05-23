#ifndef HOTEL_H
#define HOTEL_H

#include <unordered_map>
#include "Room.h"
#include "Customer.h"
#include "Booking.h"

class Hotel {
private:
    std::unordered_map<int, Room> rooms;
    std::unordered_map<int, Customer> customers;
    std::unordered_map<int, Booking> bookings;
    int nextRoomNumber = 1;
    int nextCustomerID = 1;
    int nextBookingID = 1;

public:
    void addRoom(const std::string& roomType, float pricePerNight);
    void addCustomer(const std::string& name, const std::string& contactInfo);
    void bookRoom(int customerID, int roomNumber, const std::string& checkInDate, const std::string& checkOutDate);
    void checkIn(int bookingID);
    void checkOut(int bookingID);
};

#endif // HOTEL_H
