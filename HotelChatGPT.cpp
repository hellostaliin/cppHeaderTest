#include <iostream>
#include <string>
#include <unordered_map>
#include <optional>

class Room {
private:
    int roomNumber;
    std::string roomType;
    bool isAvailable;
    float pricePerNight;

public:
    Room(int roomNumber, const std::string& roomType, bool isAvailable, float pricePerNight)
        : roomNumber(roomNumber), roomType(roomType), isAvailable(isAvailable), pricePerNight(pricePerNight) {}

    int getRoomNumber() const { return roomNumber; }
    bool getAvailability() const { return isAvailable; }
    void displayDetails() const {
        std::cout << "Room number: " << roomNumber << "\n"
                  << "Room type: " << roomType << "\n"
                  << "Availability: " << (isAvailable ? "available" : "not available") << "\n"
                  << "Price per night: " << pricePerNight << std::endl;
    }
    void markAsBooked() { isAvailable = false; }
    void markAsAvailable() { isAvailable = true; }
};

class Customer {
private:
    int customerID;
    std::string name;
    std::string contactInfo;

public:
    Customer(int customerID, const std::string& name, const std::string& contactInfo)
        : customerID(customerID), name(name), contactInfo(contactInfo) {}

    int getCustomerID() const { return customerID; }
    void displayDetails() const {
        std::cout << "Customer ID: " << customerID << "\n"
                  << "Name: " << name << "\n"
                  << "Contact Info: " << contactInfo << std::endl;
    }
};

class Booking {
private:
    int bookingID;
    int roomNumber;
    int customerID;
    std::string checkInDate;
    std::string checkOutDate;

public:
    Booking(int bookingID, int roomNumber, int customerID, const std::string& checkInDate, const std::string& checkOutDate)
        : bookingID(bookingID), roomNumber(roomNumber), customerID(customerID), checkInDate(checkInDate), checkOutDate(checkOutDate) {}

    int getBookingID() const { return bookingID; }
    int getRoomNumber() const { return roomNumber; }
    int getCustomerID() const { return customerID; }
    void displayDetails() const {
        std::cout << "Booking ID: " << bookingID << "\n"
                  << "Room number: " << roomNumber << "\n"
                  << "Customer ID: " << customerID << "\n"
                  << "Check-in date: " << checkInDate << "\n"
                  << "Check-out date: " << checkOutDate << std::endl;
    }
};

class Hotel {
private:
    std::unordered_map<int, Room> rooms;
    std::unordered_map<int, Customer> customers;
    std::unordered_map<int, Booking> bookings;
    int nextRoomNumber = 1;
    int nextCustomerID = 1;
    int nextBookingID = 1;

public:
    void addRoom(const std::string& roomType, float pricePerNight) {
        rooms.emplace(nextRoomNumber++, Room(nextRoomNumber, roomType, true, pricePerNight));
    }

    void addCustomer(const std::string& name, const std::string& contactInfo) {
        customers.emplace(nextCustomerID++, Customer(nextCustomerID, name, contactInfo));
    }

    void bookRoom(int customerID, int roomNumber, const std::string& checkInDate, const std::string& checkOutDate) {
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

    void checkIn(int bookingID) {
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

    void checkOut(int bookingID) {
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
};

int main() {
    Hotel h;
    h.addRoom("suite", 200);
    h.addCustomer("Taha", "taha@gmail.com");
    h.bookRoom(1, 1, "01/04/2024", "04/04/2024");
    h.checkIn(1);
    h.checkOut(1);
    h.addCustomer("fz", "fe@gmail.com");
    h.bookRoom(2, 1, "05/04/2024", "10/04/2024");
    
    return 0;
}
