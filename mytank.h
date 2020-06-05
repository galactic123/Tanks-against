#pragma once
#include"TANK.h"
using namespace std;
class mytank :public tank{
public:
	mytank() {
		m_x = 400;
		m_y = 300;
		m_color = RED;
		dir = "UP";
		m_speed = 0.4;
	}
	~mytank() {

	}

	void putdir(string s);
	void display();
	void move();
	void drawmytank(int style);
	void shoot(list<bullut*> &el);
};