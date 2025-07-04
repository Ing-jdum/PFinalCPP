
#ifndef UNIT_CATEGORY_H
#define UNIT_CATEGORY_H

#include <string>
#include <vector>
#include <memory>
#include "Unit.h"

class UnitCategory {
private:
    std::string name;
    std::string baseUnitName;
    std::vector<std::unique_ptr<Unit>> units;

public:
    UnitCategory(const std::string& name, const std::string& baseUnitName);
    
    const std::string& getName() const;
    const std::string& getBaseUnitName() const;
    
    void addUnit(const std::string& unitName, double conversionFactor);
    Unit* findUnit(const std::string& unitName) const;
    
    std::vector<std::string> getUnitNames() const;
    size_t getUnitCount() const;
};

#endif
