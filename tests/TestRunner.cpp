
#include <iostream>
#include <iomanip>  
#include <cassert>
#include <cmath>
#include <string>
#include <vector>
#include "../core/Unit.h"
#include "../core/UnitCategory.h"
#include "../core/Converter.h"
#include "../data/UnitRegistry.h"
#include "../utils/Validation.h"

class TestRunner {
private:
    int totalTests = 0;
    int passedTests = 0;
    
    void runTest(const std::string& testName, bool condition) {
        totalTests++;
        if (condition) {
            passedTests++;
            std::cout << "✓ " << testName << " PASSED" << std::endl;
        } else {
            std::cout << "✗ " << testName << " FAILED" << std::endl;
        }
    }
    
    bool doubleEqual(double a, double b, double epsilon = 0.001) {
        return std::abs(a - b) < epsilon;
    }

public:
    void testUnitClass() {
        std::cout << "\n=== Testing Unit Class ===" << std::endl;
        
        // Test constructor and getters
        Unit meter("meter", 1.0);
        runTest("Unit constructor stores name correctly", meter.getName() == "meter");
        runTest("Unit constructor stores conversion factor correctly", 
                doubleEqual(meter.getConversionFactor(), 1.0));
        
        Unit kilometer("kilometer", 1000.0);
        runTest("Unit with different factor stores correctly", 
                doubleEqual(kilometer.getConversionFactor(), 1000.0));
        
        // Test toBase conversion
        runTest("toBase: 5 kilometers = 5000 meters", 
                doubleEqual(kilometer.toBase(5.0), 5000.0));
        runTest("toBase: 1 meter = 1 meter (base unit)", 
                doubleEqual(meter.toBase(1.0), 1.0));
        
        // Test fromBase conversion
        runTest("fromBase: 5000 meters = 5 kilometers", 
                doubleEqual(kilometer.fromBase(5000.0), 5.0));
        runTest("fromBase: 1 meter = 1 meter (base unit)", 
                doubleEqual(meter.fromBase(1.0), 1.0));
        
        // Test with centimeter (factor 0.01)
        Unit centimeter("centimeter", 0.01);
        runTest("toBase: 100 centimeters = 1 meter", 
                doubleEqual(centimeter.toBase(100.0), 1.0));
        runTest("fromBase: 1 meter = 100 centimeters", 
                doubleEqual(centimeter.fromBase(1.0), 100.0));
    }
    
    void testUnitCategoryClass() {
        std::cout << "\n=== Testing UnitCategory Class ===" << std::endl;
        
        UnitCategory distance("Distance", "meter");
        runTest("UnitCategory constructor stores name correctly", 
                distance.getName() == "Distance");
        
        // Test that base unit was created
        try {
            const Unit& baseUnit = distance.findUnit("meter");
            runTest("Base unit exists after construction", true);
            runTest("Base unit has correct name", baseUnit.getName() == "meter");
            runTest("Base unit has factor 1.0", 
                    doubleEqual(baseUnit.getConversionFactor(), 1.0));
        } catch (...) {
            runTest("Base unit exists after construction", false);
            runTest("Base unit has correct name", false);
            runTest("Base unit has factor 1.0", false);
        }
        
        // Test adding units
        distance.addUnit("kilometer", 1000.0);
        distance.addUnit("centimeter", 0.01);
        
        try {
            const Unit& km = distance.findUnit("kilometer");
            runTest("Added kilometer unit exists", true);
            runTest("Kilometer has correct factor", 
                    doubleEqual(km.getConversionFactor(), 1000.0));
        } catch (...) {
            runTest("Added kilometer unit exists", false);
            runTest("Kilometer has correct factor", false);
        }
        
        try {
            const Unit& cm = distance.findUnit("centimeter");
            runTest("Added centimeter unit exists", true);
            runTest("Centimeter has correct factor", 
                    doubleEqual(cm.getConversionFactor(), 0.01));
        } catch (...) {
            runTest("Added centimeter unit exists", false);
            runTest("Centimeter has correct factor", false);
        }
        
        // Test findUnit with non-existent unit
        bool foundNonExistent = false;
        try {
            distance.findUnit("nonexistent");
            foundNonExistent = true;
        } catch (...) {
            foundNonExistent = false;
        }
        runTest("findUnit throws exception for non-existent unit", !foundNonExistent);
        
        // Test getUnitNames
        std::vector<std::string> unitNames = distance.getUnitNames();
        runTest("getUnitNames returns correct count", unitNames.size() == 3);
        
        bool hasKm = false, hasCm = false, hasMeter = false;
        for (const auto& name : unitNames) {
            if (name == "kilometer") hasKm = true;
            if (name == "centimeter") hasCm = true;
            if (name == "meter") hasMeter = true;
        }
        runTest("getUnitNames includes all added units", hasKm && hasCm && hasMeter);
    }
    
