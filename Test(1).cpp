#include "ArrayList.h"
#include "LinkList.h"

#include <iostream>

using namespace std;

int main ()
{
	cout<<"����ΪLList�Ĳ�����"<<endl;
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

	cout<<"����Ϊ��"<<llist.length()<<endl;

	cout<<"�Ƿ�Ϊ�գ�"<<(llist.length() == 0 ? "��" : "��")<<endl;

	llist.moveToPos(2);
	cout<<"��3��Ԫ��Ϊ��"<<llist.getValue()<<endl;

	llist.moveToStart();
	for(int i = 0;i < llist.length();i++)
	{
		if(llist.getValue() == 'a')
		{
			cout<<"a��λ��Ϊ"<<llist.currPos()<<endl;
			break;
		}
		llist.next();
	}

	llist.moveToPos(3);
	llist.insert('f');
	llist.moveToStart();
	cout<<"�����4��Ԫ�غ�"<<endl;
	for(int i = 0;i < llist.length();i++)
	{
		cout<<llist.getValue()<<endl;
		llist.next();
	}

	llist.moveToPos(2);
	llist.remove();
	llist.moveToStart();
	cout<<"ɾ����3��Ԫ�غ�:"<<endl;
	for(int i = 0;i < llist.length();i++)
	{
		cout<<llist.getValue()<<endl;
		llist.next();
	}
	//*********************************************//
	cout<<"����ΪAList�Ĳ�����"<<endl;
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

	cout<<"����Ϊ��"<<alist.length()<<endl;

	cout<<"�Ƿ�Ϊ�գ�"<<(alist.length() == 0 ? "��" : "��")<<endl;

	alist.moveToPos(2);
	cout<<"��3��Ԫ��Ϊ��"<<alist.getValue()<<endl;

	alist.moveToStart();
	for(int i = 0;i < alist.length();i++)
	{
		if(alist.getValue() == 'a')
		{
			cout<<"a��λ��Ϊ"<<alist.currPos()<<endl;
			break;
		}
		alist.next();
	}

	alist.moveToPos(3);
	alist.insert('f');
	alist.moveToStart();
	cout<<"�����4��Ԫ�غ�"<<endl;
	for(int i = 0;i < alist.length();i++)
	{
		cout<<alist.getValue()<<endl;
		alist.next();
	}

	alist.moveToPos(2);
	alist.remove();
	alist.moveToStart();
	cout<<"ɾ����3��Ԫ�غ�:"<<endl;
	for(int i = 0;i < alist.length();i++)
	{
		cout<<alist.getValue()<<endl;
		alist.next();
	}
	system("pause");
}