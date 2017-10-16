/****************************************************************************
* Author: Ngoc Duong														*
* Assignment: PA6 - CPTS 122												*
* This file defines all functions for class Stack.							*
****************************************************************************/

#include "Stack.h"

/************************************************************/
/*********Constructors, Setter, Getters**********************/
/************************************************************/

//default constructor
Stack::Stack()
{
	mMaxSize = 0;
	mCurrentSize = 0;
	mPHead = new string[1];
}

//parametrized constructor
Stack::Stack(unsigned int maxSize)
{
	mMaxSize = maxSize;
	mCurrentSize = 0;
	mPHead = new string[maxSize];
}

//copy constructor - deep copy
Stack::Stack(Stack & copyStack)
{
	mCurrentSize = copyStack.getCurrentSize();
	mMaxSize = copyStack.getMaxSize();
	mPHead = new string[mMaxSize];
	for (int index = 0; index < mMaxSize; index++)
	{
		mPHead[index] = copyStack.getPHead()[index];
	}
}

//set mPHead
void Stack::setPHead(string *const pDate)
{
	mPHead = pDate;
}

//set mCurrentSize
void Stack::setCurrentSize(const unsigned int newSize)
{
	mCurrentSize = newSize;
}

//set mMaxSize
void Stack::setMaxSize(const unsigned int newSize)
{
	mMaxSize = newSize;
}

//get mPHead
string * Stack::getPHead() const
{
	return mPHead;
}

//get mCurrentSize
unsigned int Stack::getCurrentSize() const
{
	return mCurrentSize;
}

//get mMaxSize
unsigned int Stack::getMaxSize() const
{
	return mMaxSize;
}

//destructor: delete the array
Stack::~Stack()
{
	if (mPHead != nullptr)
	{
		delete[] mPHead;
	}
}

/************************************************************/
/*********Other member functions*****************************/
/************************************************************/

//check if the stack is empty
bool Stack::isEmpty() const
{
	return mCurrentSize == 0;
}

//return value of the last item
//post condition: stack is not empty
const string & Stack::peek() const
{
	return mPHead[mCurrentSize - 1];
}

//insert the given item to the end of the stack
//return <true> is there is room to insert, <false> otherwise
bool Stack::push(const string &date)
{
	if (mCurrentSize < mMaxSize) //there is room to insert
	{
		mPHead[mCurrentSize] = date;
		mCurrentSize++;
	}
	return mCurrentSize != mMaxSize;
}

//delete the last item of the stack
//return <true> is there is an item to pop, <false> otherwise 
//return the popped item through parameter
bool Stack::pop(string &date)
{
	if (!isEmpty()) //there is an item to pop
	{
		date = mPHead[mCurrentSize - 1];
		mCurrentSize--;
	}
	return !isEmpty();
}

//overloaded assignment operator: copy the given stack over to the refered stack
//return the given stack
const Stack & Stack::operator=(const Stack &rhs)
{
	if (mPHead != nullptr || mMaxSize == 0) //if the refer stack has an array then delete the array
		delete [] mPHead;
	mPHead = new string[rhs.getMaxSize()]; //create a new array for the stack that has the same size as the rhs
	mCurrentSize = rhs.getCurrentSize();
	mMaxSize = rhs.getMaxSize();
	for (int index = 0; index < mMaxSize; index++)
	{
		mPHead[index] = rhs.getPHead()[index];
	}
	
	return rhs;
}

/************************************************************/
/*********Non member functions*******************************/
/************************************************************/