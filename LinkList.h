#ifndef LINKLIST_H
#define LINKLIST_H

#include "List.h"
#include <iostream>

using namespace std;

template <typename E>
    class Link
	{
	public:
		E element;
		Link* next;
		Link(const E& elemval, Link* nextval = NULL)
		{
			element = elemval;
			next = nextval;
		}
		Link(Link* nextval = NULL)
		{
			next = nextval;
		}
	};

template <typename E>
    class LList : public List<E>
	{
	private:
		Link<E>* head;
		Link<E>* tail;
		Link<E>* curr;
		int cnt;

		void init()
		{
			curr = tail = head = new Link<E>;
			cnt = 0;
		}

		void removeall()
		{
			while(head != NULL)
			{
				curr = head;
				head = head->next;
				delete curr;
			}
		}

	public:
		LList(int size = defaultSize)
		{
			init();
		}
		
		~LList()
		{
			removeall();
		}
	
		void clear()
		{
			removeall();
			init();
		}
	
		void insert(const E& it)
		{
			curr->next = new Link<E>(it, curr->next);
			if(tail == curr)
			{
				tail = curr->next;
			}
			cnt++;
		}

		void append(const E& it)
		{
			tail = tail->next = new Link<E>(it, NULL);
			cnt++;
		}
	
		E remove()
		{
			if(curr->next == NULL)
			{
				cout << "No element\n";
			}
			E it = curr->next->element;
			Link<E> * ltemp = curr->next;
			if(tail == curr->next)
			{
				tail = curr;
			}
			curr->next = curr->next->next;
			delete ltemp;
			cnt--;
			return it;
		}
	
		void moveToStart()
		{
			curr = head;
		}

		void moveToEnd()
		{
			curr = tail;
		}
	
		void prev()
		{
			if(curr == head)
			{
				return;
			}
			Link<E> * temp = head;
			while(temp->next != curr)
			{
				temp = temp->next;
			}
			curr = temp;
		}

		void next()
		{
			if(curr != tail)
			{
				curr = curr->next;
			}
		}

		int length() const
		{
			return cnt;
		}

		int currPos() const
		{
			Link<E> * temp = head;
			int i;
			for(i = 0;curr != temp;i++)
			{
				temp = temp->next;
			}
			return i;
		}

		void moveToPos(int pos)
		{
			if(!((pos >= 0) && (pos <= cnt)))
			{
				cout << "Position out of range\n";
			}
			curr = head;
			for(int i = 0;i < pos;i++)
			{
				curr = curr->next;
			}
		}

		const E & getValue() const
		{
			if(curr->next == NULL)
			{
				cout << "No value\n";
			}
			return curr->next->element;
		}
    };

#endif