/****************************************************************************
* Author: Ngoc Duong														*
* Assignment: PA6 - CPTS 122												*
* This file declares a class Node which represents a node in a List			*
****************************************************************************/

#include <iomanip>
#include <fstream>
#include "Stack.h"

using std::string;
using std::ostream;
using std::ofstream;
using std::cout;
using std::endl;
using std::setw;

class Node
{
	public:
		//constructors
		Node(); //default
		Node(unsigned int recordNumber, unsigned int ID, string & name,
			string & email, string & units, string & program, string & level,
			unsigned int numberAbsences, Stack & absentDate); //parametrized
		Node(Node & const pNode); //copy
		//getters
		unsigned int getRecordNumber() const; 
		unsigned int getID() const; 
		const string & getName() const;
		const string & getEmail() const;
		const string & getUnits() const; 
		const string & getProgram() const;
		const string & getLevel() const; 
		unsigned int getNumberAbsences() const;
		Stack & getAbsentDate();
		Node * getPNext() const;
		//setters
		void setRecordNumber(unsigned int recordNumber);
		void setID(unsigned int ID);
		void setName(const string & name);
		void setEmail(const string & email);
		void setUnits(const string & units);
		void setProgram(const string & program);
		void setLevel(const string & level);
		void setNumberAbsences(unsigned int numberAbsences);
		void setAbsentDate(const Stack & absentDates);
		void setPNext(Node * const node);
		//other functions
		Node & const operator= (Node & const rhs);//overloaded assignment operator
		void insertAbsentDates(ofstream & outFile); //insert all absent dates to a file (most recent comes last)
		//destructor
		~Node(); //do nothing
	private:
		unsigned int mRecordNumber; //max 3 digits
		unsigned int mID; //max 9 digits
		string mName; //last, first
		string mEmail;
		string mUnits; //number of credits for class or AU for audit
		string mProgram; //major
		string mLevel; // freshman, sophomore, junior, senior, graduate
		unsigned int mNumberAbsences;
		Stack mAbsentDate; //contains a string (date) array
		Node *mPNext;
};

//overloaded operator<< : insert content of the given node to an ostream
//content inserted includes the most recent absent date
ostream & operator<< (ostream &lhs, Node & const rhs);