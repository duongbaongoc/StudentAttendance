/****************************************************************************
* Author: Ngoc Duong														*
* Assignment: PA6 - CPTS 122												*
* This file declares a class List which is a singly linked list				*
****************************************************************************/
#include "ListNode.h"

class List
{
public:
	//constructors
	List(); //default
	List(const List &copyList); // copy
	//getter
	Node * getPHead() const;
	//setter
	void setPHead(Node * const pHead);
	//other member functions
	void insertAtEnd(Node * const pNode); //this function will call a helper in private section
	void insertAtFront(Node * const pNode); //this function will call a helper in private section
	List & const operator= (List & const rhs);//overloaded assignment operator
	//destructor
	~List();
private:
	Node *mPHead;
	void insertAtEnd(Node * const pNode, Node *& pHead); //helper for insertAtEnd() in public section
	void insertAtFront(Node * const pNode, Node *& pHead); //helper for insertAtFront() in public section
};

//overloaded operator<< : insert content of the list's nodes to an ostream
ostream & operator<< (ostream &lhs, List & const rhs);