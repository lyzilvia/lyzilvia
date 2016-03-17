#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "List.h"
#include <iostream>

using namespace std;

template <typename E>
	class AList : public List<E>
	{
	private:
		int maxSize;
		int listSize;
		int curr;
		E* listArray;

	public:
		AList(int size = defaultSize)
		{
			maxSize = size;
			listSize = curr = 0;
			listArray = new E[maxSize];
		}
		~AList()
		{
			delete [] listArray;
		}
		void clear()
		{
			delete [] listArray;
			listSize = curr = 0;
			listArray = new E[maxSize];
		}

		void insert(const E& it)
		{
			if(listSize >= maxSize)
			{
				cout<<"List capacity exceede"<<endl;
			}
			for(int i = listSize;i > curr;i--)
			{
				listArray[i] = listArray[i-1];
			}
			listArray[curr] = it;
			listSize++;
		}
		
		void append(const E& it)
		{
			if(listSize >= maxSize)
			{
				cout<<"List capacity exceede"<<endl;
			}
			listArray[listSize++] = it;
		}
		
		E remove()
		{
			if(!((curr >= 0) && (curr < listSize)))
			{
				cout<<"No element"<<endl;
			}
			E it = listArray[curr];
			for(int i = curr;i < listSize - 1;i++)
			{
				listArray[i] = listArray[i+1];
			}
			listSize--;
			return it;
		}

		void moveToStart() 
		{
			curr = 0;
		}

		void moveToEnd()
		{
			curr = listSize;
		}

		void prev()
		{
			if(curr != 0)
			{
				curr--;
			}
		}

		void next()
		{
			if(curr < listSize)
			{
				curr++;
			}
		}

		int length() const
		{
			return listSize;
		}

		int currPos() const
		{
			return curr;
		}

		void moveToPos(int pos)
		{
			if(!((pos >= 0) && (pos <= listSize)))
			{
				cout<<"Pos out of range"<<endl;
			}
			curr = pos;
		}

		const E& getValue() const
		{
			if(!((curr >= 0) && (curr < listSize)))
			{
				cout<<"No current element"<<endl;
			}
			return listArray[curr];
		}
	};
#endif