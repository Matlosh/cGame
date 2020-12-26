#include "entity.h"
#include "player.h"
#include "battleSystem.h"
#include "additionalFunctions.h"

void Entity::normalAttack(Player* player, Entity* enemy, BattleSystem* bs) {
  int randNum;
  enemy->PP -= 3;
      randNum = rand() % 101;
      if(randNum > 10) {
        int randAtt = rand() % enemy->attack + 1;
        int randPlayerDef = rand() % player->defense + 1;
        if((randAtt - randPlayerDef) > 0) {
          player->HP -= randAtt - randPlayerDef;
          print(enemy->name + " attacked you!" + " You lost " + to_string(randAtt - randPlayerDef) + " HP!", bs->x, bs->y++);
          print("You still have " + to_string(player->HP) + " HP left!", bs->x, bs->y++);
        } else {
          print("You blocked " + enemy->name + " attack!", bs->x, bs->y++);
        }
      } else {
        print(enemy->name + " missed!", bs->x, bs->y++);
      }
}

void Entity::raiseDefense(Player* player, Entity* enemy, BattleSystem* bs) {
  int randNum;
  enemy->PP -= 2;
      randNum = rand() % 101;
      if(randNum > 40) {
        int defIncrease = rand() % 6;
        if(defIncrease != 0) {
          enemy->defense += defIncrease;
          print(enemy->name + " has increased his defense by " + to_string(defIncrease) + " points!", bs->x, bs->y++);
          print("Now his defense is equal to " + to_string(enemy->defense) + " points!", bs->x, bs->y++);
        } else {
          print("Something went wrong and " + enemy->name + " wasn't able to use that skill properly!", bs->x, bs->y++);
        }
      } else {
        print(enemy->name + " failed!", bs->x, bs->y++);
      }
}