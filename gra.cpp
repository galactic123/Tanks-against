#include"gra.h"
#include<graphics.h>

using namespace std;
int GRA::height = GRA_height;
int GRA::width = GRA_wideth;
void  GRA::creat() {
	initgraph(GRA::width, GRA::height);
	setbkcolor(LIGHTGRAY);
}
int GRA::load() {
	IMAGE loadImg;
	loadimage(&loadImg, _T("D:\\timg.jpg"), 1024, 768);
	putimage(0, 0, &loadImg);
	settextcolor(RGB(0, 0, 0));
	settextstyle(48, 0, _T("黑体"));
	rectangle(407, 605, 575, 651);                         
	rectangle(407, 655, 595, 701);
	outtextxy(407, 605, _T("开始游戏"));
	outtextxy(407, 655, _T("退出游戏"));
	outtextxy(407, 555, _T("读取存档"));

	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
			case WM_LBUTTONDOWN:
				if (m.x > 407 && m.x < 575 && m.y>605 && m.y < 651) {
					return 1;
				}
				
				if (m.x > 407 && m.x < 595 && m.y>655 && m.y < 701) {
					exit(0);
					return 2;
					
				}
				if (m.x > 407 && m.x < 595 && m.y>555 && m.y < 601)
				{
					return 3;
				}

			default:
				break;
		}	
	}
	
}
void GRA::destory(){
	closegraph();
}
int GRA::get_height() {
	return GRA::height;
}
int GRA::get_width() {
	return GRA::width;
}
 