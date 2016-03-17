#include "Whole_support.h"
#include "Product.h"

#ifndef MENU_H
#define MENU_H
class menu
{
public :
    void main_menu(void) ;
private :
    void edit_menu(void) ;
} ;

void menu :: main_menu(void)
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
        cout <<"S A L E S M A N A G E M E N T" ;
        gotoxy(28,7) ;
        cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
        gotoxy(30,9) ;
        cout <<"1: PURCHASE PRODUCTS" ;
        gotoxy(30,11) ;
        cout <<"2: LIST OF PRODUCTS" ;
        gotoxy(30,13) ;
        cout <<"3: EDIT PRODUCTS FILE" ;
        gotoxy(30,15) ;
        cout <<"4: BILLS REPORT" ;
        gotoxy(30,17) ;
        cout <<"0: QUIT" ;
        gotoxy(30,20) ;
        cout <<"Enter Your Choice : " ;
        ch = getche() ;
        if (ch == '1')
        {
            product p ;
            p.purchase() ;
        }
        else if (ch == '2')
        {
            product p ;
            p.list_of_item() ;
        }
        else if (ch == '3')
            edit_menu() ;
        else if (ch == '4')
        {
            account a ;
            a.bill_list();
        }
        else if (ch == '0')
            break ;
    }
}

void menu :: edit_menu(void)
{
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
        gotoxy(32,6) ;
        cout <<"E D I T M E N U" ;
        gotoxy(32,7) ;
        cout <<"~~~~~~~~~~~~~~~~" ;
        gotoxy(32,10) ;
        cout <<"1: ADD PRODUCTS" ;
        gotoxy(32,12) ;
        cout <<"2: MODIFY PRODUCTS" ;
        gotoxy(32,14) ;
        cout <<"3: DELETE PRODUCTS" ;
        gotoxy(32,16) ;
        cout <<"0: EXIT" ;
        gotoxy(32,19) ;
        cout <<"Enter Choice : " ;
        ch = getche() ;
        if (ch == '1')
        {
            product p ;
            p.add_item() ;
            break ;
        }
        else if (ch == '2')
        {
            product p ;
            p.modify_item() ;
            break ;
        }
        else if (ch == '3')
        {
            product p ;
            p.delete_item() ;
            break ;
        }
        else if (ch == '0')
            break ;
    }
}

#endif