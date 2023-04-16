#include "tic_tac_toe_3.h"

/*
class function check_column_win
Win by column if and return true if
0,3, and 6 are equal
1, 4, and 7
2, 5, and 8
else
false
*/
bool TicTacToe3::check_column_win(int column) {
    if(pegs[column] != " ") {
        return pegs[column] == pegs[column+3] && 
               pegs[column] == pegs[column+6];
    } else {
        return false;
    }
}


/*
class function check_row_win
Win by row if
0, 1, 2 are equal
3,4,5 are equal
6,7,8 are equal
*/
bool TicTacToe3::check_row_win(int row) {
    auto pivot = 3*row;
    if (pegs[pivot] != " ") {
        return pegs[pivot] == pegs[pivot+1] &&
               pegs[pivot] == pegs[pivot+2];
    } else {
        return false;
    }
}


/*
class function check_diagonal_win
Win diagonally
0 1 2
3 4 5
6 7 8

*/
bool TicTacToe3::check_diagonal_win() 
{   
    if(pegs[4] != " ") {
        return (pegs[0] == pegs[4] && pegs[4] == pegs[8]) || 
               (pegs[2] == pegs[4] && pegs[4] == pegs[6]);
    } else {
        return false;
    }
}