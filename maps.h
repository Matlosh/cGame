#ifndef MAPS_H
#define MAPS_H

class Maps {
    int i, j;
  public:
    static int currentMap;
    static char maps[3][20][60];
    static char cMap[20][60];
    void nextMap();
    void previousMap();
};

#include "maps.cpp"
#endif