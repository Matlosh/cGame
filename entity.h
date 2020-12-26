#ifndef ENTITY_H
#define ENTITY_H

class Entity {
  public:
    string name;
    int HP, PP, PPmax, attack, defense;
    //attacks/skills
    void normalAttack(class Player* player, class Entity* enemy, class BattleSystem* bs);
    void raiseDefense(class Player* player, class Entity* enemy, class BattleSystem* bs);
};

#include "entity.cpp"
#endif