#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

class BattleSystem {
    int enemyHPmax, enemyPPmax, enemyAttackMax, enemyDefenseMax, playerPPmax, playerAttackMax, playerDefenseMax;
    int randNum, i, move;
  public:
    int x, y;
    static bool isFighting;
    void battle(class Player* player, class BattleSystem* bs, class Entity* enemy, class Equipment* items);
    void playerTurn(class Player* player, class BattleSystem* bs, class Entity* enemy);
    void enemyTurn(class Player* player, class BattleSystem* bs,class Entity* enemy);
    void clearBattleMenu(class BattleSystem* bs, int textHeight);
    void resetStats(class Entity* enemy, class Player* player);
    void rewardsDraw(class Entity* enemy, class Player* player, class BattleSystem* bs, class Equipment* items);
};

#include "battleSystem.cpp"
#endif