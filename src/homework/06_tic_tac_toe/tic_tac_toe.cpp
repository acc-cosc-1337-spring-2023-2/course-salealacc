#include "tic_tac_toe.h"
#include<iostream>
#include<cmath>

using std::cout, std::cin, std::ostream, std::istream;

//cpp
bool TicTacToe::check_row_win(int row)
{
    return false;
}

bool TicTacToe::check_column_win(int column)
{
    return false;
}

bool TicTacToe::check_diagonal_win() 
{   
    return false;
}

bool TicTacToe::game_over() {

    for(int i = 0; i < sqrt(pegs.size()); i++) {
        if (check_row_win(i) || check_column_win(i)) {
            set_winner();
            return true;
        }
    }

    if (check_diagonal_win()) {
        set_winner();
        return true;
    }

    if (check_board_full()) {
        winner = "C";
        return true;
    }

    return false;
}

void TicTacToe::start_game(string first_player)
{
    if(first_player != "X" && first_player != "O")
    {
        cout << "Player must be X or O, please try again.";
    } else {
        player = first_player;
        clear_board();
    }
}

void TicTacToe::mark_board(int position)
{
    pegs[position-1] = player;
    set_next_player();
}

string TicTacToe::get_player() const
{
    return player;
}

 string TicTacToe::get_winner() const 
 {
    return winner;
 };

void TicTacToe::set_next_player()
{
    if (player == "X") {
        player = "O";
    } else {
        player = "X";
    }
}

void TicTacToe::set_winner() {
    if (player == "X") {
        winner = "O";
    } else {
        winner = "X";
    }
}

bool TicTacToe::check_board_full() const
{
    
    bool isFull = true;
    for (auto peg : pegs) 
    {
        if (peg == " ") 
        {
            isFull = false;
        }
    }
    return isFull;
}

void TicTacToe::clear_board()
{
    for (auto& peg : pegs) {
        peg = " ";
    }
}

// Display board
ostream& operator<<(ostream& out, const TicTacToe& game)
{
    int length = game.pegs.size();
    int vdimension = sqrt(length);
    for (auto i = 0; i < length; i++) 
    {
        out << game.pegs[i];

        if (!((i+1) % vdimension)) {
            out << "\n";
        } else {
            out << " | ";
        }
    }

    return out;
}

// Get player input
istream& operator>>(istream& in, TicTacToe& game)
{
    int position;
    int vdimension = sqrt(game.pegs.size());
    string prompt_position;

    if (vdimension == 4) {
        prompt_position = " enter a position (1 - 16 to play): ";
    } else {
        prompt_position = " enter a position (1 - 9 to play): ";
    }
    
    cout << "Player " << game.get_player() << prompt_position;
    
    cin >> position;
    
    game.mark_board(position);                                     

    return in;
}
