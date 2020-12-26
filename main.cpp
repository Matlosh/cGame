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

using namespace std;

int main() {
  srand(time(NULL));
  int c;
  Maps map;

  Player player;
  player.HP = 20;
  player.PP = 5;
  player.PPmax = 5;
  player.attack = 10;
  player.defense = 10;
  player.xPosition = 1;
  player.yPosition = 1;
  player.playerCharacter = '@';
  player.playerTurn = true;
  
  BattleSystem bs;
  bs.x = 61;
  bs.y = 1;
  
  Entity wolf;
  wolf.name = "wolf";
  wolf.HP = 10;
  wolf.PP = 5;
  wolf.PPmax = 5;
  wolf.attack = 5;
  wolf.defense = 5;

  player.changePosition(map.simpleMap, player.yPosition, player.xPosition, player.playerCharacter);

  do {
    clearScreen();
    map.showMap();
    bs.battle(&player, &bs, &wolf);
    key(&player, &map, &bs);
  } while(c != 27);

  getch();
  return 0;
}