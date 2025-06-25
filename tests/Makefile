
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
TARGET = test_runner
SOURCES = TestRunner.cpp ../core/Unit.cpp ../core/UnitCategory.cpp ../core/Converter.cpp ../data/UnitRegistry.cpp ../utils/Validation.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
