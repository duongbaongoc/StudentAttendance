/****************************************************************************
* Author: Ngoc Duong														*
* Assignment: PA6 - CPTS 122												*
* This file defines all functions for class Menu.							*
****************************************************************************/

#include "program.h"
 
/************************************************************/
/*********Constructors***************************************/
/************************************************************/
 
//default constructor
Menu::Menu()
{
	mMasterList = *(new List());
	mInfileName = "classList.csv";
	mMasterFileName = "master.txt";
	mAllStudentReportName = "allStudentReport.txt";
	mThresholdReportName = "thresholdReport.txt";
}

//parametrized constructor
Menu::Menu(string & infileName, string & masterFileName,
		string & allStudentReportName, string & thresholdReportName)
{
	mMasterList = *(new List());
	mInfileName = infileName;
	mMasterFileName = masterFileName;
	mAllStudentReportName = allStudentReportName;
	mThresholdReportName = thresholdReportName;
}

/************************************************************/
/*********Getters********************************************/
/************************************************************/

//get mMasterList
const List & Menu::getList() const
{ 
	return mMasterList;
}

//get mInfileName
const string & Menu::getInfileName() const
{
	return mInfileName;
}

//get mMasterFileName
const string & Menu::getMasterFileName() const
{
	return mMasterFileName;
}

//get mAllStudentReportName
const string & Menu::getAllStudentReportName() const
{
	return mAllStudentReportName;
}

//get mThresholdReportName
const string & Menu::getThresholdReportName() const
{
	return mThresholdReportName;
}

/************************************************************/
/*********Setters********************************************/
/************************************************************/

//set mMasterList
void Menu::setList(List & const newList)
{
	mMasterList = newList;
}

//set mInfileName
void Menu::setInfileName(string & const fileName)
{
	mInfileName = fileName;
}

//set mMasterFileName
void Menu::setMasterFileName(string & const fileName)
{
	mMasterFileName = fileName;
}

//set mAllStudentReport
void Menu::setAllStudentReportName(string & const fileName)
{
	mAllStudentReportName = fileName;
}

//set mThresholdReport
void Menu::setThresholdReportName(string & const fileName)
{
	mThresholdReportName = fileName;
}

/************************************************************/
/*********Other member functions*****************************/
/************************************************************/

//display a option menu to screen
void Menu::displayMenu() const
{
	cout << "\t1.    Import course list" << endl;
	cout << "\t2.    Load master list" << endl;
	cout << "\t3.    Store master list" << endl;
	cout << "\t4.    Mark absences" << endl;
	cout << "\t5.    BONUS: Edit absences" << endl;
	cout << "\t6.    Generate report" << endl;
	cout << "\t7.    Exit" << endl;
}

//read all records from a file with mInfileName name to masterList
//if masterList is not empty then its content will be overwritten
void Menu::loadFromInfile()
{
	string line;
	ifstream file;
	std::stringstream convertingFile; //convert from string to int

	//variables that contain info to make nodes
	unsigned int recordNumber = 0; //max 3 digits
	unsigned int ID = 0; //max 9 digits
	string name; //last, first
	string email;
	string units; //number of credits for class or AU for audit
	string program; //major
	string level; // freshman, sophomore, junior, senior, graduate
	unsigned int numberAbsences = 0;
	Stack absentDate = *(new Stack(100)); //contains a string (date) array

	//empty masterList
	Node *pCur = mMasterList.getPHead(), *pPrev = nullptr;
	while (pCur != nullptr) //traverse till the end of list
	{
		pPrev = pCur;
		pCur = pCur->getPNext();
		delete pPrev;
	}
	mMasterList.setPHead(nullptr);

	file.open(mInfileName); //open the file to read
	getline(file, line); //discard the first line of file
	while (!file.eof()) //read until end of file
	{
		line = ""; //reset line

		//get all fields of each record
		getline(file, line, ','); //read recordNumber from file
		if (line.length() == 0)
			break;
		convertingFile << line;
		convertingFile >> recordNumber;
		convertingFile.clear();
		getline(file, line, ','); //read ID from file
		convertingFile << line;
		convertingFile >> ID;
		convertingFile.clear();
		getline(file, line, '"'); //read name from file
		getline(file, name, '"');
		getline(file, line, ','); //read email from file
		getline(file, email, ',');
		getline(file, units, ','); //read units from file
		getline(file, program, ','); //read program from file
		getline(file, level); //read level from file
		//Note: numberAbsences and absentDate are left to blank for now

		//make a node for each set of fields
		Node *pMem = new Node(recordNumber, ID, name, email, units, program, level,
			numberAbsences, absentDate);
		//insert the node at front of the list
		mMasterList.insertAtFront(pMem);
	}
	file.close(); //close the file
}

