
#ifndef UNIT_REGISTRY_H
#define UNIT_REGISTRY_H

#include <vector>
#include <memory>
#include "../core/UnitCategory.h"

class UnitRegistry {
private:
    std::vector<std::unique_ptr<UnitCategory>> categories;
    
    void initializeDefaultCategories();

public:
    UnitRegistry();
    
    UnitCategory* findCategory(const std::string& categoryName) const;
    std::vector<std::string> getCategoryNames() const;
    
    bool addUnitToCategory(const std::string& categoryName, 
                          const std::string& unitName, 
                          const std::string& referenceUnit, 
                          double conversionFactor);
    
    bool canAddUnitsToCategory(const std::string& categoryName) const;
};

#endif
