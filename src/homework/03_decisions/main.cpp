//write include statements
#include<iostream>
#include "decisions.h"

using std::cout, std::cin, std::string;

int main() 
{
	int option, grade;
	string letterGrade;

	cout << "MAIN MENU" << '\n';
	cout << "1. Get letter grade using if" << '\n';
	cout << "2. Get letter grade using switch" << '\n';
	cout << "3. Exit" << '\n';

	cout << "> ";
	cin >> option;

	if (option != 1 && option != 2) {
		cout << "Exiting.\n";
		return 0;
	}

	cout << "Input letter grade: ";
	cin >> grade;

	if(grade > 100 || grade < 0) {
		cout << "Number is out of range\n";
		return 1;
	}
	
	switch(option) {
		case 1:
			letterGrade = get_letter_grade_using_if(grade);
			break;
		case 2:
			letterGrade = get_letter_grade_using_switch(grade);
			break;
	}

	cout << "Number grade: " << grade << "\n";
	cout << "Letter grade: " << letterGrade << "\n";

	return 0;
}