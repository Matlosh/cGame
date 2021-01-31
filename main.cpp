#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include "maps.h"
#include "player.h"
#include "keyboard.h"
#include "battleSystem.h"
#include "additionalFunctions.h"
#include "entity.h"
#include "hud.h"
#include "menu.h"
#include "equipment.h"

#include <array>

using namespace std;

int main() {
  srand(time(NULL));
  setWindowSize(1100, 600);

  int c;
  HUD hud;

  Maps testMap;

  //strings
  Maps map;

  Player player;
  player.HP = 100;
  player.PP = 5;
  player.attack = 50;
  player.defense = 10;
  player.xPosition = 1;
  player.yPosition = 1;
  player.playerCharacter = '@';
  player.playerTurn = true;
  player.exp = 0;
  player.gold = 0;
  player.lvl = 1;
  player.inventorySlot = 0;
  for(int i = 0; i < (sizeof(player.inventoryItemAmount)/sizeof(player.inventoryItemAmount[0])); i++) {
    player.inventoryItemAmount[i] = -1;
    player.inventoryItemSubType[i] = "none";
  }
  for(int i = 0; i < (sizeof(player.armour)/sizeof(player.armour[0])); i++) {
    player.armour[i] = "none"; // 0 = head, 1 = chest, 2 = hands, 3 = legs, 4 = feet
    player.armourValues[i] = 0;
  }

  BattleSystem bs;
  bs.x = 61;
  bs.y = 1;

  Entity enemy[5];
  enemy[1].name = "wolf";
  enemy[1].HP = 20;
  enemy[1].PP = 5;
  enemy[1].attack = 5;
  enemy[1].defense = 5;
  enemy[1].expMin = 0;
  enemy[1].expMax = 4;
  enemy[1].goldMin = 0;
  enemy[1].goldMax = 10;
  enemy[1].firstItemChance = 20;
  enemy[1].secondItemChance = 35;
  enemy[1].thirdItemChance = 30;
  enemy[1].fourthItemChance = 15;
  enemy[1].firstItemNumber = 1;
  enemy[1].secondItemNumber = 8;
  enemy[1].thirdItemNumber = 1;
  enemy[1].fourthItemNumber = 8;

  enemy[2].name = "boar";
  enemy[2].HP = 30;
  enemy[2].PP = 5;
  enemy[2].attack = 3;
  enemy[2].defense = 10;
  enemy[2].expMin = 0;
  enemy[2].expMax = 3;
  enemy[2].goldMin = 0;
  enemy[2].goldMax = 12;

  enemy[3].name = "bear";
  enemy[3].HP = 50;
  enemy[3].PP = 10;
  enemy[3].attack = 10;
  enemy[3].defense = 10;
  enemy[3].expMin = 0;
  enemy[3].expMax = 6;
  enemy[3].goldMin = 0;
  enemy[3].goldMax = 15;

  enemy[4].name = "bird";
  enemy[4].HP = 10;
  enemy[4].PP = 10;
  enemy[4].attack = 3;
  enemy[4].defense = 5;
  enemy[4].expMin = 0;
  enemy[4].expMax = 2;
  enemy[4].goldMin = 0;
  enemy[4].goldMax = 6;

  //each isCountable == false must have subtype
  //each item must have type and isCountable
  Equipment items[9];
  items[0].name = "Sword";
  items[0].value = 5;
  items[0].type = "Weapon";
  items[0].isCountable = false;

  items[1].name = "Leather Helmet";
  items[1].value = 5;
  items[1].type = "Armour";
  items[1].subtype = "Head";
  items[1].isCountable = false;

  items[2].name = "Leather Chestplate";
  items[2].value = 8;
  items[2].type = "Armour";
  items[2].subtype = "Chest";
  items[2].isCountable = false;

  items[3].name = "Leather Boots";
  items[3].value = 4;
  items[3].type = "Armour";
  items[3].subtype = "Feet";
  items[3].isCountable = false;
  
  items[4].name = "First Item";
  items[4].isCountable = true;
  items[4].type = "Armour";

  items[5].name = "Second Item";
  items[5].isCountable = false;
  items[5].type = "Weapon";

  items[6].name = "Third Item";
  items[6].isCountable = true;
  items[6].type = "Food";

  items[7].name = "Fourth Item";
  items[7].isCountable = false;
  items[7].type = "Armour";

  items[8].name = "Legendary Helmet";
  items[8].value = 20;
  items[8].type = "Armour";
  items[8].subtype = "Head";
  items[8].isCountable = false;

  Menu menu;

  string tekst[7] = {"test", "test2", "test3", "test4", "test5", "test6", "test7"};

  array<array<int, 3>, 2> arr {{
    {{1, 2, 3}},
    {{4, 5, 6}}
  }};

  array<int, 3> test = arr[1];
  print(to_string(test[1]), 2, 36);

  map.nextMap();

  print(to_string(player.inventoryItemAmount[0]), 2, 49);

  bool p = false;

  do {
    clearScreen();
    hud.showHUD(&map, &menu);
    if(p == true) {
      bs.battle(&player, &bs, &enemy[0], items);
      p = false;
    }
    key(&player, &map, &bs, &menu, enemy, items);
  } while(c != 27);

  getch();
  return 0;
}