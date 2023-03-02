#include <string>
#include <func.h>
#include <iostream>

using std::string, std::cout, std::cin;

/*
use a vector of int with values 8, 4, 20, 88, 66, 99

Prompt user for 1 for Get Max from vector and 2 for Get primes.
Prompt user for a number and return max value or list of primes
and display them to screen.
Program continues until user decides to exit.

*/
int main() 
{
	int prompt;
	string dna_string;

	do {
		cout << "MAIN MENU.\n";
		cout << "1 - Get GC Content.\n";
		cout << "2 - Get DNA Complement.\n";
		cout << "3 - Exit.\n";
		cout << "> ";

		cin >> prompt;

		if (prompt == 1 || prompt == 2) {
			cout << "Enter a DNA string: ";
			cin >> dna_string;
		}

		switch (prompt) {
			case 1:
				cout << "The GC content of " << dna_string << " is " << get_gc_content(dna_string) * 100 << "%\n";
				break;

			case 2:
				cout << "The DNA complement of " << dna_string << " is " << get_dna_complement(dna_string) << "\n";
				break;

			case 3:
			{
				char confirm;
				cout << "Are you sure you want to exit? [y/n]\n";
				cout << "> ";
				cin >> confirm;
				
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