#include "menu.h"
#include "additionalFunctions.h"
#include "player.h"
#include "equipment.h"

void Menu::clearMenu() {
  for(i = 0; i < 8; i++) {
    print("                                                         ", 1, 21+i);
  }
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

void Menu::showInventory(int x, int y, Player* player) {
  clearMenu();
  print("Inventory:", 23, y++);
  for(i = 0; i < player->inventorySlot; i++) {
    if(player->inventoryItemAmount[i] == -1)
      print(to_string(i+1) + "." + player->inventory[i], x, y++);
    else
      print(to_string(i+1) + "." + player->inventory[i] + ": " + to_string(player->inventoryItemAmount[i]), x, y++);
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
  print("Head: [" + player->head + "]", 23, y++);
  print("Chest: [" + player->chest + "]", 23, y++);
  print("Left hand: [" + player->hands + "]", 2, y);
  print("Right hand: [" + player->hands + "]", 30, y++);
  print("Legs: [" + player->legs + "]", 23, y++);
  print("Left foot: [" + player->feet + "]", 2, y);
  print("Right foot: [" + player->feet + "]", 30, y++);
  print("Change equipment on:", 2, y);
  print("head: [z] chest: [x]", 23, y++);
  print("hands: [c] legs: [v] feet: [b]", 23, y);
}

int Menu::testValue = 0;
int Menu::inventoryPosition = 0;

void Menu::changeEquipment(int x, int y, Player* player, Equipment items[], string armourType, Menu* menu) {
  clearMenu();
  cursorEquipment = testValue + 22;
  if(testValue > 6) testValue--;
  if(testValue < 0) testValue++;
  if(cursorEquipment > 28) {
    menu->inventoryPosition++;
    cursorEquipment--;
  }
  if(cursorEquipment < 22 && inventoryPosition > 0) {
    menu->inventoryPosition--;
    cursorEquipment++;
  }

  print("Change " + armourType + ":", 22, y++);
  for(i = inventoryPosition; i < player->inventorySlot; i++) { //there
    if(i >= inventoryPosition+7) break;
    if(cursorEquipment == y && player->inventoryItemSubType[i] == armourType) {
      print("--> " + to_string(i+1) + "." + player->inventory[i], 2, y++);
      continue;
    }
    if(player->inventoryItemSubType[i] == armourType) {
      print("    " + to_string(i+1) + "." + player->inventory[i], 2, y++);
      continue;
    }
  }
}