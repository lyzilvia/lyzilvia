#include "Account_query.h"
#include "ShowMain_menu.h"

#ifndef SHOWCLIENT_H
#define SHOWCLIENT_H
void showClients()
{
    account_query* A = new account_query;
    int choice;
    cout<<"***Acount Information System***"<<endl;
    while(true)
    {
        cout<<"Select one option below ";
        cout<<"\n\t1-->Add record to file";
        cout<<"\n\t2-->Show record from file";
        cout<<"\n\t3-->Search Record from file";
        cout<<"\n\t4-->Update Record";
        cout<<"\n\t5-->Delete Record";
        cout<<"\n\t6-->Quit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            A->write_rec();
            break;
        case 2:
            A->read_rec();
            break;
        case 3:
            A->search_rec();
            break;
        case 4:
            A->edit_rec();
            break;
        case 5:
            A->delete_rec();
            break;
        case 6:
            break;
        default:
            cout<<"\nEnter corret choice";
			break;
        }
		if(choice == 6)
		{
			break;
		}
    }
}
#endif