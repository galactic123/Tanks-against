#include"judge.h"
using namespace std;
bool cal_dis(list<bullut*>::iterator it, enemytank& en)
{
	double dx = abs((*it)->b_x - en.e_x);
	double dy = abs((*it)->b_y - en.e_y);
	double ds = sqrt((double)(dx * dx + dy * dy));
	if (ds <= 5)return 1;
	else 
		return 0;
}
bool cal_dis(list<bullut*>::iterator it, mytank& en) {
	double dx = abs((*it)->b_x - en.m_x);
	double dy = abs((*it)->b_y - en.m_y);
	double ds = sqrt((double)(dx * dx + dy * dy));
	if (ds <= 5.0)return 1;
	else
		return 0;
}