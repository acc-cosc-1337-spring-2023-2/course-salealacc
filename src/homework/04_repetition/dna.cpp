//add include statements
#include "dna.h"
#include<iostream>
#include<limits>

using namespace std;

//add function(s) code here
int factorial(int num) {
    int product = 1;
    while (num > 1) {
        product *= num;
        num--;
    }
    return product;
}

int gcd(int num1, int num2) {
    while (num1 != num2) {
        if (num1 < num2) {
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }
        if (num1 > num2) {
            num1 -= num2;
        }
    }
    return num1;
}

/* 
    Unsure on how to unit test functions that take user input,
    but without these error catches the main function will run forever
    if given a wrong input type.
*/
void handleCinErr() {
    cin.clear();
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input, please try again.\n";
    cout << ">>> ";
}

void validateCin(char &var) {
    cin >> var;

    if(cin.fail()) {
        handleCinErr();
        validateCin(var);
    }
}

void validateCin(int &var) {
    cin >> var;

    if(cin.fail()) {
        handleCinErr();
        validateCin(var);
    }
}