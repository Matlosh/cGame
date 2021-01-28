#ifndef ENTITY_H
#define ENTITY_H

class Entity {
  public:
    std::string name;
    int HP, PP, attack, defense, expMin, expMax, goldMin, goldMax, firstItemChance, secondItemChance, thirdItemChance, fourthItemChance, firstItemNumber, secondItemNumber, thirdItemNumber, fourthItemNumber;
    //attacks/skills
    void normalAttack(class Player* player, class Entity* enemy, class BattleSystem* bs);
    void raiseDefense(class Player* player, class Entity* enemy, class BattleSystem* bs);
};

void enemyDraw(class Entity enemy[], class Player* player, class BattleSystem* bs, class Maps* map, class Equipment items[]);

#include "entity.cpp"
#endif