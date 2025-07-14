
#include "Validation.h"
#include <algorithm>
#include <cctype>
#include <regex>

bool Validation::isValidDouble(const std::string& str) {
    // TODO: Validate if a string represents a valid double number
    // 1. Check if string is empty (return false)
    // 2. Use regex to match valid double patterns:
    //    - Optional sign (+ or -)
    //    - Digits with optional decimal point
    //    - Optional scientific notation (e/E with optional sign and digits)
    // 3. Use std::regex_match with pattern: R"(^[-+]?([0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?))"
    // Examples: "123", "-45.67", "1.23e-4", "+0.5"
    if (str.empty()) {
        return false;
    }

    // 2. Define a regex for a valid integer: optional sign, then digits
    std::regex pattern(R"(^[-+]?([0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?))");

    // 3. Use regex_match to validate the whole string
    return std::regex_match(str, pattern);
}

bool Validation::isValidInt(const std::string& str) {
    // TODO: Validate if a string represents a valid integer
    // 1. Check if string is empty (return false)
    // 2. Use regex to match integer pattern:
    //    - Optional sign (+ or -)
    //    - One or more digits
    // 3. Use std::regex_match with pattern: R"(^[-+]?[0-9]+$)"
    // Examples: "123", "-45", "+67"
    if (str.empty()) {
        return false;
    }

    // 2. Define a regex for a valid integer: optional sign, then digits
    std::regex pattern(R"(^[-+]?[0-9]+$)");

    // 3. Use regex_match to validate the whole string
    return std::regex_match(str, pattern);
}

bool Validation::isValidUnitName(const std::string& name) {
    // 1. Check if name is empty (return false)
    if (name.empty()) {
        return false;
    }

    // 2. Check each character
    for (char ch : name) {
        if (!std::isalnum(ch) && ch != '_' && ch != '-') {
            return false;
        }
    }

    // 3. Return true only if all characters are valid
    return true;
}

std::string Validation::trim(const std::string& str) {
    const std::string WHITESPACE = " \t\n\r";

    // Step 1: Find the first non-whitespace character
    size_t start = 0;
    bool foundStart = false;
    for (size_t i = 0; i < str.length(); i++) {
        if (WHITESPACE.find(str[i]) == std::string::npos) {
            start = i;
            foundStart = true;
            break;
        }
    }

    // If no non-whitespace character was found, return empty string
    if (!foundStart) {
        return "";
    }

    // Step 2: Find the last non-whitespace character
    size_t end = str.length() - 1;
    for (size_t i = str.length(); i-- > 0;) {
        if (WHITESPACE.find(str[i]) == std::string::npos) {
            end = i;
            break;
        }
    }

    // Step 3: Build and return the trimmed string
    std::string result = "";
    for (size_t i = start; i <= end; i++) {
        result += str[i];
    }

    return result;
}



std::string Validation::toLowerCase(const std::string& str) {
    std::string result = str;

    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    return result;
}

