#include "account.h"
#include "Menu.h"
#include "Product.h"
#include "Whole_support.h"

#ifndef SHOWMAIN_MENU_H
#define SHOWMAIN_MENU_H
void showMain_menu()
{
    system("cls") ;
    menu m;
    m.main_menu() ;
}
#endif