#include "ArrayList.h"
#include "LinkList.h"

#include <iostream>

using namespace std;

int main ()
{
	cout<<"Output of AList"<<endl;
	AList<char> alist(10);
	alist.append('a');
	alist.append('b');
	alist.append('c');
	alist.append('d');
	alist.append('e');

	alist.moveToStart();
	for(int i = 0;i < alist.length();i++)
	{
		cout<<alist.getValue()<<endl;
		alist.next();
	}

	cout<<"Length:"<<alist.length()<<endl;

	cout<<"Is it empty:"<<(alist.length() == 0 ? "Yes" : "No")<<endl;

	alist.moveToPos(2);
	cout<<"The 3rd element is:"<<alist.getValue()<<endl;

	alist.moveToStart();
	for(int i = 0;i < alist.length();i++)
	{
		if(alist.getValue() == 'a')
		{
			cout<<"Position of a:"<<alist.currPos()<<endl;
			break;
		}
		alist.next();
	}

	alist.moveToPos(3);
	alist.insert('f');
	alist.moveToStart();
	cout<<"After insert 4th element:"<<endl;
	for(int i = 0;i < alist.length();i++)
	{
		cout<<alist.getValue()<<endl;
		alist.next();
	}

	alist.moveToPos(2);
	alist.remove();
	alist.moveToStart();
	cout<<"After delete 3rd element:"<<endl;
	for(int i = 0;i < alist.length();i++)
	{
		cout<<alist.getValue()<<endl;
		alist.next();
	}

	//*********************************************//

	cout<<"Output of LList:"<<endl;
	LList<char> llist(10);
	llist.append('a');
	llist.append('b');
	llist.append('c');
	llist.append('d');
	llist.append('e');

	llist.moveToStart();
	for(int i = 0;i < llist.length();i++)
	{
		cout<<llist.getValue()<<endl;
		llist.next();
	}

	cout<<"Length:"<<llist.length()<<endl;

	cout<<"Is it empty:"<<(llist.length() == 0 ? "Yes" : "No")<<endl;

	llist.moveToPos(2);
	cout<<"The 3rd element is:"<<llist.getValue()<<endl;

	llist.moveToStart();
	for(int i = 0;i < llist.length();i++)
	{
		if(llist.getValue() == 'a')
		{
			cout<<"Position of a:"<<llist.currPos()<<endl;
			break;
		}
		llist.next();
	}

	llist.moveToPos(3);
	llist.insert('f');
	llist.moveToStart();
	cout<<"After insert 4th element:"<<endl;
	for(int i = 0;i < llist.length();i++)
	{
		cout<<llist.getValue()<<endl;
		llist.next();
	}

	llist.moveToPos(2);
	llist.remove();
	llist.moveToStart();
	cout<<"After delete 3rd element:"<<endl;
	for(int i = 0;i < llist.length();i++)
	{
		cout<<llist.getValue()<<endl;
		llist.next();
	}

	system("pause");
}