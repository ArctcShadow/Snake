#pragma once
#include <iostream>
#include "Logic.h"
#include "Setup.h"
#include "Food.h"

using namespace std;

class Map {

public:
	

	void Draw() {

		for (int j = 1; j <= 80; j++) {
			map[1][j] = char(160);
			map[20][j] = char(160);
		}
		for (int i = 1; i <= 20; i++) {
			map[i][1] = char(160);
			map[i][80] = char(160);
		}
		for (int i = 2; i <= 20; i++) {
			for (int j = 2; j <= 79; j++) {
				map[i][j] = ' ';
			}
		}
		map[x][y] = char(254);
		for (int i = 22; i <= 29; i++) {
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
		Food f;
		Logic l;
		
		f.Fruit();
		l.GameLogic();

	}


};