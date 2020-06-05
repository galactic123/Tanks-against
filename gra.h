#pragma once
#include<easyx.h>

#include<graphics.h>
#include<Windows.h>
#include<iostream>
using namespace std;
#define GRA_wideth 1024
#define GRA_height 768
class GRA
{
public:
	static void creat();
	static int load();
	static void destory();
	static int get_width();
	static int get_height();

private:
	static int width, height;
};