//read all records from a file with  mMasterFileName name to masterList
//if masterList is not empty then its content will be overwritten
void Menu::loadFromMasterFile()
{
	string line, token;
	int beginIndex = 0, endIndex = 0;
	ifstream file;
	std::stringstream convertingFile; //convert from string to int

	//variables that contain info to make nodes
	unsigned int recordNumber = 0; //max 3 digits
	unsigned int ID = 0; //max 9 digits
	string name; //last, first
	string email;
	string units; //number of credits for class or AU for audit
	string program; //major
	string level; // freshman, sophomore, junior, senior, graduate
	unsigned int numberAbsences = 0;

	//empty masterList
	Node *pCur = mMasterList.getPHead(), *pPrev = nullptr;
	while (pCur != nullptr) //traverse till the end of list
	{
		pPrev = pCur;
		pCur = pCur->getPNext();
		delete pPrev;
	}
	mMasterList.setPHead(nullptr);

	file.open(mMasterFileName); //open the file to read
	getline(file, line); //discard the first 2 lines of file
	getline(file, line); //discard the first 2 lines of file
	while (!file.eof()) //read until end of file
	{
		line = ""; //reset line

		//get all fields of each record
		getline(file, line, ','); //read recordNumber from file
		if (line.length() == 0)
			break;
		convertingFile << line;
		convertingFile >> recordNumber;
		convertingFile.clear();
		getline(file, line, ','); //read ID from file
		convertingFile << line;
		convertingFile >> ID;
		convertingFile.clear();
		getline(file, line, '"'); //read name from file
		getline(file, name, '"');
		getline(file, line, ','); //read email from file
		getline(file, email, ',');
		getline(file, units, ','); //read units from file
		getline(file, program, ','); //read program from file
		getline(file, level); //read level from file
		file >> numberAbsences; //read number of absences from file
		Stack absentDate = *(new Stack(25)); //contains a string (date) array - read all absent dates from file
		line = "";
		int numDates = 0;
		getline(file, line); 
		beginIndex = line.find(','); //find the first comma
		endIndex = line.find(',', beginIndex + 1); //find the second comma
		while ((endIndex - beginIndex > 0) && (endIndex - beginIndex < 12) && 
			numDates <= numberAbsences)
		{
			token = line.substr(beginIndex + 1, endIndex - beginIndex - 1);
			absentDate.push(token);
			beginIndex = endIndex;
			endIndex = line.find(',', beginIndex + 1); //find the next comma
			numDates++;
		}


		//make a node for each set of fields
		Node *pMem = new Node(recordNumber, ID, name, email, units, program, level,
			numberAbsences, absentDate);
		//insert the node at front of the list
		mMasterList.insertAtFront(pMem);
	}
	file.close(); //close the file
}

