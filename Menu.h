#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include "Game.h"

using namespace std;

int option;


void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

void MainMenu() {
	string logotext1 = "                      .-=-.          .--.";
	string logotext2 = "                      /      '.      /  '_)";
	string logotext3 = "  _     .'  '.    /   .-.   |    /  /";
	string logotext4 = " ( \   / .-.  \   /   /   |   \   /  /";
	string logotext5 = " \ `-` /   \  `-'   /     \   `-`  /";
	string logotext6 = "`-.-`    '.____.'      `.____.'";
	string menutext1 = "1. New game";
	string menutext2 = "2. Check my scores";
	string menutext3 = "3. Show controls";
	string menutext4 = "4. Exit";

	SetColor(2, 0);
	cout << setw(40 + logotext1.length() / 2) << logotext1 << endl;
	cout << setw(40 + logotext2.length() / 2) << logotext2 << endl;
	cout << setw(40 + logotext3.length() / 2) << logotext3 << endl;
	cout << setw(40 + logotext4.length() / 2) << logotext4 << endl;
	cout << setw(40 + logotext5.length() / 2) << logotext5 << endl;
	cout << setw(40 + logotext6.length() / 2) << logotext6 << endl;
	cout << endl;
	SetColor(15, 0);
	cout << setw(40 + menutext1.length() / 2) << menutext1 << endl;
	cout << setw(40 + menutext2.length() / 2) << menutext2 << endl;
	cout << setw(40 + menutext3.length() / 2) << menutext3 << endl;
	cout << setw(40 + menutext4.length() / 2) << menutext4 << endl;
	cout << "Enter option : ";
	cin >> option;
	if (option == 1) {
		Setup();


		while (!GameOver) {
			Draw();
			Input();
			Logic();
		}
		if (GameOver = true) {
			system("cls");
			cout << endl;
			string text1 = "##########################################################";
			string text2 = "####################### GAME OVER ########################";
			string text3 = "##########################################################";
			cout << setw(40 + text1.length() / 2) << text1 << endl;
			cout << setw(40 + text2.length() / 2) << text2 << endl;
			cout << setw(40 + text3.length() / 2) << text3 << endl;
			cout << endl;
			string text4 = "Your score is";
			cout << setw(40 + text4.length() / 2) << text4 << ": " << score << endl;
			cout << endl;
			string text5 = "Good luck next time :)";
			cout << setw(40 + text5.length() / 2) << text5 << endl;

			string path = "Records.txt";
			ofstream fout;

			fout.open(path, ofstream::app);
			fout << score << endl;
			fout.close();

			cout << endl;
			Sleep(1700);
			system("cls");
		}
	}
	if (option == 2) {
		system("cls");
		string path = "Records.txt";
		ifstream fin;
		fin.open(path);
		char ch;
		while (fin.get(ch)) {
			cout << ch;
		}
		fin.close();
		Sleep(1700);
		system("cls");
		MainMenu();
	}
	if (option == 3) {
		system("cls");
		cout << "w - UP" << endl;
		cout << "a - LEFT" << endl;
		cout << "s - DOWN" << endl;
		cout << "d - RIGHT" << endl;
		cout << "x - QUIT" << endl;
		Sleep(1700);
		system("cls");
		MainMenu();
	}
}