    void testConverterClass() {
        std::cout << "\n=== Testing Converter Class ===" << std::endl;
        
        // Setup units for testing
        Unit meter("meter", 1.0);
        Unit kilometer("kilometer", 1000.0);
        Unit centimeter("centimeter", 0.01);
        
        // Test basic convert method
        runTest("Convert 5 km to meters", 
                doubleEqual(Converter::convert(5.0, kilometer, meter), 5000.0));
        runTest("Convert 5000 meters to km", 
                doubleEqual(Converter::convert(5000.0, meter, kilometer), 5.0));
        runTest("Convert 100 cm to meters", 
                doubleEqual(Converter::convert(100.0, centimeter, meter), 1.0));
        runTest("Convert 1 meter to cm", 
                doubleEqual(Converter::convert(1.0, meter, centimeter), 100.0));
        
        // Test same unit conversion
        runTest("Convert same unit returns same value", 
                doubleEqual(Converter::convert(42.0, meter, meter), 42.0));
        
        // Test temperature conversions
        runTest("Celsius to Fahrenheit: 0°C = 32°F", 
                doubleEqual(Converter::celsiusToFahrenheit(0.0), 32.0));
        runTest("Celsius to Fahrenheit: 100°C = 212°F", 
                doubleEqual(Converter::celsiusToFahrenheit(100.0), 212.0));
        runTest("Celsius to Fahrenheit: 25°C = 77°F", 
                doubleEqual(Converter::celsiusToFahrenheit(25.0), 77.0));
        
        runTest("Fahrenheit to Celsius: 32°F = 0°C", 
                doubleEqual(Converter::fahrenheitToCelsius(32.0), 0.0));
        runTest("Fahrenheit to Celsius: 212°F = 100°C", 
                doubleEqual(Converter::fahrenheitToCelsius(212.0), 100.0));
        runTest("Fahrenheit to Celsius: 77°F = 25°C", 
                doubleEqual(Converter::fahrenheitToCelsius(77.0), 25.0));
        
        runTest("Celsius to Kelvin: 0°C = 273.15K", 
                doubleEqual(Converter::celsiusToKelvin(0.0), 273.15));
        runTest("Celsius to Kelvin: 100°C = 373.15K", 
                doubleEqual(Converter::celsiusToKelvin(100.0), 373.15));
        runTest("Celsius to Kelvin: -273.15°C = 0K", 
                doubleEqual(Converter::celsiusToKelvin(-273.15), 0.0));
        
        runTest("Kelvin to Celsius: 273.15K = 0°C", 
                doubleEqual(Converter::kelvinToCelsius(273.15), 0.0));
        runTest("Kelvin to Celsius: 373.15K = 100°C", 
                doubleEqual(Converter::kelvinToCelsius(373.15), 100.0));
        runTest("Kelvin to Celsius: 0K = -273.15°C", 
                doubleEqual(Converter::kelvinToCelsius(0.0), -273.15));
        
        // Test complex temperature conversions
        UnitCategory temperature("Temperature", "celsius");
        temperature.addUnit("fahrenheit", 1.0);
        temperature.addUnit("kelvin", 1.0);
        
        runTest("Temperature conversion: 0°C to °F", 
                doubleEqual(Converter::convertTemperature(0.0, "celsius", "fahrenheit"), 32.0));
        runTest("Temperature conversion: 100°C to K", 
                doubleEqual(Converter::convertTemperature(100.0, "celsius", "kelvin"), 373.15));
        runTest("Temperature conversion: same unit", 
                doubleEqual(Converter::convertTemperature(25.0, "celsius", "celsius"), 25.0));
    }
    
