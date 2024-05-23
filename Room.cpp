#include "Room.h"

Room::Room(int roomNumber, const std::string& roomType, bool isAvailable, float pricePerNight)
    : roomNumber(roomNumber), roomType(roomType), isAvailable(isAvailable), pricePerNight(pricePerNight) {}

int Room::getRoomNumber() const { return roomNumber; }
bool Room::getAvailability() const { return isAvailable; }
void Room::displayDetails() const {
    std::cout << "Room number: " << roomNumber << "\n"
              << "Room type: " << roomType << "\n"
              << "Availability: " << (isAvailable ? "available" : "not available") << "\n"
              << "Price per night: " << pricePerNight << std::endl;
}
void Room::markAsBooked() { isAvailable = false; }
void Room::markAsAvailable() { isAvailable = true; }
