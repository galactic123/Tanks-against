#include"enemytank.h"
#include"mybullut.h"
#include<easyx.h>
#include<ctime>
#include<list>
#include<iostream>
using namespace std;
void enemytank::putdir(string s) {
//    endir = s;
}
void enemytank::drawmytank(int style) {
    fillrectangle(e_x- 4, e_y - 4, e_x + 4, e_y + 4);

    if (style == 1)
    {
        fillrectangle(e_x - 8, e_y - 6, e_x - 6, e_y + 6);
        fillrectangle(e_x + 6, e_y - 6, e_x + 8, e_y + 6);
    }
    else
    {
        fillrectangle(e_x - 6, e_y - 8, e_x + 6, e_y - 6);
        fillrectangle(e_x - 6, e_y + 6, e_x + 6, e_y + 8);
    }
}

string enemytank::randowturn()
{
    srand((unsigned)time(NULL));
    string enenyturn;
    int now=rand()%100;
    if (now<=10) {
        enenyturn = "UP";
        return enenyturn;
    }
    else if (now > 10 && now <= 20) {
        enenyturn = "DOWN";
        return enenyturn;
    }
    else if (now > 20 && now <= 30) {
        enenyturn = "LEFT";
        return enenyturn;
    }
    else if (now > 30 && now <= 40) {
        enenyturn = "RIGHT";
        return enenyturn;
    }
    else
    {
        enenyturn = "NULL";
        return enenyturn;
    }
}
void enemytank::display() {
    COLORREF now_color = getfillcolor();
    
    string tmp = randowturn();
    if (tmp != "NULL") {
        endir = tmp;
    }
    else {
        
    }
//    else endir = lastdir;
    setfillcolor(WHITE);
    if (endir == "UP") {
        enemytank::drawmytank(1);
        line(e_x, e_y, e_x, e_y - 10);
    }
    else if (endir == "DOWN") {
        enemytank::drawmytank(1);
        line(e_x, e_y, e_x, e_y + 10);
    }
    else if (endir == "LEFT") {
        enemytank::drawmytank(0);
        line(e_x, e_y, e_x-10, e_y );
    }
    else if (endir == "RIGHT") {
        enemytank::drawmytank(0);
        line(e_x, e_y, e_x+10, e_y );
    }
    setfillcolor(now_color);
//    lastdir = endir;
}
void enemytank::move() {
    if (endir == "UP") {
        e_y -= e_speed;
        if (e_y < 0)
            e_y = GRA::get_height() - 1;
    }
    else if (endir == "DOWN") {
        e_y += e_speed;
        if (e_y > GRA::get_height())
            e_y = 1;
    }
    else if (endir == "LEFT") {
        e_x -= e_speed;
        if (e_x < 0) {
            e_x = GRA::get_width() - 1;
        }
    }
    else if (endir == "RIGHT") {
        e_x += e_speed;
        if (e_x > GRA::get_width()) {
            e_x = 1;
        }
    }

}
void enemytank::shoot(list<bullut*>&el) {
    e_color = WHITE;
    bullut*p= new bullut(this->e_x,this->e_y,(this->e_speed)*7,this->e_color,this->endir);
    
    el.push_back(p);
}