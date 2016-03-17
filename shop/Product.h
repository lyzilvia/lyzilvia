#include "Whole_support.h"

#ifndef PRODUCT_H
#define PRODUCT_H
class product
{
public :
    void add_item(void) ;
    void delete_item(void) ;
    void modify_item(void) ;
    void list_of_item(void) ;
    void purchase(void) ;
private :
    int last_code(void) ;
    void delete_record(int) ;
    void modify_record(int) ;
    void display_record(int) ;
    int item_found(int) ;
    int recordno(int) ;
    void sort(void) ;

    int itemcode ;
    char itemname[30] ;
    float itemcost, itemprice ;
} ;

void product :: add_item(void)
{
    int tcode, valid ;
    char ch, t_itemcost[10], t_itemprice[10] ;
    tcode = last_code() ;
    tcode++ ;
    do
    {
        system("cls") ;
        gotoxy(71,2) ;
        cout <<"<0>=Exit" ;
        gotoxy(27,3) ;
        cout <<"ADDITION OF PRODUCTS" ;
        gotoxy(26,4) ;
        cout <<"********************" ;
        gotoxy(5,6) ;
        cout <<"Item Code : " <<tcode ;
        gotoxy(5,8) ;
        cout <<"Item Name : " ;
        gotoxy(5,10) ;
        cout <<"Item Cost : " ;
        gotoxy(5,12) ;
        cout <<"Item Price : " ;
        do
        {
            valid = 1 ;
            gotoxy(1,8) ;
            //clreol() ;
            gotoxy(1,24) ;
            //clreol() ;
            gotoxy(1,25) ;
            //clreol() ;
            gotoxy(3,25) ;
            cout <<"ENTER ITEM NAME TO ADD IN THE MENU" ;
            gotoxy(5,8) ;
            cout <<"Item Name : " ;
            gets(itemname) ;
            strupr(itemname) ;
            if (itemname[0] == '0')
                return ;
            if ((strlen(itemname) < 1) || (strlen(itemname) > 20))
            {
                valid = 0 ;
                gotoxy(3,24) ;
                cout <<"\7 Range = 1..20" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {
            valid = 1 ;
            gotoxy(1,10) ;
            //clreol() ;
            gotoxy(1,24) ;
            //clreol() ;
            gotoxy(1,25) ;
            //clreol() ;
            gotoxy(3,25) ;
            cout <<"ENTER ITEM COST TO ADD IN THE MENU" ;
            gotoxy(5,10) ;
            cout <<"Item Cost : " ;
            gets(t_itemcost) ;
            itemcost = atof(t_itemcost) ;
            if (t_itemcost[0] == '0')
                return ;
            if (itemcost < 1 || itemcost > 800)
            {
                valid = 0 ;
                gotoxy(3,24) ;
                cout <<"\7 Range = 1..800" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {
            valid = 1 ;
            gotoxy(1,12) ;
            //clreol() ;
            gotoxy(1,24) ;
            //clreol() ;
            gotoxy(1,25) ;
            //clreol() ;
            gotoxy(3,25) ;
            cout <<"ENTER ITEM PRICE TO ADD IN THE MENU" ;
            gotoxy(5,12) ;
            cout <<"Item Price : " ;
            gets(t_itemprice) ;
            itemprice = atof(t_itemprice) ;
            if (t_itemprice[0] == '0')
                return ;
            if (itemprice < itemcost || itemprice > 1000)
            {
                valid = 0 ;
                gotoxy(3,24) ;
                cout <<"\7 Range = " <<itemcost <<"..1000" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {
            gotoxy(1,15) ;
            //clreol() ;
            gotoxy(1,24) ;
            //clreol() ;
            gotoxy(1,25) ;
            //clreol() ;
            gotoxy(5,15) ;
            cout <<"Do you want to save this record (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
            if (ch == '0')
                return ;
        }
        while (ch != 'N' && ch != 'Y') ;
        if (ch == 'Y')
        {
            itemcode = tcode ;
            fstream file ;
            file.open("PRODUCT.DAT", ios::out | ios::app ) ;
            file.write((char *) this, sizeof(product)) ;
            file.close() ;
            tcode++ ;
        }
        do
        {
            gotoxy(1,17) ;
            //clreol() ;
            gotoxy(1,24) ;
            //clreol() ;
            gotoxy(1,25) ;
            //clreol() ;
            gotoxy(5,17) ;
            cout <<"Do you want to add more records (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
            if (ch == '0')
                return ;
        }
        while (ch != 'N' && ch != 'Y') ;
    }
    while (ch == 'Y') ;
}

void product :: display_record(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) this, sizeof(product)))
    {
        if (itemcode == tcode)
        {
            gotoxy(5,3) ;
            cout <<"Item Code : "<<itemcode ;
            gotoxy(5,4) ;
            cout <<"Item Name : "<<itemname ;
            gotoxy(5,5) ;
            cout <<"Item Cost : "<<itemcost ;
            gotoxy(5,6) ;
            cout <<"Item Price : "<<itemprice ;
            break ;
        }
    }
    file.close() ;
}

int product :: item_found(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(product)))
    {
        if (itemcode == tcode)
        {
            found++ ;
            break ;
        }
    }
    file.close() ;
    return found ;
}

int product :: recordno(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(product)))
    {
        found++ ;
        if (itemcode == tcode)
            break ;
    }
    file.close() ;
    return found ;
}

