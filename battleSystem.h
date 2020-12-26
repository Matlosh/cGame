#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

class BattleSystem {
  public:
    int x, y;
    static bool isFighting;
    void battle(class Player* player, class BattleSystem* bs, class Entity* enemy);
    void playerTurn(class Player* player, class BattleSystem* bs, class Entity* enemy);
    void enemyTurn(class Player* player, class BattleSystem* bs,class Entity* enemy);
};

#include "battleSystem.cpp"
#endif