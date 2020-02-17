#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include "Menu.h"

using namespace std;

bool GameOver;
const int width = 30;
const int height = 15;
int x, y, fruitX, fruitY, fruit2X, fruit2Y, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, UP, DOWN, RIGHT, LEFT, EXIT };
eDirection dir;


void Setup() {
	GameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width - 1;
	fruitY = rand() % height - 1;
	score = 0;
}

void Draw() {
	system("cls");
	for (int i = 0; i < width + 1; i++)
		cout << (char)254u;
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1)
				cout << (char)254u;
			if (i == y && j == x)
				cout << "0";
			else if (i == fruit2Y && j == fruit2X) {
				cout << "f";
			}
			else if (i == fruitY && j == fruitX) {
				cout << "F";
			}
			else; {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						print = true;
						cout << "o";
					}
				}
				if (!print)
					cout << " "; }
		}
		cout << endl;
	}

	for (int i = 0; i < width + 1; i++)
		cout << (char)254u;
	cout << endl;
	cout << "Score: " << score << endl;
}

void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case's':
			dir = DOWN;
			break;
		case'x':
			system("cls");
			GameOver = true;
			break;
		}
	}
}

void Logic() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
	case LEFT:
		x--;
		Sleep(10);
		break;
	case RIGHT:
		x++;
		Sleep(10);
		break;
	case UP:
		y--;
		Sleep(10);
		break;
	case DOWN:
		y++;
		Sleep(10);
		break;
	}
	if (x >= width)
		x = 0;
	else if (x < 0)
		x = width - 1;
	if (y >= height)
		y = 0;
	else if (y < 0)
		y = height - 1;

	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == x && tailY[i] == y)
			GameOver = true;
	}

	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % width - 1;
		fruitY = rand() % height - 1;
		nTail++;
	}
	if (x == fruit2X && y == fruit2Y) {
		score += 5;
		fruit2X = rand() % width - 1;
		fruit2Y = rand() % height - 1;
	}
}