void product :: delete_record(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    fstream temp ;
    temp.open("temp.dat", ios::out) ;
    file.seekg(0,ios::beg) ;
    while ( !file.eof() )
    {
        file.read((char *) this, sizeof(product)) ;
        if ( file.eof() )
            break ;
        if ( itemcode != tcode )
            temp.write((char *) this, sizeof(product)) ;
    }
    file.close() ;
    temp.close() ;
    file.open("PRODUCT.DAT", ios::out) ;
    temp.open("temp.dat", ios::in) ;
    temp.seekg(0,ios::beg) ;
    while ( !temp.eof() )
    {
        temp.read((char *) this, sizeof(product)) ;
        if ( temp.eof() )
            break ;
        file.write((char *) this, sizeof(product)) ;
    }
    file.close() ;
    temp.close() ;
}

void product :: delete_item(void)
{
    system("cls") ;
    char t_code[5], ch ;
    int t, tcode ;
    gotoxy(3,25) ;
    cout <<"Press <ENTER> to see the list" ;
    gotoxy(5,3) ;
    cout <<"Enter Item Code of the item to be deleted : " ;
    gets(t_code) ;
    t = atoi(t_code) ;
    tcode = t ;
    if (t_code[0] == '0')
        return ;
    if (tcode == 0)
    {
        list_of_item() ;
        gotoxy(1,25) ;
        //clreol() ;
        gotoxy(3,25) ;
        cout <<"Press <ENTER> to Exit" ;
        gotoxy(5,24) ;
        cout <<"Enter Item Code of the item to be deleted : " ;
        gets(t_code) ;
        t = atoi(t_code) ;
        tcode = t ;
        if (tcode == 0)
            return ;
    }
    system("cls") ;
    if (!item_found(tcode))
    {
        gotoxy(5,5) ;
        cout <<"\7Record not found" ;
        getch() ;
        return ;
    }
    display_record(tcode) ;
    do
    {
        gotoxy(1,8) ;
        //clreol() ;
        gotoxy(5,8) ;
        cout <<"Do you want to delete this record (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
    }
    while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        return ;
    delete_record(tcode) ;
    gotoxy(5,15) ;
    cout <<"\7Record Deleted" ;
    getch() ;
}

