#include <iostream>
#include <fstream>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>
#include <Windows.h>
using namespace std;

#ifndef WHOLE_SUPPORT_H
#define WHOLE_SUPPORT_H
COORD coord = {0, 0};
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct date
{
    int da_day,da_mon,da_year;
};

void getdate(date d)
{
	system("pause");
	cout<<"please enter day";
	cin>>d.da_day>>d.da_mon>>d.da_year;
}
#endif