//store (overwrite) the contents of the master list’s nodes to master.txt
void Menu::storeToMasterFile()
{
	ofstream file(mMasterFileName);
	Node *pCur = mMasterList.getPHead();
	file << ",ID,Name,Email,Units,Program,Level" << endl;
	file << "Number of Absence, Absent Dates" << endl;
	while (pCur != nullptr) //traverse through the masterList
	{
		//insert the record to outfile
		file << pCur->getRecordNumber() << ",";
		file << pCur->getID() << ",";
		file << "\"" << pCur->getName() << "\",";
		file << pCur->getEmail() << ",";
		file << pCur->getUnits() << ",";
		file << pCur->getProgram() << ",";
		file << pCur->getLevel() << endl;
		file << pCur->getNumberAbsences();
		if (!(pCur->getAbsentDate().isEmpty())) //if there is an absence
		{
			file << ",";
			pCur->insertAbsentDates(file);
		}
		file << "," << endl;

		pCur = pCur->getPNext(); //advance pCur
	}
	file.close();
}

//this function makes a traverse through the list, ask user if a current student is absent today,
// then update absence info for the student
void Menu::markAbsence()
{
	Node * pCur = mMasterList.getPHead();
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	string isAbsent, today = std::to_string(now->tm_year + 1900) + "-" +
		std::to_string(now->tm_mon + 1) + "-" + std::to_string(now->tm_mday);

	while (pCur != nullptr) //traverse through the list
	{
		system("pause");
		system("cls");

		// display and get current date - codes are given at assignment instruction
		cout << "Today is " << today << endl;

		cout << *pCur << endl; //display info of the student

		do //ask if absent
		{
			cout << "\nIs the student absent today (yes/no)? ";
			cin >> isAbsent;
		} while (isAbsent != "yes" && isAbsent != "no");

		if (isAbsent == "yes")
		{
			pCur->setNumberAbsences(pCur->getNumberAbsences() + 1); //increase ansent days
			pCur->getAbsentDate().push(today); //update the absence stack
			cout << "\n****Change of absent date has been saved.****" << endl;
		}
		cout << endl;

		pCur = pCur->getPNext(); //move to the next student
	}
}

//promts for an ID number to edit. Prompts for the date of absence to edit
//move item out of the stack until found the wanted date to edit
void Menu::editAbsence()
{
	unsigned int ID = 0;
	Node *pCur = mMasterList.getPHead();

	//promt for a valid ID
	cout << "Please enter a student ID to edit (i.e: 23452) : ";
	cin >> ID;
	while (pCur != nullptr && pCur->getID() != ID)
	{
		pCur = pCur->getPNext();
	}

	if (pCur == nullptr)
		cout << "The ID entered is not found." << endl;
	else //found ID -> edit the stack
	{
		int indexStack = pCur->getNumberAbsences() - 1;
		Stack s2(indexStack + 1);
		int indexS2 = 0, whichDate = 0, count = 0;
		string newDate;

		cout << "This student has " << pCur->getNumberAbsences() << " days of absence." << endl;
		do //get a valid date to edit
		{
			if (count == 0) //promt for the first time
				cout << "Which date do you want to edit (i.e: enter a number: 1 for the most recent absent date): ";
			else
				cout << "Your input is invalid. Please enter a number from 1 to " << pCur->getNumberAbsences() << ": ";
			cin >> whichDate;
			count++;
		} while (whichDate < 1 || whichDate > pCur->getNumberAbsences());
		
		//edit the valid date
		for (indexS2 = 0; indexS2 < whichDate; indexS2++) //move items from the stack to s2
		{
			s2.getPHead()[indexS2] = pCur->getAbsentDate().getPHead()[indexStack]; // move one item
			s2.setCurrentSize(s2.getCurrentSize() + 1); //increase current size of s2
			pCur->getAbsentDate().setCurrentSize(pCur->getAbsentDate().getCurrentSize() - 1); //decrease current size of the stack
			indexStack--;
		 }

		indexS2--;
		cout << "Found the date: " << s2.getPHead()[indexS2] << endl;
		cout << "Please enter a new date (i.e: any string): ";
		cin >> newDate;
		s2.getPHead()[indexS2] = newDate;

		indexStack += 1;
		for (; indexS2 >= 0; indexS2--) //move items back from s2 to the stack
		{
			pCur->getAbsentDate().getPHead()[indexStack] = s2.getPHead()[indexS2]; // move one item back to the stack
			s2.setCurrentSize(s2.getCurrentSize() - 1); //decrease current size of s2
			pCur->getAbsentDate().setCurrentSize(pCur->getAbsentDate().getCurrentSize() + 1); //increase current size of the stack
			indexStack++;
		}
	}
}

