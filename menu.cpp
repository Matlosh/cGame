#include "menu.h"
#include "additionalFunctions.h"
#include "player.h"
#include "equipment.h"

int Menu::positionValue = 0;
int Menu::inventoryPosition = 0;

void Menu::clearMenu() {
  for(i = 0; i < 8; i++) {
    print("                                                         ", 1, 21+i);
  }
}

void Menu::inventoryUpAndDownChecker(Menu* menu, Player* player) {
  cursorEquipment = positionValue + 22;
  if(positionValue > 6) positionValue--;
  if(positionValue < 0) positionValue++;
  if(cursorEquipment > 28 && inventoryPosition + 7 <= player->inventorySlot) {
    menu->inventoryPosition++;
    cursorEquipment--;
  }
  if(cursorEquipment > 22 && inventoryPosition + positionValue >= player->inventorySlot) {
    cursorEquipment--;
    positionValue--;
  }
  if(cursorEquipment < 22 && inventoryPosition == 0) cursorEquipment++;
  if(cursorEquipment < 22 && inventoryPosition > 0) {
    menu->inventoryPosition--;
    cursorEquipment++;
  }
  print(to_string(positionValue), 3, 54);
}

void Menu::showMenu(int x, int y) {
  clearMenu();
  print("1.Inventory", x, y++);
  print("2.Stats", x, y++);
  print("3.Equipment", x, y++);
  print("4.", x, y++);
  print("5.", x, y++);
  print("6.", x, y++);
  print("7.", x, y++);
  print("0.Menu", x, y++);
}

void Menu::showInventory(int x, int y, Player* player, Menu* menu) {
  clearMenu();
  menu->inventoryUpAndDownChecker(menu, player);
  print("Inventory:", 23, y++);
  for(i = inventoryPosition; i < player->inventorySlot; i++) {
    if(i >= inventoryPosition + 7) break;
    if(cursorEquipment == y && player->inventoryItemAmount[i] == -1) {
      print("--> " + to_string(i+1) + "." + player->inventory[i], 2, y++);
      continue;
    }
    else if(player->inventoryItemAmount[i] == -1) {
      print("    " + to_string(i+1) + "." + player->inventory[i], 2, y++);
      continue;
    }
    else if(cursorEquipment == y && player->inventoryItemAmount[i] > 0) {
      print("--> " + to_string(i+1) + "." + player->inventory[i] + ": " + to_string(player->inventoryItemAmount[i]), x, y++);
      continue;
    }
    else {
      print("    " + to_string(i+1) + "." + player->inventory[i] + ": " + to_string(player->inventoryItemAmount[i]), x, y++);
      continue;
    }
  }
}

void Menu::showStats(int x, int y, Player* player) {
  clearMenu();
  y--;
  print("Stats:", 25, y++);
  print("Attack: " + to_string(player->attack), x, y++);
  print("Defense: " + to_string(player->defense), x, y++);
  print("Power Points (PP): " + to_string(player->PP), x, y++);
  print("Health Points (HP): " + to_string(player->HP), x, y++);
  print("Experience Points (EXP): " + to_string(player->exp), x, y++);
  print("Gold: " + to_string(player->gold), x, y++);
  print("Level (LVL): " + to_string(player->lvl), x, y++);
}

void Menu::showEquipment(int x, int y, Player* player) {
  clearMenu();
  print("Equipment:", 23, y++);
  print("Head: [" + player->armour[0] + "]", 23, y++);
  print("Chest: [" + player->armour[1] + "]", 23, y++);
  print("Left hand: [" + player->armour[2] + "]", 2, y);
  print("Right hand: [" + player->armour[2] + "]", 30, y++);
  print("Legs: [" + player->armour[3] + "]", 23, y++);
  print("Left foot: [" + player->armour[4] + "]", 2, y);
  print("Right foot: [" + player->armour[4] + "]", 30, y++);
  print("Change equipment on:", 2, y);
  print("head: [z] chest: [x]", 23, y++);
  print("hands: [c] legs: [v] feet: [b]", 23, y);
}

void Menu::changeEquipment(int x, int y, Player* player, Equipment items[], string armourType, Menu* menu) {
  clearMenu();
  j = 0;
  menu->inventoryUpAndDownChecker(menu, player);
  print("Change " + armourType + ":", 22, y++);
  for(i = inventoryPosition; i < player->inventorySlot; i++) { //there
    if(i >= inventoryPosition + 7) break;
    if(cursorEquipment == y && player->inventoryItemSubType[i] == armourType) {
      j++;
      print("--> " + to_string(j) + "." + player->inventory[i], 2, y++);
      continue;
    }
    if(player->inventoryItemSubType[i] == armourType) {
      j++;
      print("    " + to_string(j) + "." + player->inventory[i], 2, y++);
      continue;
    }
  }
}

void Menu::switchEquipment(Player* player, Menu* menu) {
  int currentItemSlot = positionValue;
  std::string types[5] = {"Head", "Chest", "Hands", "Legs", "Feet"};
  if(player->inventoryItemType[currentItemSlot] == "Armour") {
    for(int i = 0; i < 5; i++) {
      if(player->inventoryItemSubType[currentItemSlot] == types[i]) {
        player->armour[i] = player->inventory[currentItemSlot];
        player->defense -= player->armourValues[i];
        player->defense += player->inventoryItemValue[currentItemSlot];
        player->armourValues[i] = player->inventoryItemValue[currentItemSlot];
      }
    }
  }
}