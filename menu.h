#ifndef MENU_H
#define MENU_H

class Menu {
    int i, j, cursorEquipment, cursorInventory;
  public:
    static int testValue, inventoryPosition;
    void clearMenu();
    void showMenu(int x, int y);
    void showInventory(int x, int y, class Player* player);
    void showStats(int x, int y, class Player* player);
    void showEquipment(int x, int y, class Player* player);
    void changeEquipment(int x, int y, class Player* player, class Equipment items[], std::string armourType, class Menu* menu);
};

#include "menu.cpp"
#endif