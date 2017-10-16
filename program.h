/****************************************************************************
* Author: Ngoc Duong														*
* Assignment: PA6 - CPTS 122												*
* This file declare a class Menu which generates the entire application.	*
****************************************************************************/

#include <fstream>
#include <sstream> //convert string to int
#include "List.h"

using std::ifstream;
using std::ofstream;
using std::getline;
using std::endl;
using std::cin;
using std::cout; 

class Menu
{
public:
	//constructors
	Menu(); //default
	Menu(string & infileName, string & masterFileName,
		string & allStudentReportName, string & thresholdReportName); //parametrized
	//getters
	const List & getList() const;
	const string & getInfileName() const;
	const string & getMasterFileName() const;
	const string & getAllStudentReportName() const;
	const string & getThresholdReportName() const;
	//setters
	void setList(List & const newList);
	void setInfileName(string & const fileName);
	void setMasterFileName(string & const fileName);
	void setAllStudentReportName(string & const fileName);
	void setThresholdReportName(string & const fileName);
	//other member functions
	void displayMenu() const; //display option menu to screen
	void loadFromInfile(); //read all records from a file with mInfileName name to masterList
	void loadFromMasterFile(); //read all records from a file with mMasterFileName name to masterList
	void storeToMasterFile(); //store the contents of the master list’s nodes to master.txt
	void markAbsence(); //traverse through masterList, ask user if a current student is absent today,
						// then update absence info for the student
	void editAbsence(); //Prompts for an ID number to edit. Prompts for the date of absence to edit
	void classReport(int thresHold); //overwrite info of students whose number of absences is greater 
									// than or equal to the threshold from masterList to mThresholdReportName
	void classReport(); //overwrite info of all students from masterList to mAllStudentReportName
	void generateReport(); //generate a report either of all students or those whose absences are at least a threshold
	void runProgram(); //operate the whole application
	void get_option(int &option); //get an option (1-7) from the option menu
	//Note: this class does not require a destructor

private:
	List mMasterList;
	string mInfileName; //text file containing students info of a semester
	string mMasterFileName; //text file containing current info of all students at a time
	string mAllStudentReportName; //text file containing info of all students with absence info
	string mThresholdReportName; //text file containing infor of students who were absent more than threshold days
};
