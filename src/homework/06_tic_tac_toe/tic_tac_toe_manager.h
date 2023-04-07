//h
#include<string>
#include<vector>
#include "tic_tac_toe.h"

using std::string, std::vector, std::ostream;

#ifndef TICTACTOE_MANAGER_H
#define TICTACTOE_MANAGER_H

class TicTacToeManager
{

    friend ostream& operator<<(ostream& out, const TicTacToeManager& manager);

    public:
        void save_game(TicTacToe game);
        void get_winner_total(int& o, int& x, int& t);

    private:
        vector<TicTacToe> games;
        int x_win = 0;
        int o_win = 0;
        int ties = 0;

        void update_winner_count(string winner);
};

#endif