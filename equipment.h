#ifndef EQUIPMENT_H
#define EQUIPMENT_H

class Equipment {
  public:
    std::string name, type, subtype;
    int attackValue, defenseValue;
    bool isCountable;
};

void itemsDraw(class Entity* enemy, class Player* player, class Equipment items[], class BattleSystem* bs);

#include "equipment.cpp"
#endif