#include "maps.h"
#include <string>
#include "player.h"

int Maps::currentMap = -1;

char Maps::cMap[20][60] = {
  {"                                                           "},
  {"                                                           "},
  {"                                                           "},
  {"                                                           "},
  {"                                                           "},
  {"                                                           "},
  {"                                                           "},
  {"                                                           "},
  {"                                                           "},
  {"                                                           "},
  {"                                                           "},
  {"                                                           "},
  {"                                                           "},
  {"                                                           "},
  {"                                                           "},
  {"                                                           "},
  {"                                                           "},
  {"                                                           "},
  {"                                                           "},
  {"                                                           "}
};

char Maps::maps[3][20][60] = {
  {
    {"###########################################################"},
    {"#         #################################################"},
    {"#          ################################################"},
    {"#           ###############################################"},
    {"#            ##############################################"},
    {"##            #############################################"},
    {"####           ######    #  #####################         #"},
    {"#####                           ##                      % #"},
    {"#######                                                   #"},
    {"#########                              #### ###############"},
    {"############                  #############################"},
    {"#############                ##############################"},
    {"#############             #################################"},
    {"#############             #################################"},
    {"##############            #################################"},
    {"##############            #################################"},
    {"###############           #################################"},
    {"###############     $     #################################"},
    {"###############           #######################simpleMap#"},
    {"###########################################################"}
  },
  {
    {"###########################################################"},
    {"###############   $  ######################################"},
    {"##############      #######################################"},
    {"###############      ######################################"},
    {"###############       #####################################"},
    {"###############      ######################################"},
    {"###                                                       #"},
    {"## %                                                    & #"},
    {"###                                                       #"},
    {"###############      ######################################"},
    {"##############      #######################################"},
    {"##############       ######################################"},
    {"##############        #####################################"},
    {"##############        #####################################"},
    {"###############       #####################################"},
    {"###############      ######################################"},
    {"################   $  #####################################"},
    {"################       ####################################"},
    {"################       #############################route1#"},
    {"###########################################################"}
  },
  {
    {"###########################################################"},
    {"#                                                         #"},
    {"#                                                         #"},
    {"#                                                         #"},
    {"#                                                         #"},
    {"#                                                         #"},
    {"#                                                         #"},
    {"#  &                                                      #"},
    {"#                                                         #"},
    {"#                                                         #"},
    {"#                                                         #"},
    {"#                                                         #"},
    {"#                                                         #"},
    {"#                                                         #"},
    {"#                                                         #"},
    {"#                                                         #"},
    {"#                                                         #"},
    {"#                                                         #"},
    {"#                                                  route2 #"},
    {"###########################################################"}
  }
};

void Maps::nextMap() {
  currentMap++;
  for(i = 0; i < 20; i++) {
    for(j = 0; j < 60; j++) {
      cMap[i][j] = maps[currentMap][i][j];
    }
  }
}

void Maps::previousMap() {
  currentMap--;
  for(i = 0; i < 20; i++) {
    for(j = 0; j < 60; j++) {
      cMap[i][j] = maps[currentMap][i][j];
    }
  }
}