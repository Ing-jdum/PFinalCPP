
#include "Converter.h"
#include <stdexcept>

double Converter::convert(double value, const Unit& fromUnit, const Unit& toUnit) {
    // TODO: Convert a value between two units in the same category
    // 1. Convert the value to the base unit using fromUnit.toBase(value)
    // 2. Convert from base unit to target unit using toUnit.fromBase(baseValue)
    // 3. Return the final converted value
    // This is the core conversion logic for linear unit conversions
    return 0.0; // Remove this line when implementing
}

double Converter::convertInCategory(double value, const std::string& fromUnit, 
                                  const std::string& toUnit, const UnitCategory& category) {
    // TODO: Convert between units by name within a specific category
    // 1. Check if this is a temperature category (special handling required)
    // 2. If temperature, call convertTemperature() instead
    // 3. Otherwise, find the fromUnit and toUnit in the category
    // 4. Call the convert() method with the found Unit references
    // 5. Handle cases where units are not found (exceptions will be thrown by findUnit)
    return 0.0; // Remove this line when implementing
}

double Converter::convertTemperature(double value, const std::string& fromUnit, const std::string& toUnit) {
    // TODO: Handle special temperature conversions (non-linear)
    // Temperature conversions don't use simple multiplication factors
    // 1. Check if fromUnit equals toUnit (return value unchanged)
    // 2. Convert fromUnit to Celsius first:
    //    - If fromUnit is "fahrenheit", use fahrenheitToCelsius()
    //    - If fromUnit is "kelvin", use kelvinToCelsius()
    //    - If fromUnit is "celsius", keep value as is
    // 3. Convert from Celsius to toUnit:
    //    - If toUnit is "celsius", return the celsius value
    //    - If toUnit is "fahrenheit", use celsiusToFahrenheit()
    //    - If toUnit is "kelvin", use celsiusToKelvin()
    // 4. Throw exception for unknown temperature units
    return 0.0; // Remove this line when implementing
}

double Converter::celsiusToFahrenheit(double celsius) {
    // TODO: Convert Celsius to Fahrenheit
    // Formula: F = (C × 9/5) + 32
    // Where C is temperature in Celsius, F is temperature in Fahrenheit
    return 0.0; // Remove this line when implementing
}

double Converter::fahrenheitToCelsius(double fahrenheit) {
    // TODO: Convert Fahrenheit to Celsius
    // Formula: C = (F - 32) × 5/9
    // Where F is temperature in Fahrenheit, C is temperature in Celsius
    return 0.0; // Remove this line when implementing
}

double Converter::celsiusToKelvin(double celsius) {
    // TODO: Convert Celsius to Kelvin
    // Formula: K = C + 273.15
    // Where C is temperature in Celsius, K is temperature in Kelvin
    return 0.0; // Remove this line when implementing
}

double Converter::kelvinToCelsius(double kelvin) {
    // TODO: Convert Kelvin to Celsius
    // Formula: C = K - 273.15
    // Where K is temperature in Kelvin, C is temperature in Celsius
    return 0.0; // Remove this line when implementing
}

double Converter::fahrenheitToKelvin(double fahrenheit) {
    // TODO: Convert Fahrenheit to Kelvin (bonus method)
    // Hint: Use the existing methods in combination
    // 1. Convert Fahrenheit to Celsius using fahrenheitToCelsius()
    // 2. Convert the result to Kelvin using celsiusToKelvin()
    return 0.0; // Remove this line when implementing
}

double Converter::kelvinToFahrenheit(double kelvin) {
    // TODO: Convert Kelvin to Fahrenheit (bonus method)
    // Hint: Use the existing methods in combination
    // 1. Convert Kelvin to Celsius using kelvinToCelsius()
    // 2. Convert the result to Fahrenheit using celsiusToFahrenheit()
    return 0.0; // Remove this line when implementing
}
