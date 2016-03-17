#include "ShowClient.h"
#include "ShowMain_menu.h"

void help(void)
{
	char ch;
	ifstream fin;
    fin.open("help.txt");
    if(!fin)
    {
        cout<<"Error in Opening! File Not Found!!"<<endl;
        return;
    }
    cout<<"\n****Help****"<<endl;
    while(fin.get(ch))
    {
        cout<<ch;
    }
    fin.close();
}

void selections(void)
{
    system("cls") ;
    char ch ;
    while (1)
    {
        system("cls") ;
        gotoxy(10,3) ;
        cout
                <<"*************************************************************" ;
        gotoxy(10,23) ;
        cout
                <<"*************************************************************" ;
        gotoxy(28,6) ;
        cout <<"WELCOME to Shop Management System!!" ;
        gotoxy(28,7) ;
        cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
        gotoxy(30,9) ;
        cout <<"1: Sales" ;
        gotoxy(30,11) ;
        cout <<"2: Clients Information" ;
        gotoxy(30,13) ;
        cout <<"3: Help" ;
        gotoxy(30,17) ;
        cout <<"0: QUIT" ;
        gotoxy(30,20) ;
        cout <<"Enter Your Choice : " ;
        ch = getche() ;
        if (ch == '1')
        {
            showMain_menu();
        }
        else if (ch == '2')
        {
            showClients();
        }
        else if (ch == '3')
            help() ;
        else if (ch == '0')
            break ;
    }
}

void main(void)
{
    system("cls") ;
    selections() ;
}
