#pragma once
#include<iostream>
//#include"mytank.h"
//#include"enemytank.h"
#include<easyx.h>
#include<list>
using namespace std;
class bullut {
public:
	bullut(int x, int y,int speed,COLORREF so,string nowdir) {
		bullut::b_x = x;
		bullut::b_y = y;
		bullut::b_color = so;
		bullut::b_dir = nowdir;
		bullut::b_speed = speed;
	}
/*	bullut(mytank& a) {
		bullut::b_x = a.m_x;
		bullut::b_y = a.m_y;
		b_color = a.m_color;
		b_speed = a.m_speed * 5;
		b_dir = a.dir;
		b_live = 1;
	};
	bullut(enemytank& a) {
		bullut::b_x = a.e_x;
		bullut::b_y = a.e_y;
		b_color = a.m_color;
		b_speed = a.e_speed * 5;
		b_dir = a.endir;
		b_live = 1;
	};*/
	
	void creat();
	void drawmybullut();	
	void display();
	void move();
	void destory() {
		delete this;
	};
	double b_x, b_y;
	COLORREF b_color;
	string b_dir;
	double b_speed;
	bool b_live=1;
	int harm = 1;
};