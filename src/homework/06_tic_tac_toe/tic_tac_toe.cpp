#include "tic_tac_toe.h"
#include<iostream>

using std::cout;

//cpp
bool TicTacToe::game_over() {
    return check_board_full();
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

void TicTacToe::display_board() const
{
    int length = pegs.size();
    for (auto i = 0; i < length; i++) 
    {
        cout << pegs[i];

        if (!((i+1) % 3)) {
            cout << "\n";
        } else {
            cout << " | ";
        }
    }
}

void TicTacToe::set_next_player()
{
    if (player == "X") {
        player = "O";
    } else {
        player = "X";
    }
}

bool TicTacToe::check_board_full()
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
    for (auto peg : pegs) {
        peg = " ";
    }
}
