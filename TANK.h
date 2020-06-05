#pragma once
#include"gra.h"
#include<iostream>
#include<string>
#include<easyx.h>
#include<Windows.h>
#include<list>
#include"mybullut.h"
using namespace std;
class tank {
public:
	virtual void display() = 0;
	virtual void move() = 0;
	virtual void shoot(list<bullut*> & el ) = 0;
	double m_x, m_y;
	COLORREF m_color;
	string dir;
	double m_speed;
	int hp = 50;
	int eraharm = 0;
};