#include "Hotel.h"

void Hotel::addRoom(const std::string& roomType, float pricePerNight) {
    rooms.emplace(nextRoomNumber, Room(nextRoomNumber, roomType, true, pricePerNight));
    nextRoomNumber++;
}

void Hotel::addCustomer(const std::string& name, const std::string& contactInfo) {
    customers.emplace(nextCustomerID, Customer(nextCustomerID, name, contactInfo));
    nextCustomerID++;
}

void Hotel::bookRoom(int customerID, int roomNumber, const std::string& checkInDate, const std::string& checkOutDate) {
    auto roomIt = rooms.find(roomNumber);
    auto customerIt = customers.find(customerID);

    if (roomIt == rooms.end()) {
        std::cout << "Room not found." << std::endl;
        return;
    }

    if (customerIt == customers.end()) {
        std::cout << "Customer not found." << std::endl;
        return;
    }

    if (!roomIt->second.getAvailability()) {
        std::cout << "Room is not available." << std::endl;
        return;
    }

    rooms[roomNumber].markAsBooked();
    bookings.emplace(nextBookingID, Booking(nextBookingID, roomNumber, customerID, checkInDate, checkOutDate));
    customers[customerID].displayDetails();
    std::cout << "Booking successful!" << std::endl;

    nextBookingID++;
}

void Hotel::checkIn(int bookingID) {
    auto bookingIt = bookings.find(bookingID);
    if (bookingIt != bookings.end()) {
        int roomNumber = bookingIt->second.getRoomNumber();
        auto roomIt = rooms.find(roomNumber);
        if (roomIt != rooms.end() && !roomIt->second.getAvailability()) {
            std::cout << "Welcome! You have checked in successfully." << std::endl;
            return;
        }
    }
    std::cout << "Check-in failed. Booking not found or room is not available." << std::endl;
}

void Hotel::checkOut(int bookingID) {
    auto bookingIt = bookings.find(bookingID);
    if (bookingIt != bookings.end()) {
        int roomNumber = bookingIt->second.getRoomNumber();
        auto roomIt = rooms.find(roomNumber);
        if (roomIt != rooms.end()) {
            roomIt->second.markAsAvailable();
            std::cout << "Check-out successful! Room " << roomNumber << " is now available." << std::endl;
            return;
        }
    }
    std::cout << "Check-out failed. Booking not found." << std::endl;
}
