
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
    return false; // Remove this line when implementing
}

bool Validation::isValidInt(const std::string& str) {
    // TODO: Validate if a string represents a valid integer
    // 1. Check if string is empty (return false)
    // 2. Use regex to match integer pattern:
    //    - Optional sign (+ or -)
    //    - One or more digits
    // 3. Use std::regex_match with pattern: R"(^[-+]?[0-9]+$)"
    // Examples: "123", "-45", "+67"
    return false; // Remove this line when implementing
}

bool Validation::isValidUnitName(const std::string& name) {
    // TODO: Validate if a string is a valid unit name
    // 1. Check if name is empty (return false)
    // 2. Check each character in the name:
    //    - Allow alphanumeric characters (std::isalnum)
    //    - Allow underscore (_) and hyphen (-)
    //    - Reject any other characters
    // 3. Return true only if all characters are valid
    // Examples: "meter", "foot_per_second", "mile-per-hour"
    return false; // Remove this line when implementing
}

std::string Validation::trim(const std::string& str) {
    // TODO: Remove whitespace from beginning and end of string
    // 1. Find the first non-whitespace character using find_first_not_of()
    //    - Search for characters not in " \t\n\r"
    // 2. If no non-whitespace found, return empty string
    // 3. Find the last non-whitespace character using find_last_not_of()
    // 4. Use substr() to extract the trimmed substring
    // Example: "  hello world  " becomes "hello world"
    return ""; // Remove this line when implementing
}

std::string Validation::toLowerCase(const std::string& str) {
    // TODO: Convert string to lowercase
    // 1. Create a copy of the input string
    // 2. Use std::transform with ::tolower to convert each character
    // 3. Return the transformed string
    // Example: "Hello World" becomes "hello world"
    // Hint: std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return ""; // Remove this line when implementing
}
