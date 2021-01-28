#ifndef KEYBOARD_H
#define KEYBOARD_H

char currentKey, currentSubKey;
void key(class Player* player, class Maps* map, class BattleSystem* bs, class Menu* menu, class Entity enemy[], class Equipment items[]);
int bsKeys();

void movementKey(class Player* player, class Maps* map, class BattleSystem* bs, class Menu* menu, class Entity enemy[], class Equipment items[], int mapMoveNumberX, int mapMoveNumberY);
void menuKeySettings(char cKey, char cSubKey);
void changeEquipmentKey(int x, int y, class Player* player, class Equipment items[], std::string armourType, class Menu* menu, char cSubKey);

#include "keyboard.cpp"
#endif