    void testUnitRegistryClass() {
        std::cout << "\n=== Testing UnitRegistry Class ===" << std::endl;
        
        UnitRegistry registry;
        
        // Test that categories were initialized
        std::vector<std::string> categories = registry.getCategoryNames();
        runTest("Registry has categories after initialization", !categories.empty());
        
        bool hasDistance = false, hasTemperature = false, hasMass = false;
        for (const auto& cat : categories) {
            if (cat == "Distance") hasDistance = true;
            if (cat == "Temperature") hasTemperature = true;
            if (cat == "Mass") hasMass = true;
        }
        runTest("Registry has Distance category", hasDistance);
        runTest("Registry has Temperature category", hasTemperature);
        runTest("Registry has Mass category", hasMass);
        
        // Test findCategory
        try {
            const UnitCategory& distanceCategory = registry.findCategory("Distance");
            runTest("findCategory returns valid reference for existing category", true);
            runTest("Found category has correct name", 
                    distanceCategory.getName() == "Distance");
            
            // Test that default units exist
            try {
                distanceCategory.findUnit("meter");
                runTest("Distance category has meter unit", true);
            } catch (...) {
                runTest("Distance category has meter unit", false);
            }
            
            try {
                distanceCategory.findUnit("kilometer");
                runTest("Distance category has kilometer unit", true);
            } catch (...) {
                runTest("Distance category has kilometer unit", false);
            }
        } catch (...) {
            runTest("findCategory returns valid reference for existing category", false);
            runTest("Found category has correct name", false);
            runTest("Distance category has meter unit", false);
            runTest("Distance category has kilometer unit", false);
        }
        
        // Test findCategory with non-existent category
        bool foundNonExistent = false;
        try {
            registry.findCategory("NonExistent");
            foundNonExistent = true;
        } catch (...) {
            foundNonExistent = false;
        }
        runTest("findCategory throws exception for non-existent category", !foundNonExistent);
        
        // Test canAddUnitsToCategory
        runTest("Can add units to Distance category", 
                registry.canAddUnitsToCategory("Distance"));
        runTest("Can add units to Mass category", 
                registry.canAddUnitsToCategory("Mass"));
        runTest("Cannot add units to Temperature category", 
                !registry.canAddUnitsToCategory("Temperature"));
        
        // Test adding new unit
        bool addSuccess = registry.addUnitToCategory("Distance", "inch", "meter", 0.0254);
        runTest("Successfully added inch to Distance category", addSuccess);
        
        try {
            const UnitCategory& distanceCategory = registry.findCategory("Distance");
            try {
                const Unit& inch = distanceCategory.findUnit("inch");
                runTest("Added inch unit exists", true);
                runTest("Inch has correct conversion factor", 
                        doubleEqual(inch.getConversionFactor(), 0.0254));
            } catch (...) {
                runTest("Added inch unit exists", false);
                runTest("Inch has correct conversion factor", false);
            }
        } catch (...) {
            runTest("Added inch unit exists", false);
            runTest("Inch has correct conversion factor", false);
        }
        
        // Test adding unit to temperature (should fail)
        bool tempAddFail = registry.addUnitToCategory("Temperature", "rankine", "celsius", 1.0);
        runTest("Adding unit to Temperature category fails", !tempAddFail);
    }
    
