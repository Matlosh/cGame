#ifndef PLAYER_H
#define PLAYER_H

class Player {
  public:
    int HP, PP, PPmax, attack, defense, xPosition, yPosition;
    char playerCharacter;
    bool playerTurn;
    void changePosition(char mapName[20][60], int yPosition, int xPosition, char playerCharacter);
    //attacks/skills
    void normalAttack(class Player* player, class Entity* enemy, class BattleSystem* bs);
    void raiseDefense(class Player* player, class Entity* enemy, class BattleSystem* bs);
};

#include "player.cpp"
#endif