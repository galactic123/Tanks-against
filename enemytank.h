#pragma once
#include"TANK.h"
#include<iostream>
using namespace std;
class enemytank :public tank
{
public:
	string endir;
	string lastdir;
	double e_x, e_y;
	COLORREF e_color;
	double e_speed;
	enemytank() {
		e_x = 500;
		e_y = 500;
		e_color = WHITE;
		endir = "LEFT";
		lastdir = "LEFT";
		e_speed = 0.2;
	}
	~enemytank() {

	}
	void putdir(string s);
	void display();
	void move();
	void drawmytank(int style);
	string randowturn();
	void shoot(list<bullut* >& el);
private:

};

