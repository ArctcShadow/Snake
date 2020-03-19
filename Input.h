#pragma once
#include<iostream>
#include <conio.h>

using namespace std;


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