
#include <iostream>
#include <string>
#include "ui/Menu.h"
#include "data/UnitRegistry.h"

int main() {
    std::cout << "=== Unit Converter Application ===" << std::endl;
    
    UnitRegistry registry;
    Menu menu(registry);
    
    menu.run();
    
    return 0;
}
