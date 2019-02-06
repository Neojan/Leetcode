#include "leetcode.h"

/*
2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers. 

The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

class ListNode
{
public:
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};


template <class Item>
class QueueTP
{
private:
	enum { Q_SIZE = 10 };//static const int Q_SIZE = 10; //int QueueTP::Q_SIZE = 10; 
	// ListNode is a nested class definition
	ListNode * front;       // pointer to front of Queue
	ListNode * rear;        // pointer to rear of Queue
	int items;          // current number of items in Queue
	const int qsize;    // maximum number of items in Queue
	QueueTP(const QueueTP & q) : qsize(0) {}
	QueueTP & operator=(const QueueTP & q) { return *this; }
public:
	QueueTP(int qs = Q_SIZE);
	~QueueTP();
	bool isempty() const
	{
		return items == 0;
	}
	bool isfull() const
	{
		return items == qsize;
	}
	int queuecount() const
	{
		return items;
	}
	bool enqueue(const Item &item); // add item to end
	bool dequeue(Item &item);       // remove item from front
};

// QueueTP methods
template <class Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
	front = rear = 0;
	items = 0;
}

template <class Item>
QueueTP<Item>::~QueueTP()
{
	ListNode * temp;
	while (front != 0)      // while queue is not yet empty
	{
		temp = front;       // save address of front item
		front = front->next;// reset pointer to next item
		delete temp;        // delete former front
	}
}

// Add item to queue
template <class Item>
bool QueueTP<Item>::enqueue(const Item & val)
{
	if (isfull())
		return false;
	ListNode * add = new ListNode(val);    // create node
											// on failure, new throws std::bad_alloc exception
	items++;
	if (front == 0)         // if queue is empty,
		front = add;        // place item at front
	else
		rear->next = add;   // else place at rear
	rear = add;             // have rear point to new node
	return true;
}

// Place front item into item variable and remove from queue
template <class Item>
bool QueueTP<Item>::dequeue(Item & val)
{
	if (front == 0)
		return false;
	val = front->val;     // set item to first item in queue
	items--;
	ListNode * temp = front;    // save location of first item
	front = front->next;    // reset front to next item
	delete temp;            // delete former first item
	if (items == 0)
		rear = 0;
	return true;
}

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *retNode = new ListNode(0);
		ListNode *newNode = retNode;
		ListNode *headNode = retNode;
		int value = 0;
		int carry = 0;
		int add1 = 0;
		int add2 = 0;

		for (; l1 || l2;)
		{
			if (NULL == l1)
			{
				//l1 is end
				add1 = l2->val;
				add2 = 0;
				l2 = l2->next;
			}
			else if (NULL == l2)
			{
				//l2 is end
				add1 = l1->val;
				add2 = 0;			
				l1 = l1->next;
			}
			else
			{
				add1 = l1->val;
				add2 = l2->val;
				l1 = l1->next;
				l2 = l2->next;
			}
			value = (add1 + add2 + carry) % 10;
			carry = (add1 + add2 + carry) / 10;
			newNode->next = new ListNode(value);
			newNode = newNode->next;
		}

		if (carry)
		{
			newNode->next = new ListNode(carry);
			newNode = newNode->next;
		}
		
		retNode = retNode->next;

		delete headNode;

		return retNode;
	}
};

void T2_test(void)
{
	Solution twoSolve;
	ListNode *retNode;
	ListNode *temp;
	ListNode *l1;
	l1 = new ListNode(1);
	//l1->next = new ListNode(4);
	//l1->next->next = new ListNode(3);

	ListNode *l2;
	l2 = new ListNode(9);
	l2->next = new ListNode(9);
	//l2->next->next = new ListNode(4);
#if 0
	QueueTP<int> l1(3);
	int temp;
	l1.enqueue(2);
	l1.enqueue(4);
	l1.enqueue(3);
	while (!l1.isempty())
	{
		l1.dequeue(temp);
		cout << temp << endl;
	}
#endif

	retNode = twoSolve.addTwoNumbers(l1, l2);
	do
	{
		cout << retNode->val << endl;
		ListNode * temp = retNode;    // save location of first item
		retNode = retNode->next;    // reset front to next item
		delete temp;            // delete former first item
	} while (retNode);

	getchar();
}