#include "player.h"
#include "entity.h"
#include "additionalFunctions.h"
#include "battleSystem.h"
#include "maps.h"
#include "equipment.h"

void Player::changePosition(Maps* map, int yPosition, int xPosition, char playerCharacter) {
  map->cMap[yPosition][xPosition] = playerCharacter;
}

void Player::normalAttack(Player* player, Entity* enemy, BattleSystem* bs) {
  int randNum;
  player->PP -= 3;
      randNum = rand() % 101;
      if(randNum > 20) {
        int randAtt = rand() % player->attack + 1; 
        int randEnemyDef = rand() % enemy->defense + 1;
        if((randAtt - randEnemyDef) > 0) {
          enemy->HP -= randAtt - randEnemyDef;
          print("You attacked " + enemy->name + " and he lost " + to_string(randAtt - randEnemyDef) + " HP!", bs->x, bs->y++);
          print(enemy->name + " has still " + to_string(enemy->HP) + " HP!", bs->x, bs->y++);
        } else {
          print(enemy->name + " blocked your attack!", bs->x, bs->y++);
        }
      } else {
        print("You missed!", bs->x, bs->y++);
      }
}

void Player::raiseDefense(Player* player, Entity* enemy, BattleSystem* bs) {
  int randNum;
  player->PP -= 2;
      randNum = rand() % 101;
      if(randNum > 40) {
        int defIncrease = rand() % 6;
        if(defIncrease != 0) {
          player->defense += defIncrease;
          print("Your defense was increased by " + to_string(defIncrease) + " points!", bs->x, bs->y++);
          print("Now your defense is equal to " + to_string(player->defense) + " points.", bs->x, bs->y++);
        } else {
          print("Something went wrong and you weren't able to use that skill properly!", bs->x, bs->y++);
        }
      } else {
        print("You failed!", bs->x, bs->y++);
      }
}

void Player::addItem(Equipment* items, Player* player) {
  for(int j = 0; j < 23; j++) {
    player->inventory[player->inventorySlot][j] = items->name[j];
  }
  player->inventorySlot++;
}