
#include "Unit.h"

Unit::Unit(const std::string& name, double conversionFactor) 
    : name(name), conversionFactor(conversionFactor) {
    // TODO: Initialize the Unit object with the given name and conversion factor
    // The conversion factor represents how many base units this unit represents
    // For example: if meter is base unit, then kilometer would have factor 1000.0
}

const std::string& Unit::getName() const {
    // TODO: Return the name of this unit
    // This should be a simple getter that returns the unit's name
    // Example: "meter", "kilometer", "celsius", etc.
}

double Unit::getConversionFactor() const {
    // TODO: Return the conversion factor of this unit relative to the base unit
    // This factor is used to convert between this unit and the base unit
    // Base unit always has factor 1.0, other units have their relative factors
}

double Unit::toBase(double value) const {
    // TODO: Convert a value from this unit to the base unit
    // Formula: value_in_base = value_in_this_unit * conversion_factor
    // Example: 5 kilometers * 1000 = 5000 meters
    return 0.0; // Remove this line when implementing
}

double Unit::fromBase(double value) const {
    // TODO: Convert a value from the base unit to this unit
    // Formula: value_in_this_unit = value_in_base / conversion_factor
    // Example: 5000 meters / 1000 = 5 kilometers
    return 0.0; // Remove this line when implementing
}
