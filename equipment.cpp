#include "equipment.h"
#include <string>
#include "entity.h"
#include "player.h"
#include <cstdlib>
#include "battleSystem.h"
#include "additionalFunctions.h"

void itemsDraw(Entity* enemy, Player* player, Equipment items[], BattleSystem* bs) {
  int randNum = rand() % 101;
  bool isInInventory = false;
  if(randNum < enemy->firstItemChance) 
    if(enemy->firstItemNumber == -1) return;
    else {
      if(items[enemy->firstItemNumber].isCountable == true) {
        for(int i = 0; i < player->inventorySlot; i++) {
          if(player->inventory[i] == items[enemy->firstItemNumber].name) {
            isInInventory = true;
            player->inventoryItemAmount[i]++;
            print(enemy->name + " dropped " + items[enemy->firstItemNumber].name + "!", bs->x, bs->y++);
            break;
          }
        }
        if(!isInInventory) {
          player->inventoryItemAmount[player->inventorySlot] = 1;
          player->addItem(&items[enemy->firstItemNumber], player);
          print(enemy->name + " dropped " + items[enemy->firstItemNumber].name + "!", bs->x, bs->y++);
        }
      }
      if(items[enemy->firstItemNumber].isCountable == false) {
        player->inventoryItemSubType[player->inventorySlot] = items[enemy->firstItemNumber].subtype;
        player->addItem(&items[enemy->firstItemNumber], player);
        print(enemy->name + " dropped " + items[enemy->firstItemNumber].name + "!", bs->x, bs->y++);
      }
    }
  else if(enemy->firstItemChance < randNum && randNum < enemy->firstItemChance + enemy->secondItemChance)
    if(enemy->secondItemNumber == -1) return;
    else {
      if(items[enemy->secondItemNumber].isCountable == true) {
        for(int i = 0; i < player->inventorySlot; i++) {
          if(player->inventory[i] == items[enemy->secondItemNumber].name) {
            isInInventory = true;
            player->inventoryItemAmount[i]++;
            print(enemy->name + " dropped " + items[enemy->secondItemNumber].name + "!", bs->x, bs->y++);
            break;
          }
        }
        if(!isInInventory) {
          player->inventoryItemAmount[player->inventorySlot] = 1;
          player->addItem(&items[enemy->secondItemNumber], player);
          print(enemy->name + " dropped " + items[enemy->secondItemNumber].name + "!", bs->x, bs->y++);
        }
      }
      if(items[enemy->secondItemNumber].isCountable == false) {
        player->inventoryItemSubType[player->inventorySlot] = items[enemy->secondItemNumber].subtype;
        player->addItem(&items[enemy->secondItemNumber], player);
        print(enemy->name + " dropped " + items[enemy->secondItemNumber].name + "!", bs->x, bs->y++);
      }
    }
  else if(enemy->firstItemChance + enemy->secondItemChance < randNum && randNum < enemy->firstItemChance + enemy->secondItemChance + enemy->thirdItemChance)
    if(enemy->thirdItemNumber == -1) return;
    else { 
      if(items[enemy->thirdItemNumber].isCountable == true) {
        for(int i = 0; i < player->inventorySlot; i++) {
          if(player->inventory[i] == items[enemy->thirdItemNumber].name) {
            isInInventory = true;
            player->inventoryItemAmount[i]++;
            print(enemy->name + " dropped " + items[enemy->thirdItemNumber].name + "!", bs->x, bs->y++);
            break;
          }
        }
        if(!isInInventory) {
          player->inventoryItemAmount[player->inventorySlot] = 1;
          player->addItem(&items[enemy->thirdItemNumber], player);
          print(enemy->name + " dropped " + items[enemy->thirdItemNumber].name + "!", bs->x, bs->y++);
        }
      }
      if(items[enemy->thirdItemNumber].isCountable == false) {
        player->inventoryItemSubType[player->inventorySlot] = items[enemy->thirdItemNumber].subtype;
        player->addItem(&items[enemy->thirdItemNumber], player);
        print(enemy->name + " dropped " + items[enemy->thirdItemNumber].name + "!", bs->x, bs->y++);
      }
    }
  else
    if(enemy->thirdItemNumber == -1) return;
    else { 
      if(items[enemy->fourthItemNumber].isCountable == true) {
        for(int i = 0; i < player->inventorySlot; i++) {
          if(player->inventory[i] == items[enemy->fourthItemNumber].name) {
            isInInventory = true;
            player->inventoryItemAmount[i]++;
            print(enemy->name + " dropped " + items[enemy->fourthItemNumber].name + "!", bs->x, bs->y++);
            break;
          }
        }
        if(!isInInventory) {
          player->inventoryItemAmount[player->inventorySlot] = 1;
          player->addItem(&items[enemy->fourthItemNumber], player);
          print(enemy->name + " dropped " + items[enemy->fourthItemNumber].name + "!", bs->x, bs->y++);
        }
      }
      if(items[enemy->fourthItemNumber].isCountable == false) {
        player->inventoryItemSubType[player->inventorySlot] = items[enemy->fourthItemNumber].subtype;
        player->addItem(&items[enemy->fourthItemNumber], player);
        print(enemy->name + " dropped " + items[enemy->fourthItemNumber].name + "!", bs->x, bs->y++);
      }
    }
}