#include "Whole_support.h"

#ifndef ACCOUNT_H
#define ACCOUNT_H
class account
{
public :
    void bill_list(void) ;
    void prepare_bill(int) ;
    int last_billno(void) ;
    void add_bill(int, int t_itemcode, char *t_itemname, float t_qty,
                  float t_cost, float t_price) ;
private :
    int code, billno, length ;
    int dd, mm, yy ;
    float cost, price, quantity ;
    char name[30] ;
} ;

int account :: last_billno(void)
{
    fstream file ;
    file.open("BILL.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int t=0 ;
    while (file.read((char *) this, sizeof(account)))
        t = billno ;
    file.close() ;
    return t ;
}

void account :: add_bill(int t_billno, int t_itemcode, char
                         t_itemname[30], float t_qty, float t_cost, float t_price)
{
    date d;
    int d1, m1, y1 ;
    getdate(d);
    d1 = d.da_day ;
    m1 = d.da_mon ;
    y1 = d.da_year ;
    dd = d1 ;
    mm = m1 ;
    yy = y1 ;
    code = t_itemcode ;
    strcpy(name,t_itemname) ;
    cost = t_cost ;
    price = t_price ;
    quantity = t_qty ;
    billno = t_billno ;
    fstream file ;
    file.open("BILL.DAT", ios::out | ios:: app ) ;
    file.write((char *) this, sizeof(account)) ;
    file.close() ;
}

void account :: prepare_bill(int t_billno)
{
    system("cls") ;
    date d;
    int d1, m1, y1 ;
    getdate(d);
    d1 = d.da_day ;
    m1 = d.da_mon ;
    y1 = d.da_year ;
    float total=0.0, total_bill=0.0 ;
    gotoxy(33,3) ;
    cout <<"CUSTOMER BILL" ;
    gotoxy(55,5) ;
    cout <<"Date:" <<d1 <<"/" <<m1 <<"/" <<y1 ;
    gotoxy(8,7) ;
    cout <<"ITEMS PURCHASED" ;
    gotoxy(8,8) ;
    cout <<"+++++++++++++++" ;
    gotoxy(8,9) ;
    cout <<"Item code Item name Cost Price Qty Total"
         ;
    gotoxy(8,10) ;
    cout <<"------------------------------------------------------------"
         ;
    int row=11 ;
    fstream file ;
    file.open("BILL.DAT", ios::in) ;
    file.seekg(0) ;
    while (file.read((char *) this, sizeof(account)) !=0 )
    {
        if (billno == t_billno)
        {
            gotoxy(8,5) ;
            cout <<"BILL NO. # " <<billno ;
            gotoxy(8,6) ;
            cout <<"===============" ;
            gotoxy(10,row) ;
            cout <<code ;
            gotoxy(18,row) ;
            cout <<name ;
            gotoxy(39,row) ;
            cout <<cost ;
            gotoxy(47,row) ;
            cout <<price ;
            gotoxy(56,row) ;
            cout <<quantity ;
            total = quantity * price ;
            gotoxy(63,row) ;
            cout <<total ;
            total_bill = total_bill + total ;
            row++ ;
        }
    }
    file.close() ;
    gotoxy(39,row+1) ;
    cout <<"TOTAL BILL: Rs." <<total_bill <<" /=" ;
    getch() ;
}

void account :: bill_list(void)
{
    system("cls") ;
    fstream file ;
    file.open("BILL.DAT", ios::in) ;
    file.seekg(0) ;
    int row=5, found=0, pageno=1, prev_billno=0, flag=0 ;
    float total=0.0, total_bill=0.0 ;
    gotoxy(30,2) ;
    cout <<"LIST OF BILLS" ;
    gotoxy(3,4) ;
    cout <<"Billno. Date Item Code Item name Cost Pri Qty Total" ;
    gotoxy(3,5) ;
    cout
            <<"===========================================================================" ;
    while (file.read((char *) this, sizeof(account)))
    {
        row++ ;
        Sleep(20) ;
        found = 1 ;
        if (prev_billno != billno)
        {
            if (flag)
            {
                gotoxy(52,row) ;
                cout <<"TOTAL BILL: Rs." <<total_bill <<"/=" ;
                total_bill = 0.0 ;
                row++ ;
            }
            gotoxy(4,row) ;
            cout <<billno ;
        }
        flag = 1 ;
        gotoxy(11,row) ;
        cout <<dd <<"/" <<mm <<"/" <<yy ;
        gotoxy(24,row) ;
        cout <<code ;
        gotoxy(32,row) ;
        cout <<name ;
        gotoxy(52,row) ;
        cout <<cost ;
        gotoxy(59,row) ;
        cout <<price ;
        gotoxy(67,row) ;
        cout <<quantity ;
        total = quantity * price ;
        gotoxy(73,row) ;
        cout <<total ;
        total_bill = total_bill + total ;
        if ( row >= 23 )
        {
            row = 5 ;
            gotoxy(66,1) ;
            cout <<"Page no. : " <<pageno ;
            pageno++ ;
            gotoxy(1,25) ;
            cout <<"Press any key to continue..." ;
            getche() ;
            system("cls") ;
            gotoxy(30,2) ;
            cout <<"LIST OF BILLS" ;
            gotoxy(3,4) ;
            cout <<"Billno. Date Item Code Item name CostPrice Qty Total" ;
            gotoxy(3,5) ;
            cout
                    <<"===========================================================================" ;
        }
        prev_billno = billno ;
    }
    row++ ;
    gotoxy(52,row) ;
    cout <<"TOTAL BILL: Rs." <<total_bill <<"/=" ;
    if ( !found )
    {
        gotoxy(5,10) ;
        cout <<"\7Records not found" ;
    }
    gotoxy(66,1) ;
    cout <<"Page no. : " <<pageno ;
    gotoxy(1,25) ;
    cout <<"Press any key to continue..." ;
    getche() ;
    file.close () ;
}
#endif