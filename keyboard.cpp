#include "keyboard.h"
#include "battleSystem.h"
#include "player.h"
#include "maps.h"
#include <conio.h>
#include "menu.h"

#include "entity.h"

#include "additionalFunctions.h"

using namespace std;
//'%' - nastepna mapa
//'$' - walka z przeciwnikiem
//'#' - obiekt nie do przejscia (granica)
//'&' - poprzednia mapa
void key(Player* player, Maps* map, BattleSystem* bs, Menu* menu, Entity enemy[], Equipment items[]) {
  if(bs->isFighting == false) {
    int c = getch();
    switch (c)
    {
    case 119:
      movementKey(player, map, bs, menu, enemy, items, 0, 1);
    break;

    case 100:
      movementKey(player, map, bs, menu, enemy, items, -1, 0);
    break;

    case 115:
      movementKey(player, map, bs, menu, enemy, items, 0, -1);
    break;

    case 97:
      movementKey(player, map, bs, menu, enemy, items, 1, 0);
    break;

    case 49: //"1" key
      menuKeySettings('1', 'i', menu);
      menu->showInventory(2, 21, player, menu);
    break;

    case 50: //"2" key
      menuKeySettings('2', ';', menu);
      menu->showStats(2, 22, player);
    break;

    case 51: //"3" key
      menuKeySettings('3', ';', menu);
      menu->showEquipment(2, 21, player);
    break;

    case 122: //"z" key
      changeEquipmentKey(2, 21, player, items, "Head", menu, 'z');
    break;

    case 120: //"x" key
      changeEquipmentKey(2, 21, player, items, "Chest", menu, 'x');
    break;

    case 99: //"c" key
      changeEquipmentKey(2, 21, player, items, "Hands", menu, 'c');
    break;

    case 118: //"v" key
      changeEquipmentKey(2, 21, player, items, "Legs", menu, 'v');
    break;

    case 98: //"b" key
      changeEquipmentKey(2, 21, player, items, "Feet", menu, 'b');
    break;

    case 13: //"enter" key
      menu->switchEquipment(player, menu);
    break;

    //can add another "switch" if is needed
    }
    if(currentSubKey == 'z') {
      if(c == 72) {
        print("test1", 2, 52);
        menu->positionValue--;
        menu->changeEquipment(2, 21, player, items, "Head", menu);
      }
      if(c == 80) {
        print("test2", 2, 52);
        menu->positionValue++;
        menu->changeEquipment(2, 21, player, items, "Head", menu);
      }
    }
    if(currentSubKey == 'x') {
      if(c == 72) {
        print("test1", 2, 52);
        menu->positionValue--;
        menu->changeEquipment(2, 21, player, items, "Chest", menu);
      }
      if(c == 80) {
        print("test2", 2, 52);
        menu->positionValue++;
        menu->changeEquipment(2, 21, player, items, "Chest", menu);
      }
    }
    if(currentSubKey == 'c') {
      if(c == 72) {
        print("test1", 2, 52);
        menu->positionValue--;
        menu->changeEquipment(2, 21, player, items, "Hands", menu);
      }
      if(c == 80) {
        print("test2", 2, 52);
        menu->positionValue++;
        menu->changeEquipment(2, 21, player, items, "Hands", menu);
      }
    }
    if(currentSubKey == 'v') {
      if(c == 72) {
        print("test1", 2, 52);
        menu->positionValue--;
        menu->changeEquipment(2, 21, player, items, "Legs", menu);
      }
      if(c == 80) {
        print("test2", 2, 52);
        menu->positionValue++;
        menu->changeEquipment(2, 21, player, items, "Legs", menu);
      }
    }
    if(currentSubKey == 'b') {
      if(c == 72) {
        print("test1", 2, 52);
        menu->positionValue--;
        menu->changeEquipment(2, 21, player, items, "Feet", menu);
      }
      if(c == 80) {
        print("test2", 2, 52);
        menu->positionValue++;
        menu->changeEquipment(2, 21, player, items, "Feet", menu);
      }
    }
    if(currentSubKey == 'i') {
      if(c == 72) {
        menu->positionValue--;
        menu->showInventory(2, 21, player, menu);
      }
      if(c == 80) {
        menu->positionValue++;
        menu->showInventory(2, 21, player, menu);
      }
    }
    if(c == 48) { //"0" key
      currentKey = '0';
      currentSubKey = ';';
      menu->showMenu(2, 21);
    }
  }
}

int bsKeys() {
  int c = getch();
  if(c == 49) { //1
    return 1;
  }
  if(c == 50) { //2
    return 2;
  }
  if(c == 51) { //3
    return 3;
  }
}

void movementKey(Player* player, Maps* map, BattleSystem* bs, Menu* menu, Entity enemy[], Equipment items[], int mapMoveNumberX, int mapMoveNumberY) {
  if(map->cMap[player->yPosition - (mapMoveNumberY)][player->xPosition - (mapMoveNumberX)] != '#') {
    if(map->cMap[player->yPosition - (mapMoveNumberY)][player->xPosition - (mapMoveNumberX)] == '%') {
      map->nextMap();
      player->changePosition(map, player->yPosition, player->xPosition, player->playerCharacter);
    } 
    else if(map->cMap[player->yPosition - (mapMoveNumberY)][player->xPosition - (mapMoveNumberX)] == '$') {
      enemyDraw(enemy, player, bs, map, items);
      player->changePosition(map, player->yPosition - (mapMoveNumberY), player->xPosition - (mapMoveNumberX), ' ');
    } 
    else if(map->cMap[player->yPosition - (mapMoveNumberY)][player->xPosition - (mapMoveNumberX)] == '&') {
      map->previousMap();
      player->changePosition(map, player->yPosition, player->xPosition, player->playerCharacter);
    } else {
      player->changePosition(map, player->yPosition, player->xPosition, ' ');
      player->yPosition -= (mapMoveNumberY);
      player->xPosition -= (mapMoveNumberX);
      player->changePosition(map, player->yPosition, player->xPosition, player->playerCharacter);
    }
  }
}

void menuKeySettings(char cKey, char cSubKey, Menu* menu) {
  /* next 2 lines for "inventory" tab */
  menu->inventoryPosition = 0;
  menu->positionValue = 0;
  currentKey = cKey;
  currentSubKey = cSubKey;
}

void changeEquipmentKey(int x, int y, Player* player, Equipment items[], string armourType, Menu* menu, char cSubKey) {
  menu->inventoryPosition = 0;
  menu->positionValue = 0;
  if(currentKey == '3') {
    menu->changeEquipment(x, y, player, items, armourType, menu);
    currentSubKey = cSubKey;
  }
}