//overwrite info of students whose number of absences is greater 
// than or equal to the threshold from masterList to mThresholdReportName
void Menu::classReport(int thresHold)
{
	ofstream file(mThresholdReportName);
	Node *pCur = mMasterList.getPHead();

	file << "This is list of students whose number of absences is at least " << thresHold << "." << endl;
	while (pCur != nullptr) //traverse through the masterList
	{
		if ((pCur->getNumberAbsences()) >= thresHold) //only process records whose # absences is greater than threshold
			file << *pCur << endl; //insert the record to outfile
		pCur = pCur->getPNext(); //advance pCur
	}

	file.close();
}

//overwrite info of all students from masterList to mAllStudentReportName
void Menu::classReport()
{
	ofstream file(mAllStudentReportName);
	Node *pCur = mMasterList.getPHead();

	file << "This is list of all students." << endl;
	while (pCur != nullptr) //traverse through the masterList
	{
		file << *pCur << endl; //insert the record to outfile
		pCur = pCur->getPNext(); //advance pCur
	}

	file.close();
}

//generate a report either of all students or those whose absences are at least a threshold
void Menu::generateReport()
{
	int option = 0, count = 0, threshold = 0;
	//display options
	cout << "Which report would you like? " << endl;
	cout << "\t1.\tReport for all students." << endl;
	cout << "\t2.\tReport for students with absences that match or exceed a threshold." << endl << endl;

	do
	{
		if (count == 0) //promt for the first time
			cout << "Please provide an option (i.e: 2): ";
		else
			cout << "Your input is invalid. Please provide an option (i.e: 2): ";
		cin >> option;
		count++;
	} while (option < 1 || option > 2);

	if (option == 1)
		classReport();
	else
	{
		count = 0;
		do
		{
			if (count == 0) //promt for the first time
				cout << "Please provide a threshold (i.e: 3): ";
			else
				cout << "Your input is invalid. Please provide a threshold (i.e: 3): ";
			cin >> threshold;
			count++;
		} while (option < 0 || option > 25);
		classReport(threshold);
	}
}

//operate the whole application
void Menu::runProgram()
{
	int option = 0;
	int threshold = 0;

	//promt a valid option then execute the option
	do
	{
		get_option(option);
		switch (option)
		{
		case 1: //Reads the .csv course file and overwrites the master list
			loadFromInfile();
			cout << mMasterList;
			break;
		case 2: //Populates the master list with previous nodes from master.txt
			loadFromMasterFile();
			cout << mMasterList;
			break;
		case 3: //Stores the contents of the master list’s nodes to master.txt
			storeToMasterFile();
			cout << mMasterList;
			break; 
		case 4: //Mark absences
			markAbsence();
			cout << mMasterList;
			break;
		case 5: //Edit absences
			editAbsence();
			cout << mMasterList;
			break;
		case 6: //Generate report
			generateReport();
			cout << mMasterList;
			break;
		case 7: //Exit.
			storeToMasterFile();
			cout << mMasterList;
			break;
		}
		system("pause");
		system("cls");
	} while (option != 7);
}

//get an option (1-7) from the option menu
void Menu::get_option(int &option)
{
	option = 0; //reset option
	int count = 0;
	displayMenu(); //display option menu
	do
	{
		if (count == 0) //promt for the first time
			cout << "Please provide an option 1-7(i.e: 4): ";
		else
			cout << "Your input is invalid. Please provide an option 1-7(i.e: 4): ";
		cin >> option;
		count++;
	} while (option < 1 || option > 7);
}