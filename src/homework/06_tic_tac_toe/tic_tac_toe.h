//h
#include<string>
#include<vector>

using std::string, std::vector, std::ostream, std::istream;

#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{

    friend ostream& operator<<(ostream& out, const TicTacToe& game);
    friend istream& operator>>(istream& in, TicTacToe& game);

    public:
        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player() const;
        string get_winner() const;

    private:
        string player;
        string winner;
        vector<string> pegs = {" ", " ", " ", " ", " ", " ", " ", " ", " "};

        void set_next_player();
        void set_winner();

        bool check_board_full();
        void clear_board();

        bool check_diagonal_win();
        bool check_row_win(int row);
        bool check_column_win(int column);
};

#endif