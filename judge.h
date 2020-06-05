#pragma once
#include"enemytank.h"
#include"mybullut.h"
#include"mytank.h"
#include<iostream>
using namespace std;
bool cal_dis(list<bullut*>::iterator it,enemytank &en);
bool cal_dis(list<bullut*>::iterator it, mytank& en);