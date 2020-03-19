#pragma once

#include <iostream>
#include<vector>
using namespace std;




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

void setup() {

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
