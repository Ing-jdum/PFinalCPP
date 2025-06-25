// Modified code to restrict adding temperature units and ensure correct temperature calculations.
#include "Menu.h"
#include "InputHandler.h"
#include "../core/Converter.h"
#include "../utils/Validation.h"
#include <iostream>
#include <iomanip>

Menu::Menu(UnitRegistry& registry) : registry(registry) {}

void Menu::run() {
    bool running = true;

    while (running) {
        showMainMenu();
        int choice = InputHandler::getInt("Enter your choice: ");

        switch (choice) {
            case 1:
                handleUserMode();
                break;
            case 2:
                handleAdminMode();
                break;
            case 3:
                running = false;
                std::cout << "Thank you for using Unit Converter!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        if (running) {
            InputHandler::waitForEnter();
        }
    }
}

void Menu::showMainMenu() {
    std::cout << "\n=== UNIT CONVERTER ===" << std::endl;
    std::cout << "1. User Mode (Convert units)" << std::endl;
    std::cout << "2. Admin Mode (Add new units)" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "========================" << std::endl;
}

void Menu::handleUserMode() {
    std::cout << "\n--- USER MODE ---" << std::endl;
    performConversion();
}

void Menu::handleAdminMode() {
    std::cout << "\n--- ADMIN MODE ---" << std::endl;
    addNewUnit();
}

void Menu::performConversion() {
    // Show available categories
    std::cout << "\nAvailable categories:" << std::endl;
    auto categories = registry.getCategoryNames();
    for (size_t i = 0; i < categories.size(); ++i) {
        std::cout << (i + 1) << ". " << categories[i] << std::endl;
    }

    int categoryChoice = InputHandler::getInt("Select category: ");
    if (categoryChoice < 1 || categoryChoice > static_cast<int>(categories.size())) {
        std::cout << "Invalid category selection." << std::endl;
        return;
    }

    std::string selectedCategory = categories[categoryChoice - 1];
    UnitCategory* category = registry.findCategory(selectedCategory);

    if (!category) {
        std::cout << "Category not found." << std::endl;
        return;
    }

    // Show available units in category
    std::cout << "\nAvailable units in " << selectedCategory << ":" << std::endl;
    auto units = category->getUnitNames();
    for (const auto& unit : units) {
        std::cout << "- " << unit << std::endl;
    }

    std::string fromUnit = InputHandler::getString("From unit: ");
    std::string toUnit = InputHandler::getString("To unit: ");
    double value = InputHandler::getDouble("Value to convert: ");

    // Special handling for temperature
    if (selectedCategory == "Temperature") {
        std::cout << "Note: Temperature conversion requires special handling." << std::endl;
        std::cout << "This is a simplified implementation." << std::endl;
    }

    try {
        double result = Converter::convertInCategory(value, fromUnit, toUnit, *category);
        std::cout << std::fixed << std::setprecision(6);
        std::cout << value << " " << fromUnit << " = " << result << " " << toUnit << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Conversion failed: " << e.what() << std::endl;
    }
}

void Menu::addNewUnit() {
    // Show available categories
    std::cout << "\nAvailable categories:" << std::endl;
    auto categories = registry.getCategoryNames();
    for (size_t i = 0; i < categories.size(); ++i) {
        std::cout << (i + 1) << ". " << categories[i] << std::endl;
    }

    int categoryChoice = InputHandler::getInt("Select category to add unit to: ");
    if (categoryChoice < 1 || categoryChoice > static_cast<int>(categories.size())) {
        std::cout << "Invalid category selection." << std::endl;
        return;
    }

    std::string selectedCategory = categories[categoryChoice - 1];
    UnitCategory* category = registry.findCategory(selectedCategory);

    if (!category) {
        std::cout << "Category not found." << std::endl;
        return;
    }

    // Check if this category allows adding new units
    if (!registry.canAddUnitsToCategory(selectedCategory)) {
        std::cout << "Cannot add new units to " << selectedCategory << " category." << std::endl;
        std::cout << "Temperature conversions require special formulas and cannot be extended." << std::endl;
        return;
    }

    // Show existing units
    std::cout << "\nExisting units in " << selectedCategory << ":" << std::endl;
    auto units = category->getUnitNames();
    for (const auto& unit : units) {
        std::cout << "- " << unit << std::endl;
    }

    std::string newUnitName = InputHandler::getString("New unit name: ");
    if (!Validation::isValidUnitName(newUnitName)) {
        std::cout << "Invalid unit name." << std::endl;
        return;
    }

    std::string referenceUnit = InputHandler::getString("Reference unit (existing unit): ");
    double conversionFactor = InputHandler::getDouble("Conversion factor (how many reference units = 1 new unit): ");

    if (registry.addUnitToCategory(selectedCategory, newUnitName, referenceUnit, conversionFactor)) {
        std::cout << "Unit '" << newUnitName << "' added successfully!" << std::endl;
        std::cout << "1 " << newUnitName << " = " << conversionFactor << " " << referenceUnit << std::endl;
    } else {
        std::cout << "Failed to add unit. Check that the reference unit exists." << std::endl;
    }
}