void product :: modify_record(int tcode)
{
    int recno ;
    recno = recordno(tcode) ;
    int valid, t_code ;
    char ch, t_itemcost[10], t_itemprice[10], t_itemcode[5] ;
    gotoxy(71,2) ;
    cout <<"<0>=Exit" ;
    gotoxy(5,12) ;
    cout <<"Item Code : " ;
    gotoxy(5,14) ;
    cout <<"Item Name : " ;
    gotoxy(5,16) ;
    cout <<"Item Cost : " ;
    gotoxy(5,18) ;
    cout <<"Item Price : " ;
    do
    {
        gotoxy(20,12) ;
        //clreol() ;
        cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
        gotoxy(1,12) ;
        //clreol() ;
        gotoxy(1,24) ;
        //clreol() ;
        gotoxy(1,25) ;
        //clreol() ;
        gotoxy(3,25) ;
        cout <<"ENTER ITEM CODE TO ADD IN THE MENU" ;
        gotoxy(5,12) ;
        cout <<"Item Code : " ;
        gets(t_itemcode) ;
        t_code = atoi(t_itemcode) ;
        if (t_code == 0)
            return ;
        if (item_found(t_code) && t_code != tcode)
        {
            valid = 0 ;
            gotoxy(3,24) ;
            cout <<"\7 CODE ALREADY GIVEN" ;
            getch() ;
        }
    }
    do
    {
        gotoxy(20,14) ;
        //clreol() ;
        cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
        gotoxy(1,14) ;
        //clreol() ;
        gotoxy(1,24) ;
        //clreol() ;
        gotoxy(1,25) ;
        //clreol() ;
        gotoxy(3,25) ;
        cout <<"ENTER ITEM NAME TO ADD IN THE MENU" ;
        gotoxy(5,14) ;
        cout <<"Item Name : " ;
        gets(itemname) ;
        strupr(itemname) ;
        if (itemname[0] == '0')
            return ;
        if ((strlen(itemname) < 1) || (strlen(itemname) > 20))
        {
            valid = 0 ;
            gotoxy(3,24) ;
            cout <<"\7 Range = 1..20" ;
            getch() ;
        }
    }
    do
    {
        gotoxy(20,16) ;
        //clreol() ;
        cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
        gotoxy(1,16) ;
        //clreol() ;
        gotoxy(1,24) ;
        //clreol() ;
        gotoxy(1,25) ;
        //clreol() ;
        gotoxy(3,25) ;
        cout <<"ENTER ITEM COST TO ADD IN THE MENU" ;
        gotoxy(5,16) ;
        cout <<"Item Cost : " ;
        gets(t_itemcost) ;
        itemcost = atof(t_itemcost) ;
        if (t_itemcost[0] == '0')
            return ;
        if (itemcost < 1 || itemcost > 800)
        {
            valid = 0 ;
            gotoxy(3,24) ;
            cout <<"\7 Range = 1..800" ;
            getch() ;
        }
    }
    do
    {
        gotoxy(20,18) ;
        //clreol() ;
        cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
        gotoxy(1,18) ;
        //clreol() ;
        gotoxy(1,24) ;
        //clreol() ;
        gotoxy(1,25) ;
        //clreol() ;
        gotoxy(3,25) ;
        cout <<"ENTER ITEM PRICE TO ADD IN THE MENU" ;
        gotoxy(5,18) ;
        cout <<"Item Price : " ;
        gets(t_itemprice) ;
        itemprice = atof(t_itemprice) ;
        if (t_itemprice[0] == '0')
            return ;
        if (itemprice < itemcost || itemprice > 1000)
        {
            valid = 0 ;
            gotoxy(3,24) ;
            cout <<"\7 Range = " <<itemcost <<"..1000" ;
            getch() ;
        }
    }
    do
    {
        gotoxy(1,21) ;
        //clreol() ;
        gotoxy(1,24) ;
        //clreol() ;
        gotoxy(1,25) ;
        //clreol() ;
        gotoxy(5,21) ;
        cout <<"Do you want to save this record (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        return ;
    itemcode = t_code ;
    cout <<"\n" <<itemname ;
    cout <<itemcost ;
    cout <<itemprice ;
    getch() ;
    fstream file ;
    file.open("PRODUCT.DAT", ios::out | ios::ate) ;
    int location ;
    location = (recno-1) * sizeof(product) ;
    file.seekp(location) ;
    file.write((char *) this, sizeof(product)) ;
    file.close() ;
    sort() ;
    system("cls") ;
    gotoxy(5,15) ;
    cout <<"\7Record Modified" ;
    getch() ;
}

void product :: modify_item(void)
{
    system("cls") ;
    char t_code[5], ch ;
    int t, tcode ;
    gotoxy(3,25) ;
    cout <<"Press <ENTER> to see the list" ;
    gotoxy(5,3) ;
    cout <<"Enter Item Code of the item to be Modify : " ;
    gets(t_code) ;
    t = atoi(t_code) ;
    tcode = t ;
    if (t_code[0] == '0')
        return ;
    if (tcode == 0)
    {
        list_of_item() ;
        gotoxy(1,25) ;
        //clreol() ;
        gotoxy(3,25) ;
        cout <<"Press <ENTER> to Exit" ;
        gotoxy(5,24) ;
        cout <<"Enter Item Code of the item to be modify : " ;
        gets(t_code) ;
        t = atoi(t_code) ;
        tcode = t ;
        if (tcode == 0)
            return ;
    }
    system("cls") ;
    if (!item_found(tcode))
    {
        gotoxy(5,5) ;
        cout <<"\7Record not found" ;
        getch() ;
        return ;
    }
    display_record(tcode) ;
    do
    {
        gotoxy(5,8) ;
        cout <<"Do you want to Modify this record (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
    }
    while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        return ;
    modify_record(tcode) ;
}

void product :: sort(void)
{
    int i=0,j ;
    product arr[100] ;
    product temp ;
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) &arr[i], sizeof(product)))
        i++ ;
    int size ;
    size = i ;
    file.close() ;
    for (i=1; i<size; i++)
        for (j=0; j<size-i; j++)
        {
            if (arr[j].itemcode > arr[j+1].itemcode)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    file.open("PRODUCT.DAT", ios::out) ;
    for (i=0; i<size; i++)
        file.write((char *) &arr[i], sizeof(product)) ;
    file.close() ;
}

