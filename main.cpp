/****************************************************************************
* Author: Ngoc Duong														*
* Assignment: PA6 - CPTS 122												*
* This program manages attendance of students for a course. Once per school	*
*		term, student info is loaded from a file. During the term, manager	*
*		can view info, mark absent students, edit absent dates and generates*
*		desired reports.													*
* EXTRA WORK: 1/ COMPLETED EDIT ABSENT DATES								*
*			  2/ OPERATED STACKS PROPERLY (LIFO) as in						*
*			void Node::insertAbsentDates(ofstream & outFile) in ListNode.cpp*
*			and void Menu::editAbsence() in Program.cpp				     	*
****************************************************************************/

#include "program.h"

int main()
{
	Menu menu;
	menu.runProgram();
	return 0;
}