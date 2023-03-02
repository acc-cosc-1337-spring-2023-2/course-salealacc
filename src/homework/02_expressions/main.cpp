//write include statements
#include "hwexpressions.h"
#include <iostream>

//write namespace using statement for cout
using std::cout, std::cin;

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	double meal_amount, 
		   tip_rate, 
		   tip_amount, 
		   tax_amount, 
		   total;

	cout << "Price of meal: ";
	cin >> meal_amount;

	tax_amount = get_sales_tax_amount(meal_amount);

	cout << "Tip rate: ";
	cin >> tip_rate;

	tip_amount = get_tip_amount(meal_amount, tip_rate);

	total = meal_amount + tip_amount + tax_amount;

	cout << "Meal Amount: " << meal_amount << "\n";
	cout << "Sales Tax: " << tax_amount << "\n";
	cout << "Tip Amount: " << tip_amount << "\n";
	cout << "Total: " << total << "\n";

	return 0;
}
