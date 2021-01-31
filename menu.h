#ifndef MENU_H
#define MENU_H

class Menu {
    int i, j, cursorEquipment, cursorInventory;
  public:
    static int positionValue, inventoryPosition;
    void clearMenu();
    void showMenu(int x, int y);
    void showInventory(int x, int y, class Player* player, class Menu* menu);
    void showStats(int x, int y, class Player* player);
    void showEquipment(int x, int y, class Player* player);
    void changeEquipment(int x, int y, class Player* player, class Equipment items[], std::string armourType, class Menu* menu);
    void inventoryUpAndDownChecker(class Menu* menu, class Player* player);
    void switchEquipment(class Player* player, class Menu* menu);
};

#include "menu.cpp"
#endif