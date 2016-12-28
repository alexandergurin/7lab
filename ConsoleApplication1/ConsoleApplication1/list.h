#pragma once
#include <iostream>
#include <string>
using namespace std;
template <class T>
class List
{
private:
	T value;
	List *head;
	List *next;
public:
	List()
	{
		head = NULL;
		next = NULL;
	}
	void operator () (int i)
	{
		List *ptr1, *ptr2;
		int k = 0;
		if (head == NULL)
			return;
		if ((head)->next == NULL) {
			free(head);
			head = NULL;
			return;
		}
		ptr1 = head;
		ptr2 = (head)->next;
		if (i == 0)
		{
			head = head->next;
			delete ptr1;
		}
		else
		{
			while (k != i)
			{
				ptr1 = ptr2;
				ptr2 = ptr2->next;
				k++;
			}
			ptr1->next = ptr2->head;
			delete ptr2;
		}
	}
	void operator () (T val, int index)
	{
		if (!head)
		{
			head = new List();
			head->next = NULL;
			head->value = val;
			return;
		}
		else
		{
			if (index < 0)
			{
				List * q = head;
				if (q->next == NULL)
				{
					q->next = new List();
					q->next->next = NULL;
					q->next->value = val;
				}
				else
				{
					while (q->next != NULL)
					{
						q = q->next;
					};
					q->next = new List();
					q->next->next = NULL;
					q->next->value = val;
				}
			}
		}
		if (index == 0)
		{
			List *q = new List();
			q->value = val;
			q->next = head;
			head = q;
		}
		if (index > 0)
		{
			List *ptr1, *ptr2;
			ptr1 = head;
			ptr2 = new List();
			for (int i = 1; i < index; i++)
				ptr1 = ptr1->next;
			ptr2->value = val;
			ptr2->next = ptr1->next;
			ptr1->next = ptr2;
		}
	}
	
	friend bool operator != (List &a, List &b)
	{
		List *temp1 = a.head;
		List *temp2 = b.head;
		while ((temp1) || (temp2))
		{
			if (temp1 == NULL) return false;
			if (temp2 == NULL) return false;
			if (temp1->value == temp2->value)
			{
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	void show()
	{
		List *q = head;
		while (q)
		{
			cout << q->value << " ";
			q = q->next;
		}
		cout << endl;
	}
void	sred ()
{
	int sr;
	int sum = 0;
	int count=0;
	List *q = head;
		while (q)
		{
		sum = sum+q->value;
			q = q->next;
			count++;
		}
		 sr=sum/count;
			cout<<"SRED ZNACH:"<<sr<< endl;
}

	void showData()
	{
		List *q = head;
		while (q)
		{
			T temp = q->value;
			cout << temp.getData() << " ";
			q = q->next;
		}
		cout << endl;
	}
};
class Object
{
private:
	string data;
	int number;
public:
	Object()
	{
		data = "";
		number = 0;
	}
	Object(string d, int num)
	{
		data = d;
		number = num;
	}
	void setData(string d, int num)
	{
		data = d;
		number = num;
	}
	string getData()
	{
		return data;
	}
	void print()
	{
		cout << data << " " << number << endl;
	}
	friend int operator +(int left, Object &right)
	{
		return left+right.number;
	}

};