#pragma warning(disable:4996)
#pragma comment(lib,"Winmm.lib")
#include <iostream>
#include <conio.h>
#include <time.h>
#include<list>
#include<Windows.h>
#include<stdlib.h>
#include"mybullut.h"
#include"enemytank.h"
#include"mytank.h"
#include"gra.h"
#include"judge.h"
#include"data.h"
using namespace std;
 
void readfile() {
    freopen("d://data.txt", "r+", stdin);
    cin >> k >> myready_hp >> mylevel >> money>>sotank.eraharm;
}
void writefile() {
    freopen("d://data.txt", "w+", stdout);
    cout << k << myready_hp << mylevel << money<<sotank.eraharm;
}
void load_test();
void market() {
    settextcolor(BLACK);
    setfillcolor(RED);
    settextstyle(24, 0, _T("黑体"));


    fillrectangle(100, 100, 270, 150);
    TCHAR s[] = _T("金钱数量");
    outtextxy(137,113,s);
    TCHAR number[20];
    _stprintf(number, _T("%d"), money);
    outtextxy(300, 113, number);

    fillrectangle(100, 200, 270, 250);
    TCHAR s1[] = _T("购买血量");
    outtextxy(137, 213, s1);
    TCHAR hp_cost[20];
    int hp_money = 10 + ((int)mylevel - 1) * 2;
    _stprintf(hp_cost, _T("%d"), hp_money);
    outtextxy(300, 213, hp_cost);

    
    fillrectangle(100, 300, 270, 350);
    TCHAR s2[] = _T("提升等级");
    outtextxy(137, 313, s2);
    TCHAR level_cost[20];
    int level_money = 25 + ((int)mylevel - 1) * 3;
    _stprintf(level_cost, _T("%d"), level_money);
    outtextxy(300, 313, level_cost);


    fillrectangle(100, 400, 270, 450);
    TCHAR s3[] = _T("提升伤害");
    outtextxy(137, 413, s3);
    TCHAR harm_cost[20];
    int harm_money = 10 + ((int)mylevel - 1) * 2;
    _stprintf(harm_cost, _T("%d"), harm_money);
    outtextxy(300, 413, harm_cost);


    fillrectangle(100, 500, 270, 550);
    TCHAR s4[] = _T("提升速度");
    outtextxy(137, 513, s4);
    TCHAR speed_cost[20];
    int speed_money = 10 + ((int)mylevel - 1) * 2;
    _stprintf(speed_cost, _T("%d"), speed_money);
    outtextxy(300, 513, speed_cost);


    MOUSEMSG m;
    while (1)
    {
         
        int sign = 0;
        m = GetMouseMsg();
        switch (m.uMsg)
        {
            
            case WM_LBUTTONDOWN:
                sign = 1;
                if (m.x > 100 && m.x < 270 && m.y>200 && m.y < 250) {
                    //hp
                    if (money >= hp_money) {
                        sotank.hp += 5;
                        money -= hp_money;
                    }
                    else
                    {
                        outtextxy(407, 505, _T("金钱不足"));
                    }
                 
                }
                else if (m.x > 100 && m.x < 270 && m.y>300 && m.y < 350) {
                    //level
                    if (money >= level_money)
                    {
                        sotank.hp += 5;
                        sotank.m_speed += 0.05;
                        sotank.eraharm += 2;
                        mylevel++;
                        money -= level_money;
                    }
                    else {
                        outtextxy(407, 505, _T("金钱不足"));
                    }
                }
                else if (m.x > 100 && m.x < 270 && m.y>400 && m.y < 450) {
                    //harm
                    if (money >= harm_money) {
                        sotank.eraharm += 2;
                        money -= harm_money;
                    }
                    else {
                        outtextxy(407, 505, _T("金钱不足"));
                    }
                }
                else if (m.x > 100 && m.x < 270 && m.y>500 && m.y < 550) {
                    //speed
                    if (money >= speed_money) {
                        sotank.m_speed += 0.02;
                        money -= speed_money;

                    }
                    else {
                        outtextxy(407, 505, _T("金钱不足"));
                    }
                     
                }
            
                break;
            default:
                break;
        }
        if(sign==1)break;
    }
     
}
void work() {
         
        bu.clear();
	    sotank.dir;
        
        mciSendString(_T("open background.mp3 alias mymusic") , NULL, 0, NULL);
         

        bool loop = true;
        bool skip = false;
        while (loop)
        {
            mciSendString(_T("play mymusic"), NULL, 0, NULL);
            if (kbhit())
            {
                int key = getch();

                switch (key)
                {
                    // Up
                case 72:
                    sotank.putdir("UP");
                    break;
                    // Down
                case 80:
                    sotank.putdir("DOWN");
                    break;
                    // Left
                case 75:
                    sotank.putdir("LEFT");
                    break;
                    // Right
                case 77:
                    sotank.putdir("RIGHT");
                    break;
                case 224: // 方向键高8位
                    break;
                    // Esc
                case 27:
                    mciSendString(_T("stop mymusic"), NULL, 0, NULL);
                    settextcolor(RGB(0, 0, 0));
                    settextstyle(48, 0, _T("黑体"));
                    rectangle(407, 505, 575, 551);
                    outtextxy(407, 404, _T("存  档"));
                    outtextxy(407, 505, _T("点此退出"));
                    outtextxy(407, 606, _T("进入商店"));
                    MOUSEMSG m;
                    while (1)
                    {
                        int sign = 0;
                        m = GetMouseMsg();
                        switch (m.uMsg)
                        {
                        case WM_LBUTTONDOWN:
                            if (m.x > 407 && m.x < 575 && m.y>505 && m.y < 551) {
   //                           
                                cleardevice();
 //                               return 1;
                                load_test();
                            }
                            else if (m.x > 407 && m.x < 575 && m.y>606 && m.y < 652) {
                                cleardevice();
                                market();
                                 
                            }
                            else if (m.x > 407 && m.x < 575 && m.y>405 && m.y < 452) {
                                writefile();
                                sign = 1;
                            }
                            else sign = 1;
                            break;
                        default:
                            break;
                        }
                        if (sign == 1)break;
                    }
 //                   loop = false;
                    break;
                    // Space
                case 32:
                    mciSendString(_T("stop mymusic"), NULL, 0, NULL);
                    if (skip)
                        skip = false;
                    else
                        skip = true;
                    break;
                
                    // Enter
                case 13:
                    if(bu.size()<=5)
                    sotank.shoot(bu);
 //                   enemy.shoot(enbu);
 //                   Sleep(10);
                    break;
                default:
                    break;
                }
            }
             
            if (!skip)
            {
                cleardevice();
                settextstyle(12, 0, _T("黑体"));

                outtextxy(20, 105, _T("LV:"));
                TCHAR slv[10];
                _stprintf(slv, _T("%d"), level);
                outtextxy(40, 105, slv);


                outtextxy(20, 135, _T("LV:"));
                TCHAR slv1[10];
                _stprintf(slv1, _T("%d"), mylevel);
                outtextxy(40, 135, slv1);


                setfillcolor(LIGHTGRAY);
                fillrectangle(50, 100, 50 + ready_hp * 2, 120);
                fillrectangle(50, 130, 50 + ready_hp * 2, 150);
                
                setfillcolor(WHITE);
                fillrectangle(50, 100, 50+enemy.hp*2, 120);

                
                
                
                setfillcolor(RED);
                fillrectangle(50, 130, 50 + sotank.hp * 2, 150);
                sotank.move();
                sotank.display();
                enemy.move();
                enemy.display();
                srand((unsigned)time(NULL));
                int tmp = rand() % 200+1;
                k++;
                if(k==tmp||k==200) 
                {
                    enemy.shoot(enbu);
                    k = 0;
                }
                
                    
                for (list<bullut*>::iterator it = bu.begin();it!=bu.end(); )
                {
                    
                    
                    (*it)->move();
                    //子弹命中
                    if (cal_dis(it, enemy)) {
                        IMAGE loadImg;
                        loadimage(&loadImg, _T("D:\\2.png"), 20, 20);
                        putimage(enemy.e_x-7, enemy.e_y-7, &loadImg);
                        enemy.hp -= ((*it)->harm+sotank.eraharm);
                        //当前坦克被击败
                        if (enemy.hp <= 0) {
                            money += 5;
                            settextcolor(RGB(0, 0, 0));
                            settextstyle(48, 0, _T("黑体"));
//                            rectangle(407, 505, 575, 551);
                            outtextxy(207, 505, _T("敌方坦克升级，按任意键继续"));
                            while (1)
                            {
                                int sign = 0;
                                MOUSEMSG m;
                                m = GetMouseMsg();
                                switch (m.uMsg)
                                {
                                case WM_LBUTTONDOWN:
                                    sign = 1;
                                    break;
                                default:
                                    break;
                                }
                                if (sign == 1)break;
                            }
                            level++;
                            enemy.eraharm += 2;
                            enemy.hp = 50+(level-1.0)*10;
                            enemy.e_speed += (level-1.0)*0.1 ;
                        }
                    }
//                    (*it)->b_live = 0;
                    if ((*it)->b_live == 0) {
                        delete *it;
                        it=bu.erase(it);
                        continue;
                    }
                    (*it)->display();
 //                   (*it)->display();
                    it++;
                }
                
                for (list<bullut*>::iterator it = enbu.begin(); it != enbu.end(); )
                {


                    (*it)->move();
                    //子弹命中
                    if (cal_dis(it, sotank)) {

                        IMAGE loadImg;
                        loadimage(&loadImg, _T("D:\\2.png"), 20, 20);
                        putimage(sotank.m_x - 7, sotank.m_y - 7, &loadImg);
                        sotank.hp -= ((*it)->harm+enemy.eraharm);
                        
 //                       system("pause");
                         
                        if (sotank.hp <= 0) {
                            settextstyle(48, 0, _T("黑体"));
                            outtextxy(207, 505, _T("你已被击败"));
                            while (1)
                            {
                                int sign = 0;
                                MOUSEMSG m;
                                m = GetMouseMsg();
                                switch (m.uMsg)
                                {
                                case WM_LBUTTONDOWN:
                                    sign = 1;
                                    break;
                                default:
                                    break;
                                }
                                if (sign == 1)break;
                            }
                            sotank.hp = myready_hp;
                            load_test();
                        }
                        
                    }
                    //                    (*it)->b_live = 0;
                    if ((*it)->b_live == 0) {
                        delete* it;
                        it = enbu.erase(it);
                        continue;
                    }
                    (*it)->display();
                    //                   (*it)->display();
                    it++;
                }
                
 //                   bu.clear();
            }

            Sleep(10);
        }

}
void load_test() {
    int GRA_load_return_val = 0, work_return_val = 0;
    GRA_load_return_val = GRA::load();
    if (GRA_load_return_val == 1)
    {
        work();
    }
    else if (GRA_load_return_val == 2) {
        GRA::destory();

    }
    else if(GRA_load_return_val == 3) {
        readfile();
        cleardevice();
        load_test();
    }
}
int main() {
    
	GRA::creat();
    /*
    int GRA_load_return_val=0,work_return_val=0;
    GRA_load_return_val = GRA::load();
    if (GRA_load_return_val == 1)
    {
        work();
    }
    else if (GRA_load_return_val == 2) {
        GRA::destory();
        
    }
    */
    load_test();
    GRA::destory();
    return 0;
}