#include"mytank.h"
#include"mybullut.h"
#include"TANK.h"
using namespace std;
void mytank::putdir(string s) {
	dir = s;
}
void mytank::drawmytank(int style) {
    fillrectangle(m_x - 4, m_y - 4, m_x + 4, m_y + 4);

    if (style == 1)
    {
        fillrectangle(m_x - 8, m_y - 6, m_x - 6, m_y + 6);
        fillrectangle(m_x + 6, m_y - 6, m_x + 8, m_y + 6);
    }
    else
    {
        fillrectangle(m_x - 6, m_y - 8, m_x + 6, m_y - 6);
        fillrectangle(m_x - 6, m_y + 6, m_x + 6, m_y + 8);
    }
}
void mytank::display() {
    COLORREF now_color = getfillcolor();
    setfillcolor(m_color);
    if (dir == "UP") {
        drawmytank(1);
        line(m_x, m_y, m_x, m_y - 10);
    }
    else if (dir == "DOWN") {
        drawmytank(1);
        line(m_x, m_y, m_x, m_y + 10);
    }
    else if (dir == "LEFT") {
        drawmytank(0);
        line(m_x, m_y, m_x - 10, m_y);
    }
    else if (dir == "RIGHT") {
        drawmytank(0);
        line(m_x, m_y, m_x + 10, m_y);
    }
    setfillcolor(now_color);
}
void mytank::move() {
    if (dir == "UP") {
        m_y -= m_speed;
        if (m_y < 0)
            m_y = GRA::get_height() - 1;
    }
    else if (dir == "DOWN") {
        m_y += m_speed;
        if (m_y > GRA::get_height())
            m_y = 1;
    }
    else if (dir == "LEFT") {
        m_x -= m_speed;
        if (m_x < 0) {
            m_x = GRA::get_width() - 1;
        }
    }
    else if (dir == "RIGHT") {
        m_x += m_speed;
        if (m_x > GRA::get_width()) {
            m_x = 1;
        }
    }
}
void mytank::shoot(list<bullut*>&el) {
   
    bullut* p = new bullut(this->m_x, this->m_y, (this->m_speed) * 5, this->m_color,this->dir);
    
    
 
    
    el.push_back(p);
}