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
    itemDraw(enemy, player, items, bs, enemy->firstItemChance, enemy->firstItemNumber, isInInventory);
  else if(enemy->firstItemChance < randNum && randNum < enemy->firstItemChance + enemy->secondItemChance)
    itemDraw(enemy, player, items, bs, enemy->secondItemChance, enemy->secondItemNumber, isInInventory);
  else if(enemy->firstItemChance + enemy->secondItemChance < randNum && randNum < enemy->firstItemChance + enemy->secondItemChance + enemy->thirdItemChance)
    itemDraw(enemy, player, items, bs, enemy->thirdItemChance, enemy->thirdItemNumber, isInInventory);
  else
    itemDraw(enemy, player, items, bs, enemy->fourthItemChance, enemy->fourthItemNumber, isInInventory);
}

void itemDraw(Entity* enemy, Player* player, Equipment items[], BattleSystem* bs, int itemChance, int itemNumber, bool isInInventory) {
  if(itemNumber == -1) return;
  else {
    if(items[itemNumber].isCountable == true) {
      for(int i = 0; i < player->inventorySlot; i++) {
        if(player->inventory[i] == items[itemNumber].name) {
          isInInventory = true;
          player->inventoryItemAmount[i]++;
          print(enemy->name + " dropped " + items[itemNumber].name + "!", bs->x, bs->y++);
          break;
        }
      }
      if(!isInInventory) {
        player->inventoryItemAmount[player->inventorySlot] = 1;
        player->inventoryItemValue[player->inventorySlot] = items[itemNumber].value;
        player->addItem(&items[itemNumber], player);
        print(enemy->name + " dropped " + items[itemNumber].name + "!", bs->x, bs->y++);
      }
    } 
    if(items[itemNumber].isCountable == false) {
      player->inventoryItemType[player->inventorySlot] = items[itemNumber].type;
      player->inventoryItemSubType[player->inventorySlot] = items[itemNumber].subtype;
      player->inventoryItemValue[player->inventorySlot] = items[itemNumber].value;
      player->addItem(&items[itemNumber], player);
      print(enemy->name + " dropped " + items[itemNumber].name + "!", bs->x, bs->y++);
    }
  }
}