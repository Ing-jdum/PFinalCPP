
#ifndef CONVERTER_H
#define CONVERTER_H

#include "UnitCategory.h"

class Converter {
public:
    static double convert(double value, const Unit& fromUnit, const Unit& toUnit);
    static double convertInCategory(double value, const std::string& fromUnit, 
                                  const std::string& toUnit, const UnitCategory& category);
    
    // Special temperature conversion methods
    static double convertTemperature(double value, const std::string& fromUnit, const std::string& toUnit);
    static double celsiusToFahrenheit(double celsius);
    static double fahrenheitToCelsius(double fahrenheit);
    static double celsiusToKelvin(double celsius);
    static double kelvinToCelsius(double kelvin);
    static double fahrenheitToKelvin(double fahrenheit);
    static double kelvinToFahrenheit(double kelvin);
};

#endif
