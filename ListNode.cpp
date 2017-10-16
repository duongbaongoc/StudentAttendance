/****************************************************************************
* Author: Ngoc Duong														*
* Assignment: PA6 - CPTS 122												*
* This file defines all functions for class Node.							*
****************************************************************************/

#include "ListNode.h"

/************************************************************/
/*********Constructors***************************************/
/************************************************************/

//default constructor - max 25 days of absence
Node::Node()
{
	mRecordNumber = 0;
	mID = 0;
	mName = "";
	mEmail = "";
	mUnits = "";
	mProgram = "";
	mLevel = "";
	mNumberAbsences = 0;
	mAbsentDate = *(new Stack(25));
	mPNext = nullptr;
}

//parametrized constructor
Node::Node(unsigned int recordNumber, unsigned int ID, string & name,
	string & email, string & units, string & program, string & level,
	unsigned int numberAbsences, Stack & absentDate)
{
	mRecordNumber = recordNumber;
	mID = ID;
	mName = name;
	mEmail = email;
	mUnits = units;
	mProgram = program;
	mLevel = level;
	mNumberAbsences = numberAbsences;
	mAbsentDate = absentDate;
	mPNext = nullptr;
}

//copy constructor
Node::Node(Node & const pNode)
{
	mRecordNumber = pNode.getRecordNumber();
	mID = pNode.getID();
	mName = pNode.getName();
	mEmail = pNode.getEmail();
	mUnits = pNode.getUnits();
	mProgram = pNode.getProgram();
	mLevel = pNode.getLevel();
	mNumberAbsences = pNode.getNumberAbsences();
	mAbsentDate = pNode.getAbsentDate();
	mPNext = nullptr;
}

/************************************************************/
/*********Getters********************************************/
/************************************************************/

//get mRecordNumber
unsigned int Node::getRecordNumber() const
{
	return mRecordNumber;
}

//get mID
unsigned int Node::getID() const
{
	return mID;
}

//get mName
const string & Node::getName() const
{
	return mName;
}

//get mEmail
const string & Node::getEmail() const
{
	return mEmail;
}

//get mUnits
const string & Node::getUnits() const
{
	return mUnits;
}

//get mProgram
const string & Node::getProgram() const
{
	return mProgram;
}

//get mLevel
const string & Node::getLevel() const
{
	return mLevel;
}

//get mNumberAbsences
unsigned int Node::getNumberAbsences() const
{
	return mNumberAbsences;
}

//get mAbsentDate
Stack & Node::getAbsentDate()
{
	return mAbsentDate;
}

//get mPNext
Node * Node::getPNext() const
{
	return mPNext;
}

/************************************************************/
/*********Setters********************************************/
/************************************************************/

//set mRecordNumber
void Node::setRecordNumber(unsigned int recordNumber)
{
	mRecordNumber = recordNumber;
}

//set mID
void Node::setID(unsigned int ID)
{
	mID = ID;
}

//set mName
void Node::setName(const string & name)
{
	mName = name;
}

//set mEmail
void Node::setEmail(const string & email)
{
	mEmail = email;
}

//set mUnits
void Node::setUnits(const string & units)
{
	mUnits = units;
}

//set mProgram
void Node::setProgram(const string & program)
{
	mProgram = program;
}

//set mLevel
void Node::setLevel(const string & level)
{
	mLevel = level;
}

//set mNumberAbsences
void Node::setNumberAbsences(unsigned int numberAbsences)
{
	mNumberAbsences = numberAbsences;
}

//set mAbsentDates
void Node::setAbsentDate(const Stack & absentDates)
{
	mAbsentDate = absentDates;
}

//set mPHead
void Node::setPNext(Node * const node)
{
	mPNext = node;
}

//destructor
Node::~Node()
{
	//nothing goes here
}

/************************************************************/
/*********Other member functions*****************************/
/************************************************************/

//overloaded assignment operator
Node & const Node::operator= (Node & const rhs)
{
	mRecordNumber = rhs.getRecordNumber();
	mID = rhs.getID();
	mName = rhs.getName();
	mEmail = rhs.getEmail();
	mUnits = rhs.getUnits();
	mProgram = rhs.getProgram();
	mLevel = rhs.getLevel();
	mNumberAbsences = rhs.getNumberAbsences();
	mAbsentDate = rhs.getAbsentDate();
	mPNext = nullptr;
	return rhs;
}

//insert all absent dates to a file (most recent comes last)
//move the top item of the stack to other stack (s2)
//then move each item of s2 back to the stack
//post condition: stack has at least one item
void Node::insertAbsentDates(ofstream & outFile)
{
	int indexStack = mAbsentDate.getCurrentSize() - 1;
	Stack s2(indexStack + 1);
	int indexS2 = 0;
	
	//move all items from the absence date stack to s2
	for (; indexStack >= 0; indexStack--)
	{
		s2.getPHead()[indexS2] = mAbsentDate.getPHead()[indexStack]; // move one item
		s2.setCurrentSize(s2.getCurrentSize() + 1); //increase current size of s2
		mAbsentDate.setCurrentSize(mAbsentDate.getCurrentSize() - 1); //decrease current size of the stack
		indexS2++;
	}

	//move each item from s2 to the stack while inserting the item to the file
	indexStack = 0;
	indexS2 -= 1;
	for (; indexS2 > 0; indexS2--)
	{
		outFile << s2.getPHead()[indexS2] << ","; //insert the date to the file
		mAbsentDate.getPHead()[indexStack] = s2.getPHead()[indexS2]; // move one item back to the stack
		s2.setCurrentSize(s2.getCurrentSize() - 1); //decrease current size of s2
		mAbsentDate.setCurrentSize(mAbsentDate.getCurrentSize() + 1); //increase current size of the stack
		indexStack++;
	}

	//last item
	outFile << s2.getPHead()[indexS2]; //insert the date to the file
	mAbsentDate.getPHead()[indexStack] = s2.getPHead()[indexS2]; // move one item back to the stack
	s2.setCurrentSize(s2.getCurrentSize() - 1); //decrease current size of s2
	mAbsentDate.setCurrentSize(mAbsentDate.getCurrentSize() + 1); //increase current size of the stack
	indexStack++;
}

/************************************************************/
/*********Non member functions*******************************/
/************************************************************/

//overloaded operator<< : insert content of the given node to an ostream
//content inserted includes the most recent absent date
ostream & operator<< (ostream &lhs, Node & rhs)
{
	string date = "No absence.";
	if (!rhs.getAbsentDate().isEmpty()) //if there is an absence
		date = rhs.getAbsentDate().peek();
	lhs << endl << "Student " << rhs.getRecordNumber() << ":" << endl;
	lhs << std::left << "ID: " << rhs.getID() << setw(6) <<  "\tName: " <<
		setw(20) << rhs.getName() << setw(7) << "Email: " << rhs.getEmail() << endl;
	lhs << "Units: " << rhs.getUnits() << "\tProgram: " << rhs.getProgram() << "\t\tLevel: " << rhs.getLevel() << endl;
	lhs << "Number of Absences: " << rhs.getNumberAbsences() << "\t\tMost Recent Absent Date: " << date;
	return lhs;
} 