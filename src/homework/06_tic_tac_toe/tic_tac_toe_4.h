//h
#include "tic_tac_toe.h"
#include<iostream>

using std::ostream;

#ifndef TICTACTOE4_H
#define TICTACTOE4_H

class TicTacToe4 : public TicTacToe
{
    public:
        TicTacToe4() : TicTacToe(4){}
        TicTacToe4(vector<string> p, string win) : TicTacToe(p, win){}

    private:
        bool check_diagonal_win();
        bool check_row_win(int row);
        bool check_column_win(int column);
};

#endif