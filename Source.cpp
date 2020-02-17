#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include "Menu.h"
#include "Game.h"

using namespace std;

int main() {
	MainMenu();
	Setup();
	Draw();
	Input();
	Logic();
}