    void testValidationClass() {
        std::cout << "\n=== Testing Validation Class ===" << std::endl;
        
        // Test isValidDouble
        runTest("Valid double: '123.45'", Validation::isValidDouble("123.45"));
        runTest("Valid double: '-67.89'", Validation::isValidDouble("-67.89"));
        runTest("Valid double: '+42'", Validation::isValidDouble("+42"));
        runTest("Valid double: '1.23e-4'", Validation::isValidDouble("1.23e-4"));
        runTest("Valid double: '5E+10'", Validation::isValidDouble("5E+10"));
        runTest("Valid double: '0'", Validation::isValidDouble("0"));
        runTest("Valid double: '.5'", Validation::isValidDouble(".5"));
        
        runTest("Invalid double: empty string", !Validation::isValidDouble(""));
        runTest("Invalid double: 'abc'", !Validation::isValidDouble("abc"));
        runTest("Invalid double: '12.34.56'", !Validation::isValidDouble("12.34.56"));
        runTest("Invalid double: 'e10'", !Validation::isValidDouble("e10"));
        
        // Test isValidInt
        runTest("Valid int: '123'", Validation::isValidInt("123"));
        runTest("Valid int: '-456'", Validation::isValidInt("-456"));
        runTest("Valid int: '+789'", Validation::isValidInt("+789"));
        runTest("Valid int: '0'", Validation::isValidInt("0"));
        
        runTest("Invalid int: empty string", !Validation::isValidInt(""));
        runTest("Invalid int: '12.34'", !Validation::isValidInt("12.34"));
        runTest("Invalid int: 'abc'", !Validation::isValidInt("abc"));
        runTest("Invalid int: '12e3'", !Validation::isValidInt("12e3"));
        
        // Test isValidUnitName
        runTest("Valid unit name: 'meter'", Validation::isValidUnitName("meter"));
        runTest("Valid unit name: 'foot_per_second'", Validation::isValidUnitName("foot_per_second"));
        runTest("Valid unit name: 'mile-per-hour'", Validation::isValidUnitName("mile-per-hour"));
        runTest("Valid unit name: 'kg2'", Validation::isValidUnitName("kg2"));
        
        runTest("Invalid unit name: empty string", !Validation::isValidUnitName(""));
        runTest("Invalid unit name: 'unit with spaces'", !Validation::isValidUnitName("unit with spaces"));
        runTest("Invalid unit name: 'unit@symbol'", !Validation::isValidUnitName("unit@symbol"));
        runTest("Invalid unit name: 'unit.dot'", !Validation::isValidUnitName("unit.dot"));
        
        // Test trim
        runTest("Trim: '  hello  '", Validation::trim("  hello  ") == "hello");
        runTest("Trim: 'no spaces'", Validation::trim("no spaces") == "no spaces");
        runTest("Trim: '\\t\\ntest\\r '", Validation::trim("\t\ntest\r ") == "test");
        runTest("Trim: empty string", Validation::trim("") == "");
        runTest("Trim: only spaces", Validation::trim("   ") == "");
        
        // Test toLowerCase
        runTest("toLowerCase: 'Hello World'", Validation::toLowerCase("Hello World") == "hello world");
        runTest("toLowerCase: 'UPPERCASE'", Validation::toLowerCase("UPPERCASE") == "uppercase");
        runTest("toLowerCase: 'MiXeD cAsE'", Validation::toLowerCase("MiXeD cAsE") == "mixed case");
        runTest("toLowerCase: 'already lowercase'", Validation::toLowerCase("already lowercase") == "already lowercase");
        runTest("toLowerCase: empty string", Validation::toLowerCase("") == "");
    }
    
    void runAllTests() {
        std::cout << "Starting Unit Converter Test Suite..." << std::endl;
        std::cout << "========================================" << std::endl;
        
        testUnitClass();
        testUnitCategoryClass();
        testConverterClass();
        testUnitRegistryClass();
        testValidationClass();
        
        std::cout << "\n========================================" << std::endl;
        std::cout << "Test Results: " << passedTests << "/" << totalTests << " tests passed" << std::endl;
        
        if (passedTests == totalTests) {
            std::cout << "🎉 All tests passed! Great job!" << std::endl;
        } else {
            std::cout << "❌ " << (totalTests - passedTests) << " tests failed. Keep working!" << std::endl;
        }
        
        double percentage = (double)passedTests / totalTests * 100;
        std::cout << "Success rate: " << std::fixed << std::setprecision(1) << percentage << "%" << std::endl;
    }
};

int main() {
    TestRunner testRunner;
    testRunner.runAllTests();
    return 0;
}
