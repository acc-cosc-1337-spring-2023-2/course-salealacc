//h
#include "tic_tac_toe.h"

#ifndef TICTACTOE3_H
#define TICTACTOE3_H

class TicTacToe3 : public TicTacToe
{
    public:
        TicTacToe3() : TicTacToe(3){}

    private:
        bool check_diagonal_win();
        bool check_row_win(int row);
        bool check_column_win(int column);
};

#endif