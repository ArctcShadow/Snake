#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <vector>
#include <conio.h>


using namespace std;
class Snake {

public:

	void TestFunc() {
		for (int i = 0; i <= 5; i++)
			tailX.push_back(i);

		cout << endl;

		tailX.insert(tailX.begin(), 100);
		for (int i = 0; i < tailX.size(); i++) {
			cout << tailX[i] << " ";
		}
	}

	Snake() {

		delay = 100;
		dx = 0;
		dy = 1;
		x = 6;
		y = 25;
		applexCOORD = 1;
		appleyCOORD = 1;
		tail = 3;
		points = 0;
		isRunning = true;
		eat = false;
	}


	void Begin() {

		map = new char* [26];

		for (int i = 0; i < 26; i++) {
			map[i] = new char[81];

		}
		Draw();
	}

	void Draw() {

		for (int j = 1; j <= 80; j++) {
			map[1][j] = char(178);
			map[25][j] = char(178);
		}
		for (int i = 1; i <= 25; i++) {
			map[i][1] = char(178);
			map[i][80] = char(178);
		}
		for (int i = 2; i <= 24; i++) {
			for (int j = 2; j <= 79; j++) {
				map[i][j] = ' ';
			}
		}
		map[x][y] = char(254);
		for (int i = 22; i <= 24; i++) {
			tailY.push_back(i);
		}
		for (int i = 0; i < tail; i++) {
			tailX.push_back(x);
		}
		for (int i = 0; i < tail; i++) {
			map[tailX[i]][tailY[i]] = 'o';
		}
		for (int i = 1; i <= 25; i++) {
			for (int j = 1; j <= 80; j++) {
				if (j == 40)
					cout << map[i][j] << endl;
				else
					cout << map[i][j];
			}
		}
		Fruit();
		GameLogic();
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

	void Fruit() {
		srand((unsigned)time(NULL));
		applexCOORD = 2 + rand() % (24 - 2 + 1);
		appleyCOORD = 2 + rand() % (79 - 2 + 1);
		map[applexCOORD][appleyCOORD] = 'o';
	}

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

	void EndGame() {
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
				Fruit();

				
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
				EndGame();	
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

	void KeyListener() {
		if (_kbhit()) {
			char in = _getch();
			switch (in) {
			case 'd':
			{ 

				dx = 0;
				dy = 1;
				break;
			}
			case 'w':
			{
				dx = -1;
				dy = 0;
				break;
			}
			case 'a':
			{
				dx = 0;
				dy = -1;
				break;
			}
			case 's':
			{
				dx = 1;
				dy = 0;
				break;
			}
			}
		}
	}





private: 
	
	
	int x, y;
	int tail;
	 
	int applexCOORD, appleyCOORD;
	int dx, dy;
	int prevPositionX, prevPositionY;
	int points;
	int delay;
	bool isRunning, eat;


	char** map;


	vector<int> tailX;
	vector<int> tailY;
	
	
	};