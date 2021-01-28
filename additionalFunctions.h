#ifndef ADDITIONALFUNCTIONS_H
#define ADDITIONALFUNCTIONS_H

void setWindowSize(int width, int height);
void clearScreen();
void changePointer(int y);
void print(std::string text, int x, int y); //"string" bez "std::" wyrzuca blad

#include "additionalFunctions.cpp"
#endif
