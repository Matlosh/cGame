#include "additionalFunctions.h"
#include <Windows.h>

#include <string>

using namespace std;

void setWindowSize(int width, int height) {
  HWND console = GetConsoleWindow();
  RECT r;
  GetWindowRect(console, &r);
  
  MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void clearScreen() {
  COORD cursorPosition;
  cursorPosition.X = 0;
  cursorPosition.Y = 0;

  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void print(std::string text, int x, int y) {
  COORD cursorPosition;
  cursorPosition.X = x;
  cursorPosition.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
  cout << text << endl;
}