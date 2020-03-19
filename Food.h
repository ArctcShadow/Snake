#pragma once
#include<iostream>
#include "Setup.h"
#include <ctime>
using namespace std;

class Food {
public:

	void Fruit() {
		srand((unsigned)time(NULL));
		applexCOORD = 2 + rand() % (24 - 2 + 1);
		appleyCOORD = 2 + rand() % (79 - 2 + 1);
		map[applexCOORD][appleyCOORD] = 'o';
	}


};