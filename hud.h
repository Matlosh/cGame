#ifndef HUD_H
#define HUD_H

class HUD {
    int i;
    static bool firstTime;
  public:
    static char battleMenu[30][74];
    static char menuBox[10][60];
    void showHUD(class Maps* map, class Menu* menu);
};

#include "hud.cpp"
#endif