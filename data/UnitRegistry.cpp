#include "UnitRegistry.h"
#include "../utils/Validation.h"
#include <algorithm>

UnitRegistry::UnitRegistry() {
    // TODO: Initialize the registry with default categories
    // Call initializeDefaultCategories() to set up the basic unit categoriesz
    // This constructor should prepare the registry with Distance, Temperature, and Mass categories
    initializeDefaultCategories();
}

void UnitRegistry::initializeDefaultCategories() {
    // TODO: Create and initialize the default unit categories
    // 
    // 1. Create Distance category with "meter" as base unit:
    //    - Add: kilometer (1000.0), centimeter (0.01), millimeter (0.001)
    //    - Add: inch (0.0254), foot (0.3048)
    //
    // 2. Create Temperature category with "celsius" as base unit:
    //    - Add: fahrenheit (1.0 - placeholder), kelvin (1.0 - placeholder)
    //    - Note: Temperature uses special conversion, factors are just placeholders
    //
    // 3. Create Mass category with "gram" as base unit:
    //    - Add: kilogram (1000.0), pound (453.592), ounce (28.3495), ton (1000000.0)
    //
    // Use std::make_unique to create categories and add them to the categories vector
    
    auto distance = std::make_unique<UnitCategory>("Distance", "meter");
    distance->addUnit("kilometer", 1000.0);
    distance->addUnit("inch", 0.0254);
    distance->addUnit("foot", 0.3048);
    categories.push_back(std::move(distance));
    
    auto temperature = std::make_unique<UnitCategory>("Temperature", "celsius");

    temperature->addUnit("fahrenheit", 1.0); 
    temperature->addUnit("kelvin", 1.0); 
    categories.push_back(std::move(temperature));
    
    // Mass category
    auto mass = std::make_unique<UnitCategory>("Mass", "gram");
    mass->addUnit("kilogram", 1000.0);
    mass->addUnit("pound", 453.592);
    mass->addUnit("ounce", 28.3495);
    mass->addUnit("ton", 1000000.0);
    categories.push_back(std::move(mass));
}

UnitCategory* UnitRegistry::findCategory(const std::string& categoryName) const {
    // TODO: Find a category by name and return pointer to it
    // 1. Use std::find_if to search through the categories vector
    // 2. Compare category names using a lambda function
    // 3. Return pointer to the category if found, nullptr otherwise
    // Hint: categories is a vector of unique_ptr, so use ->get() to get raw pointer
    auto it = std::find_if(categories.begin(), categories.end(),
        [&categoryName](const std::unique_ptr<UnitCategory>& category) {
            return category->getName() == categoryName;
        });
    
    return (it != categories.end()) ? it->get() : nullptr;
}

std::vector<std::string> UnitRegistry::getCategoryNames() const {
    // TODO: Return a vector of all category names
    // 1. Create an empty vector of strings
    // 2. Iterate through all categories
    // 3. Add each category's name to the vector
    // 4. Return the completed vector
    // This is used by the UI to show available categories to users
    std::vector<std::string> names;
    for (const auto& category : categories) {
        names.push_back(category->getName());
    }
    return names;
}

bool UnitRegistry::addUnitToCategory(const std::string& categoryName, 
                                    const std::string& unitName, 
                                    const std::string& referenceUnit, 
                                    double conversionFactor) {
    // TODO: Add a new unit to an existing category
    // 1. Check if the category allows adding new units using canAddUnitsToCategory()
    // 2. Find the target category using findCategory()
    // 3. Find the reference unit in that category
    // 4. Calculate the conversion factor relative to the base unit:
    //    newUnitFactor = referenceUnit->getConversionFactor() * conversionFactor
    // 5. Add the new unit to the category with the calculated factor
    // 6. Return true if successful, false if any step fails
    // Example: Adding "nanometer" with factor 1e-9 relative to "meter"
    if (canAddUnitsToCategory(categoryName)){
        UnitCategory* category = findCategory(categoryName);
        if(!category){
            return false;
        }
        Unit* refUnit = category->findUnit(referenceUnit);
        if(!refUnit){
            return false;
        }
        double newUnitFactor = refUnit->getConversionFactor() * conversionFactor;
        category->addUnit(unitName, newUnitFactor);
        return true;
    }    
    return false;
}

bool UnitRegistry::canAddUnitsToCategory(const std::string& categoryName) const {
    // TODO: Check if new units can be added to a specific category
    // Temperature category should return false because temperature conversions
    // require special formulas (not linear multiplication)
    // All other categories should return true
    // This prevents users from trying to add custom temperature units
     if(Validation::toLowerCase(categoryName) == "temperature"){
        return false;
     } 

     return true;
}