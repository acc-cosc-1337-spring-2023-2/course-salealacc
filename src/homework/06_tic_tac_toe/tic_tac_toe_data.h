//h
#include "tic_tac_toe.h"
#include <vector>
#include <memory>

using std::vector, std::unique_ptr;

#ifndef TICTACTOE_DATA_H
#define TICTACTOE_DATA_H

class TicTacToeData
{
    public:
        void save_games(const vector<unique_ptr<TicTacToe>>& games);
        vector<unique_ptr<TicTacToe>> get_games();

};

#endif