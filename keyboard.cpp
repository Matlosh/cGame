#include "keyboard.h"
#include "battleSystem.h"
#include "player.h"
#include "maps.h"
#include <conio.h>

void key(Player* player, Maps* map, BattleSystem* bs) {
  if(bs->isFighting == false) {
    int c = getch();
    if(c == 119) { //up
      if(map->simpleMap[player->yPosition - 1][player->xPosition] != '#') {
        player->changePosition(map->simpleMap, player->yPosition, player->xPosition, ' ');
        player->yPosition--;
        player->changePosition(map->simpleMap, player->yPosition, player->xPosition, player->playerCharacter);
      }
    }
    if(c == 100) { //right
      if(map->simpleMap[player->yPosition][player->xPosition + 1] != '#') {
        player->changePosition(map->simpleMap, player->yPosition, player->xPosition, ' ');
        player->xPosition++;
        player->changePosition(map->simpleMap, player->yPosition, player->xPosition, player->playerCharacter);
      }
    }
    if(c == 115) { //down
      if(map->simpleMap[player->yPosition + 1][player->xPosition] != '#') {
        player->changePosition(map->simpleMap, player->yPosition, player->xPosition, ' ');
        player->yPosition++;
        player->changePosition(map->simpleMap, player->yPosition, player->xPosition, player->playerCharacter);
      }
    }
    if(c == 97) { //left
      if(map->simpleMap[player->yPosition][player->xPosition - 1] != '#') {
        player->changePosition(map->simpleMap, player->yPosition, player->xPosition, ' ');
        player->xPosition--;
        player->changePosition(map->simpleMap, player->yPosition, player->xPosition, player->playerCharacter);
      }
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