void product :: purchase(void)
{
    system("cls") ;
    account a ;
    int t_billno, purchased=0 ;
    t_billno = a.last_billno() ;
    t_billno++ ;
    char t_code[5], ch;
    float t_quantity ;
    int t, tcode, i=0, valid ;
    float qty ;
    int t_itemcode ;
    float t_qty, t_cost, t_price ;
    char t_itemname[30] ;
	date d;
	d.da_day = 0;
	d.da_mon = 0;
	d.da_year = 0;
    int d1, m1, y1 ;
    getdate(d);
    d1 = d.da_day ;
    m1 = d.da_mon ;
    y1 = d.da_year ;
    do
    {
        system("cls") ;
        gotoxy(3,25) ;
        cout <<"Press <ENTER> to see the list" ;
        gotoxy(5,3) ;
        cout <<"Enter Item Code of the item to be Purchase : " ;
        gets(t_code) ;
        t = atoi(t_code) ;
        tcode = t ;
        if (t_code[0] == '0')
        {
            if (purchased)
                a.prepare_bill(t_billno) ;
            return ;
        }
        if (tcode == 0)
        {
            list_of_item() ;
            gotoxy(1,25) ;
            //clreol() ;
            gotoxy(3,25) ;
            cout <<"Press <ENTER> to Exit" ;
            gotoxy(5,24) ;
            cout <<"Enter Item Code of the item to be Purchase : " ;
            gets(t_code) ;
            t = atoi(t_code) ;
            tcode = t ;
            if (tcode == 0)
            {
                if (purchased)
                    a.prepare_bill(t_billno) ;
                return ;
            }
        }
        system("cls") ;
        if (!item_found(tcode))
        {
            gotoxy(5,5) ;
            cout <<"\7Item Code not found" ;
            getch() ;
            if (purchased)
                a.prepare_bill(t_billno) ;
            return ;
        }
        gotoxy(60,2) ;
        cout <<"Date:" <<d1 <<"/" <<m1 <<"/" <<y1 ;
        display_record(tcode) ;
        do
        {
            valid = 1 ;
            gotoxy(1,8) ;
            //clreol() ;
            gotoxy(1,24) ;
            //clreol() ;
            gotoxy(1,25) ;
            //clreol() ;
            gotoxy(3,25) ;
            cout <<"ENTER QUANTITY TO BE PURCHASE IN Kg." ;
            gotoxy(5,8) ;
            cout <<"Quantity : " ;
            cin>>t_quantity ;
            qty=t_quantity ;
            if (t_quantity == 0)
            {
                if (purchased)
                    a.prepare_bill(t_billno) ;
                return ;
            }
            if (qty < 1 || qty > 800)
            {
                valid = 0 ;
                gotoxy(3,24) ;
                cout <<"\7 Range = 1..800" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {
            gotoxy(5,10) ;
            //clreol() ;
            gotoxy(5,10) ;
            cout <<"Do you want to cancel this purchase (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
        }
        while (ch != 'N' && ch != 'Y') ;
        if (ch == 'N')
        {
            purchased = 1 ;
            fstream file ;
            file.open("PRODUCT.DAT", ios::in) ;
            file.seekg(0,ios::beg) ;
            while (file.read((char *) this, sizeof(product)))
            {
                if (itemcode == tcode)
                {
                    t_itemcode = itemcode ;
                    strcpy(t_itemname,itemname) ;
                    t_cost = itemcost ;
                    t_price = itemprice ;
                    t_qty = qty ;
                    a.add_bill(t_billno,t_itemcode,t_itemname,t_qty,t_cost,t_price) ;
                    i++ ;
                    break ;
                }
            }
            file.close() ;
        }
        do
        {
            gotoxy(5,12) ;
            //clreol() ;
            gotoxy(5,12) ;
            cout <<"Do you want to purchase more (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
        }
        while (ch != 'N' && ch != 'Y') ;
    }
    while (ch == 'Y') ;
    a.prepare_bill(t_billno) ;
}

int product :: last_code(void)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int t=0 ;
    while (file.read((char *) this, sizeof(product)))
        t = itemcode ;
    file.close() ;
    return t ;
}


//**********************************************************
// THIS FUNCTION DISPLAY THE LIST OF THE ITEMS
//**********************************************************

void product :: list_of_item(void)
{
    system("cls") ;
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0) ;
    int row = 6 , found = 0 ;
    gotoxy(30,2) ;
    cout <<"LIST OF ITEMS" ;
    gotoxy(3,4) ;
    cout <<"ITEM CODE ITEM NAME ITEM COST ITEM PRICE" ;
    gotoxy(2,5) ;
    cout <<"***********************************************************" ;
    while (file.read((char *) this, sizeof(product)))
    {
        Sleep(20) ;
        found = 1 ;
        gotoxy(5,row) ;
        cout <<itemcode ;
        gotoxy(14,row) ;
        cout <<itemname ;
        gotoxy(37,row) ;
        cout <<itemcost ;
        gotoxy(51,row) ;
        cout <<itemprice ;
        if ( row == 22 )
        {
            row = 5 ;
            gotoxy(1,25) ;
            cout <<"Press any key to continue..." ;
            getche() ;
            system("cls") ;
            gotoxy(30,2) ;
            cout <<"LIST OF ITEMS" ;
            gotoxy(3,4) ;
            cout <<"ITEM CODE ITEM NAME ITEM COST ITEM PRICE" ;
            gotoxy(2,5) ;
            cout <<"***********************************************************"
                 ;
        }
        else
            row++ ;
    }
    if ( !found )
    {
        gotoxy(5,10) ;
        cout <<"\7Records not found" ;
    }
    gotoxy(1,25) ;
    cout <<"Press any key to continue..." ;
    getche() ;
    file.close () ;
}

#endif