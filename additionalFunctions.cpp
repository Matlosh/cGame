#include "additionalFunctions.h"
#include <Windows.h>

void clearScreen() {
  COORD cursorPosition;
  cursorPosition.X = 0;
  cursorPosition.Y = 0;

  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void changePointer(int y) {
  COORD cursorPosition;
  cursorPosition.X = 61;
  cursorPosition.Y = 0;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void print(string text, int x, int y) {
  COORD cursorPosition;
  cursorPosition.X = x;
  cursorPosition.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
  cout << text << endl;
}