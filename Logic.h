#pragma once
#include <iostream>
#include"Setup.h"
#include<windows.h>
#include "Food.h"
#include "Input.h"
#include <conio.h>
#include "Map.h"

using namespace std;

class Logic {

public:

	int CheckBorders() {
		if ((x == 1) || (x == 25) || (y == 1) || (y == 80)) {
			return 1;
		}
		for (int i = 0; i < tail - 1; i++) {
			if ((tailX[i] == x) && (tailY[i] == y))
				return 1;
		}
		return 0;
	}

	void GG() {
		system("cls");
		Sleep(1000);
		cout << "Game Over :(" << endl;
		Sleep(50);
		cout << "You earned " << points << " points" << endl;
	}

	void GameLogic() {

		while (isRunning == true) {

			if (_kbhit()) {
				KeyListener();
			}
			cout << endl;
			prevPositionX = x;
			prevPositionY = y;
			x = x + dx;
			y = y + dy;

			if ((x == applexCOORD) && (y == appleyCOORD)) {
				points = points + 10;
				eat = true;
				map[applexCOORD][appleyCOORD] = ' ';
				Food f;
				f.Fruit();


			}
			if (eat == true) {
				tail++;
				tailX.insert(tailX.begin(), tailX[0]);
				tailY.insert(tailY.begin(), tailY[0]);
				eat = false;
			}
			map[tailX[0]][tailY[0]] = ' ';
			for (int i = 0; i < tail - 1; i++) {
				tailX[i] = tailX[i + 1];
				tailY[i] = tailY[i + 1];
			}
			tailX[tail - 1] = prevPositionX;
			tailY[tail - 1] = prevPositionY;
			if (CheckBorders()) {
				GG();
				isRunning = false;
				break;
			}
			if (points > 50 && points <= 100) {
				delay = 75;
			}
			else if (points > 100 && points <= 150) {
				delay = 50;
			}
			else if (points > 150) {
				delay = 25;
			}
			Sleep(delay);


			system("cls");
			Refresher();
		}
	}
	void Refresher() {

		map[x][y] = char(254);
		for (int i = 0; i < tail; i++) {
			map[tailX[i]][tailY[i]] = 'o';
		}
		for (int i = 1; i <= 25; i++) {
			for (int j = 1; j <= 80; j++) {
				if (j == 80)
					cout << map[i][j] << endl;
				else
					cout << map[i][j];
			}
		}

	}

	void Begin() {

		map = new char* [26];

		for (int i = 0; i < 26; i++) {
			map[i] = new char[81];

		}
		Map m;
		m.Draw();
	}


};