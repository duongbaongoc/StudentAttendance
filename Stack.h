/****************************************************************************
* Author: Ngoc Duong														*
* Assignment: PA6 - CPTS 122												*
* This file declare a class Stack which is a string array.					*
****************************************************************************/

#include <iostream>
#include <string>

using std::string;

//Stack contains a string array whose each node represents an absent date
//The stack has a pointer to the head of it but all push/pop/peek are applied at the end of the stack
class Stack
{
	public:
		//constructors
		Stack(); //default
		Stack(unsigned int maxSize); //parametrized
		Stack(Stack & copyStack); //deep copy
		//setters
		void setPHead(string * const pDate);
		void setCurrentSize(const unsigned int newSize);
		void setMaxSize(const unsigned int newSize);
		//getters
		string * getPHead() const;
		unsigned int getCurrentSize() const;
		unsigned int getMaxSize() const;
		//other functions
		bool isEmpty() const; // check if the stack is empty
		const string & peek() const; //retrieve content of the last item
		bool push(const string &date); //insert an item to the end
		bool pop(string &date); //delete the last item
		const Stack & operator=(const Stack &rhs); //overloaded assignment operator
		//destructor
		~Stack(); //delete the array
	private:
		string *mPHead;
		unsigned int mCurrentSize;
		unsigned int mMaxSize;
};