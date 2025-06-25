
#include "InputHandler.h"
#include "../utils/Validation.h"
#include <iostream>
#include <limits>

std::string InputHandler::getString(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return Validation::trim(input);
}

double InputHandler::getDouble(const std::string& prompt) {
    std::string input;
    double value;
    
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        
        if (Validation::isValidDouble(input)) {
            try {
                value = std::stod(input);
                break;
            } catch (const std::exception&) {
                std::cout << "Invalid number. Please try again." << std::endl;
            }
        } else {
            std::cout << "Invalid number format. Please try again." << std::endl;
        }
    }
    
    return value;
}

int InputHandler::getInt(const std::string& prompt) {
    std::string input;
    int value;
    
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        
        if (Validation::isValidInt(input)) {
            try {
                value = std::stoi(input);
                break;
            } catch (const std::exception&) {
                std::cout << "Invalid number. Please try again." << std::endl;
            }
        } else {
            std::cout << "Invalid integer format. Please try again." << std::endl;
        }
    }
    
    return value;
}

bool InputHandler::getYesNo(const std::string& prompt) {
    std::string input;
    
    while (true) {
        std::cout << prompt << " (y/n): ";
        std::getline(std::cin, input);
        input = Validation::toLowerCase(Validation::trim(input));
        
        if (input == "y" || input == "yes") {
            return true;
        } else if (input == "n" || input == "no") {
            return false;
        } else {
            std::cout << "Please enter 'y' or 'n'." << std::endl;
        }
    }
}

void InputHandler::clearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void InputHandler::waitForEnter() {
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}
