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
        TicTacToe(int size) : pegs(size*size, " "){}
        TicTacToe(vector<string> p, string win) : pegs(p), winner(win){}

        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player() const;
        string get_winner() const;
        vector<string> get_pegs() const;

    protected:
        vector<string> pegs;

        virtual bool check_diagonal_win() = 0;
        virtual bool check_row_win(int row) = 0;
        virtual bool check_column_win(int column) = 0;

    private:
        string player;
        string winner;

        void set_next_player();
        void set_winner();

        bool check_board_full() const;
        void clear_board();
};

#endif