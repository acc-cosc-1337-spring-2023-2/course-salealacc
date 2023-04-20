//write include statement for decisions header
#include "decisions.h"
#include<string>

using std::string;

//Write a function(s) prototype  here
string get_letter_grade_using_if(int grade)
{
    if(grade >= 90) {
        return "A";
    } 
    else if (grade >= 80) {
        return "B";
    }  
    else if (grade >= 70) {
        return "C";
    }
    else if (grade >= 60) {
        return "D";
    }
    else {
        return "F";
    }
}

string get_letter_grade_using_switch(int grade)
{
    switch (grade) {
        case 90 ... 100:
            return "A";
        case 80 ... 89:
            return "B";
        case 70 ... 79:
            return "C";
        case 60 ... 69:
            return "D";
        default:
            return "F";
    }
}

//Write code for function(s) code here