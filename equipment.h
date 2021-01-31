#ifndef EQUIPMENT_H
#define EQUIPMENT_H

class Equipment {
  public:
    std::string name, type, subtype;
    int value; // value means attackValue, defenseValue etc. It just depends from item and its type
    bool isCountable;
};

void itemsDraw(class Entity* enemy, class Player* player, class Equipment items[], class BattleSystem* bs);
void itemDraw(class Entity* enemy, class Player* player, class Equipment items[], class BattleSystem* bs, int itemChance, int itemNumber, bool isInInventory);

#include "equipment.cpp"
#endif