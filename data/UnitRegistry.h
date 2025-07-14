#ifndef UNIT_REGISTRY_H
#define UNIT_REGISTRY_H

#include <vector>
#include <string>
#include "../core/UnitCategory.h"
#include "../utils/Validation.h"


class UnitRegistry {
private:
    std::vector<UnitCategory> categories;  
    
    void initializeDefaultCategories();

public:
    UnitRegistry();
    
    const UnitCategory& findCategory(const std::string& categoryName) const;
    std::vector<std::string> getCategoryNames() const;

    bool addUnitToCategory(const std::string& categoryName, 
                           const std::string& unitName, 
                           const std::string& referenceUnit, 
                           double conversionFactor);

    bool canAddUnitsToCategory(const std::string& categoryName) const;
};

#endif
