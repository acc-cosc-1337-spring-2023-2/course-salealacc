//write include statements
#include<iostream>
#include "dna.h"
//write using statements
using std::cout;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	int prompt;

	do {
		cout << "MAIN MENU.\n";
		cout << "1 - Factorial.\n";
		cout << "2 - Greatest Common Divisor.\n";
		cout << "3 - Exit.\n";
		cout << ">>> ";

		validateCin(prompt);

		switch (prompt) {
			case 1:
				int num;

				cout << "Enter a number: ";
				validateCin(num);

				cout << "The factorial of " << num << " is " << factorial(num) << '\n';

				break;

			case 2:
				int num1, num2;

				cout << "Enter the first number: ";
				validateCin(num1);

				cout << "Enter the second number: ";
				validateCin(num2);

				cout << "The greatest common divisor of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << "\n";
				break;

			case 3:
			{
				char confirm;
				cout << "Are you sure you want to exit? [y/n]\n";
				cout << ">>> ";
				validateCin(confirm);
				
				if (std::tolower(confirm) == 'y') {
					cout << "Exiting.\n";
				} else {
					prompt = 0;
				}
				
				break;
			}

			default:
				cout << "Invalid option.\n";
				prompt = 0;
		}

		cout << "\n";

	} while (prompt != 3);

	return 0;
}