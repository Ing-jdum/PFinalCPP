
#ifndef MENU_H
#define MENU_H

#include "../data/UnitRegistry.h"

class Menu {
private:
    UnitRegistry& registry;
    
    void showMainMenu();
    void handleUserMode();
    void handleAdminMode();
    void performConversion();
    void addNewUnit();

public:
    Menu(UnitRegistry& registry);
    void run();
};

#endif
