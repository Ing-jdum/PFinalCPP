
#include "UnitCategory.h"
#include <stdexcept>
#include <algorithm>

UnitCategory::UnitCategory(const std::string& name, const std::string& baseUnitName) 
    : name(name) {
    // TODO: Initialize the category with a name and create the base unit
    // 1. Store the category name
    // 2. Create a base unit with the given name and conversion factor 1.0
    // 3. Add the base unit to the units vector
    // The base unit is the reference unit for all conversions in this category
}

const std::string& UnitCategory::getName() const {
    // TODO: Return the name of this category
    // Simple getter method that returns the category name
    // Example: "Distance", "Temperature", "Mass"
}

void UnitCategory::addUnit(const std::string& unitName, double conversionFactor) {
    // TODO: Add a new unit to this category
    // 1. Create a new Unit object with the given name and conversion factor
    // 2. Add it to the units vector using std::make_unique
    // 3. The conversion factor should be relative to the base unit
    // Note: Don't add duplicate units (check if unit already exists)
}

const Unit& UnitCategory::findUnit(const std::string& unitName) const {
    // TODO: Find and return a unit by name, throw exception if not found
    // 1. Use std::find_if to search through the units vector
    // 2. Compare unit names (case-sensitive)
    // 3. Return reference to the Unit if found, throw std::runtime_error if not found
    // Hint: Use a lambda function for the comparison
    throw std::runtime_error("Unit not found"); // Remove this line when implementing
}

std::vector<std::string> UnitCategory::getUnitNames() const {
    // TODO: Return a vector containing all unit names in this category
    // 1. Create an empty vector of strings
    // 2. Iterate through all units in the category
    // 3. Add each unit's name to the vector
    // 4. Return the completed vector
    std::vector<std::string> names; // You can keep this line
    return names; // Modify this when implementing
}
