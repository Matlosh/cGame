#include "battleSystem.h"
#include "player.h"
#include <cstdlib>
#include "keyboard.h"
#include "entity.h"
#include <string>
#include <Windows.h>
#include "equipment.h"

#include "additionalFunctions.h"

using namespace std;

bool BattleSystem::isFighting = false;

void BattleSystem::battle(Player* player, BattleSystem* bs, Entity* enemy, Equipment items[]) {
  isFighting = true;
  print("Battle!", bs->x, bs->y++);
  randNum = rand() % 101;

  enemyHPmax = enemy->HP;
  enemyPPmax = enemy->PP;
  enemyAttackMax = enemy->attack;
  enemyDefenseMax = enemy->defense;
  playerPPmax = player->PP;
  playerAttackMax = player->attack;
  playerDefenseMax = player->defense;

  while(player->HP > 0 && enemy->HP > 0) {
    if(randNum >= 50) {
      enemy->PP = 0;
      playerTurn(player, bs, enemy);
    } else {
      player->PP = 0;
      enemyTurn(player, bs, enemy);
    }
  }

  rewardsDraw(enemy, player, bs, items);
  resetStats(enemy, player);
  print("The battle has ended.", bs->x, bs->y++);
  isFighting = false;
}

//1 - attack
//2 - increase defense
//3 - skip turn
void BattleSystem::playerTurn(Player* player, BattleSystem* bs, Entity* enemy) {
  clearBattleMenu(bs, 7);
  print("----------", bs->x, bs->y++);
  print("Your turn!", bs->x, bs->y++);
  print("What you want to do? PP: " + to_string(player->PP), bs->x, bs->y++);
  print("1.Attack (-3 PP)", bs->x, bs->y++);
  print("2.Increase defense (-2 PP)", bs->x, bs->y++);
  print("3.Skip turn (0 PP)", bs->x, bs->y++);
  print("----------", bs->x, bs->y++);
  while(player->HP > 0 && enemy->HP > 0) {
    move = bsKeys();
    clearBattleMenu(bs, 2);
    if(move == 1 && player->PP >= 3) {
      player->normalAttack(player, enemy, bs);
    }
    else if(move == 2 && player->PP >= 2) {
      player->raiseDefense(player, enemy, bs);
    }
    else if(move == 3) {
      print("You skipped your turn!", bs->x, bs->y++);
      enemy->PP += enemyPPmax;
      enemyTurn(player, bs, enemy);
    }
    else if(move != 1 && move != 2 && move != 3) {
      print("You can't do that!", bs->x, bs->y++);
    }
    else {
      print("You don't have enough PP for this move!", bs->x, bs->y++);
    }
  }
}

//1 - attack (60%) 3PP
//2 - defense (30%) 2PP
//3 - skip turn (10%) 0PP
void BattleSystem::enemyTurn(Player* player, BattleSystem* bs, Entity* enemy) {
  randNum = rand() % 101;
  clearBattleMenu(bs, 3);
  print("----------", bs->x, bs->y++);
  print("Enemy", bs->x, bs->y++);
  print("----------", bs->x, bs->y++);
  while(enemy->HP > 0 && player->HP > 0) {
    clearBattleMenu(bs, 2);
    if(randNum <= 60 && enemy->PP >= 3) {
      enemy->normalAttack(player, enemy, bs);
    }
    else if(randNum > 60 && randNum <= 90 && enemy->PP >= 2) {
      enemy->raiseDefense(player, enemy, bs);
    } else {
      print(enemy->name + " skipped his turn!", x, bs->y++);
      player->PP += playerPPmax;
      playerTurn(player, bs, enemy);
    }
  }
}

void BattleSystem::clearBattleMenu(BattleSystem* bs, int textHeight) {
  if(bs->y >= 29 - textHeight) {
    for(i = 1; i < bs->y; i++) {
      print("                                                                      ", bs->x, i);
    }
    bs->y = 1;
  }
}

void BattleSystem::resetStats(Entity* enemy, Player* player) {
  enemy->HP = enemyHPmax;
  enemy->PP = enemyPPmax;
  enemy->attack = playerAttackMax;
  enemy->defense = playerDefenseMax;

  player->PP = playerPPmax;
  player->attack = playerAttackMax;
  player->defense = playerDefenseMax;
}

void BattleSystem::rewardsDraw(Entity* enemy, Player* player, BattleSystem* bs, Equipment items[]) {
  randNum = rand() % enemy->expMax + enemy->expMin;
  print("----------", bs->x, bs->y++);
  if(randNum > 0) {
    print("You gained " + to_string(randNum) + " EXP from this battle!", bs->x, bs->y++);
    player->exp += randNum;
  } else {
    print("You didn't gain any EXP from this battle.", bs->x, bs->y++);
  }
  randNum = rand() % enemy->goldMax + enemy->goldMin;
  if(randNum > 0) {
    print("You earned " + to_string(randNum) + " gold from this battle!", bs->x, bs->y++);
    player->gold += randNum;
  } else {
    print("You didn't gain any gold from this battle.", bs->x, bs->y++);
  }
  itemsDraw(enemy, player, items, bs);
  print("----------", bs->x, bs->y++);
}