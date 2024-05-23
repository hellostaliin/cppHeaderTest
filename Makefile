# Define the compiler
CXX = clang++

# Define compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra

# Define the target executable
TARGET = hotel

# Define the source files
SRCS = main.cpp Room.cpp Customer.cpp Booking.cpp Hotel.cpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
