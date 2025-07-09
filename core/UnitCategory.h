#ifndef UNIT_CATEGORY_H
#define UNIT_CATEGORY_H

#include <string>
#include <vector>
#include "Unit.h"

class UnitCategory {
private:
    std::string name;
    std::string baseUnitName;
    std::vector<Unit> units;  
    
public:
    UnitCategory(const std::string& name, const std::string& baseUnitName);
    
    const std::string& getName() const;
    
    void addUnit(const std::string& unitName, double conversionFactor);
    const Unit& findUnit(const std::string& unitName) const;

    std::vector<std::string> getUnitNames() const;
};

#endif
