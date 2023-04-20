#include "tic_tac_toe_4.h"
#include<cmath>
#include<iostream>

using std::ostream;

/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/
bool TicTacToe4::check_column_win(int column) {
    if(pegs[column] != " ") {
        return pegs[column] == pegs[column+4] && 
               pegs[column] == pegs[column+8] &&
               pegs[column] == pegs[column+12];
    } else {
        return false;
    }
}


/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal 
12,13,14, 15 are equal
*/
bool TicTacToe4::check_row_win(int row) {
    auto pivot = 4*row;
    if (pegs[pivot] != " ") {
        return pegs[pivot] == pegs[pivot+1] &&
               pegs[pivot] == pegs[pivot+2] &&
               pegs[pivot] == pegs[pivot+3];
    } else {
        return false;
    }
}


/*
class function check_diagonal_win
Win diagonally
0, 1,  2,  3
4, 5,  6,  7
8, 9, 10, 11
12,13,14, 15

*/
bool TicTacToe4::check_diagonal_win() 
{   
    bool diag1 = false, 
         diag2 = false;

    if(pegs[0] != " ") {
        diag1 = (pegs[0] == pegs[5]) &&
                (pegs[5] == pegs[10]) &&
                (pegs[10] == pegs[15]);  
    }

    if(pegs[3] != " ") {
        diag1 = (pegs[3] == pegs[6]) &&
                (pegs[6] == pegs[9]) &&
                (pegs[9] == pegs[12]);  
    }
    
    return diag1 || diag2;
}