#include"mybullut.h"
#include"mytank.h"
#include"judge.h"
#include<string>
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<list>

using namespace std;


void bullut::creat() {
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();
	setfillcolor(b_color);
	setcolor(b_color);
//	cout << b_x << b_y << endl;
//	fillcircle(b_x+10, b_y+10, 10);
	Sleep(100);
	setcolor(color_save);
	setfillcolor(fill_color_save);
}
void bullut::drawmybullut() {
	solidcircle(b_x, b_y, 3);
	/*
	Sleep(100);
	clearcircle(b_x, b_y, 3);*/
}
void bullut::display() {
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();
	setfillcolor(b_color);
	setcolor(b_color);
	drawmybullut();
	setcolor(color_save);
	setfillcolor(fill_color_save);
}
void bullut::move() {
	if (b_dir == "UP") {
		b_y -= b_speed;
		if (b_y <= 5)b_live = 0;
	}
	else if (b_dir == "DOWN") {
		b_y += b_speed;
		if (b_y > GRA::get_height()-5) {
			b_live = 0;
		}
	}
	else if (b_dir == "LEFT") {
		b_x -= b_speed;
		if (b_x < 5) {
			b_live = 0;
		}
	}
	else if (b_dir == "RIGHT") {
		b_x += b_speed;
		if (b_x > GRA::get_width()-5) {
			b_live = 0;
		}
	}
}