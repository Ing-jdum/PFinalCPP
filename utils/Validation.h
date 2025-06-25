
#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

class Validation {
public:
    static bool isValidDouble(const std::string& str);
    static bool isValidInt(const std::string& str);
    static bool isValidUnitName(const std::string& name);
    static std::string trim(const std::string& str);
    static std::string toLowerCase(const std::string& str);
};

#endif
