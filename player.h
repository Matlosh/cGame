#ifndef PLAYER_H
#define PLAYER_H

class Player {
  public:
    int HP, PP, attack, defense, xPosition, yPosition, exp, gold, lvl, inventorySlot;
    char playerCharacter;
    bool playerTurn;
    char inventory[14][23];
    std::string inventoryItemType[14], inventoryItemSubType[14], armour[5];
    int inventoryItemAmount[14], inventoryItemValue[14], armourValues[5];
    void changePosition(class Maps* map, int yPosition, int xPosition, char playerCharacter);
    //attacks/skills
    void normalAttack(class Player* player, class Entity* enemy, class BattleSystem* bs);
    void raiseDefense(class Player* player, class Entity* enemy, class BattleSystem* bs);
    //items
    void addItem(class Equipment* items, class Player* player);
};

#include "player.cpp"
#endif