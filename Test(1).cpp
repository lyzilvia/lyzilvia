#include "ArrayList.h"
#include "LinkList.h"

#include <iostream>

using namespace std;

int main ()
{
	cout<<"以下为LList的操作："<<endl;
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

	cout<<"长度为："<<llist.length()<<endl;

	cout<<"是否为空："<<(llist.length() == 0 ? "是" : "否")<<endl;

	llist.moveToPos(2);
	cout<<"第3个元素为："<<llist.getValue()<<endl;

	llist.moveToStart();
	for(int i = 0;i < llist.length();i++)
	{
		if(llist.getValue() == 'a')
		{
			cout<<"a的位置为"<<llist.currPos()<<endl;
			break;
		}
		llist.next();
	}

	llist.moveToPos(3);
	llist.insert('f');
	llist.moveToStart();
	cout<<"插入第4个元素后："<<endl;
	for(int i = 0;i < llist.length();i++)
	{
		cout<<llist.getValue()<<endl;
		llist.next();
	}

	llist.moveToPos(2);
	llist.remove();
	llist.moveToStart();
	cout<<"删除第3个元素后:"<<endl;
	for(int i = 0;i < llist.length();i++)
	{
		cout<<llist.getValue()<<endl;
		llist.next();
	}
	//*********************************************//
	cout<<"以下为AList的操作："<<endl;
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

	cout<<"长度为："<<alist.length()<<endl;

	cout<<"是否为空："<<(alist.length() == 0 ? "是" : "否")<<endl;

	alist.moveToPos(2);
	cout<<"第3个元素为："<<alist.getValue()<<endl;

	alist.moveToStart();
	for(int i = 0;i < alist.length();i++)
	{
		if(alist.getValue() == 'a')
		{
			cout<<"a的位置为"<<alist.currPos()<<endl;
			break;
		}
		alist.next();
	}

	alist.moveToPos(3);
	alist.insert('f');
	alist.moveToStart();
	cout<<"插入第4个元素后："<<endl;
	for(int i = 0;i < alist.length();i++)
	{
		cout<<alist.getValue()<<endl;
		alist.next();
	}

	alist.moveToPos(2);
	alist.remove();
	alist.moveToStart();
	cout<<"删除第3个元素后:"<<endl;
	for(int i = 0;i < alist.length();i++)
	{
		cout<<alist.getValue()<<endl;
		alist.next();
	}
	system("pause");
}