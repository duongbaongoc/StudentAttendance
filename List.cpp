/****************************************************************************
* Author: Ngoc Duong														*
* Assignment: PA6 - CPTS 122												*
* This file defines all functions for class List.							*
****************************************************************************/

#include "List.h"

/************************************************************/
/*********Constructors***************************************/
/************************************************************/

//default constructor
List::List()
{
	mPHead = nullptr;
}

//copy constructor - deep copy
List::List(const List &copyList)
{
	Node *pCur = copyList.getPHead();
	while (pCur != nullptr) //traverse through the copyList
	{
		Node *pMem = new Node(*pCur); //create a new node for each node found in copyList
		insertAtEnd(pMem); // insert the created node to end of the refered list
		pCur = pCur->getPNext(); //advance pCur
	}
}

/************************************************************/
/*********Setters, Getters, Destructor***********************/
/************************************************************/

//get mPHead
Node * List::getPHead() const
{
	return mPHead;
}

//set mPHead
void List::setPHead(Node * const pHead)
{
	mPHead = pHead;
}

//destructor
List::~List()
{
	Node *pCur = mPHead, *pPrev = nullptr;
	while (pCur != nullptr) //traverse till the end of list
	{
		pPrev = pCur;
		pCur = pCur->getPNext();
		delete pPrev;
	}
}

/************************************************************/
/*********Member functions***********************************/
/************************************************************/

//this function will call a helper in private section
//insert the given node at the end of the list
void List::insertAtEnd(Node *const pNode)
{
	insertAtEnd(pNode, mPHead);
}

//helper for insertAtEnd() in public section
//insert the given node at the end of the list
void List::insertAtEnd(Node * const pNode, Node *& pHead) 
{
	Node *pCur = pHead;
	if (pCur == nullptr) //list is empty
		pHead = pNode;
	else
	{
		while (pCur->getPNext() != nullptr) // find the last node in the list
		{
			pCur = pCur->getPNext();
		}
		pCur->setPNext(pNode); //link the given node to the last node of the list
	}
}

//this function will call a helper in private section
//insert the given node at front of the list
void List::insertAtFront(Node *const pNode)
{
	insertAtFront(pNode, mPHead);
}

//helper for insertAtFront() in public section
//insert the given node at front of the list
void List::insertAtFront(Node * const pNode, Node *& pHead)
{
	pNode->setPNext(pHead);
	mPHead = pNode;
}

//overloaded assignment operator - deep copy
List & const List::operator= (List & const rhs)
{
	Node *pCur = rhs.getPHead();
	while (pCur != nullptr) //traverse through the copyList
	{
		Node *pMem = new Node(*pCur); //create a new node for each node found in copyList
		insertAtEnd(pMem); // insert the created node to end of the refered list
		pCur = pCur->getPNext(); //advance pCur
	}
	return rhs;
}

/************************************************************/
/*********Non member functions*******************************/
/************************************************************/

//overloaded operator<< : insert content of the list's nodes to an ostream
ostream & operator<< (ostream &lhs, List & const rhs)
{
	Node *pCur = rhs.getPHead();
	while (pCur != nullptr)
	{
		lhs << *pCur << endl;
		pCur = pCur->getPNext();
	}
	return lhs;
}