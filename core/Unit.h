
#ifndef UNIT_H
#define UNIT_H

#include <string>

class Unit {
private:
    std::string name;
    double conversionFactor; // Factor to convert to base unit

public:
    Unit(const std::string& name, double conversionFactor);
    
    const std::string& getName() const;
    double getConversionFactor() const;
    
    // Convert from this unit to base unit
    double toBase(double value) const;
    
    // Convert from base unit to this unit
    double fromBase(double value) const;
};

#endif
