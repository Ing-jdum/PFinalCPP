
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
    // TODO: Remove whitespace from beginning and end of string
    // 1. Find the first non-whitespace character using find_first_not_of()
    //    - Search for characters not in " \t\n\r"
    // 2. If no non-whitespace found, return empty string
    // 3. Find the last non-whitespace character using find_last_not_of()
    // 4. Use substr() to extract the trimmed substring
    // Example: "  hello world  " becomes "hello world"
    // Step 1: Find the first non-space character
    
    int start = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            start = i;
            break;
        }
    }

    // Step 2: Find the last non-space character
    int end = str.length() - 1;
    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            end = i;
            break;
        }
    }

    // Step 3: Create the trimmed string
    std::string result = "";
    for (int i = start; i <= end; i++) {
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

