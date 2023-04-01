#include "tic_tac_toe.h"
#include<iostream>

using std::cout;

//cpp
bool TicTacToe::check_row_win(int row) {
    auto pivot = 3*row;
    if (pegs[pivot] != " ") {
        return pegs[pivot] == pegs[pivot+1] &&
               pegs[pivot] == pegs[pivot+2];
    } else {
        return false;
    }
}

bool TicTacToe::check_column_win(int column) {
    if(pegs[column] != " ") {
        return pegs[column] == pegs[column+3] && 
               pegs[column] == pegs[column+6];
    } else {
        return false;
    }
}

bool TicTacToe::check_diagonal_win() 
{   
    if(pegs[4] != " ") {
        return (pegs[0] == pegs[4] && pegs[4] == pegs[8]) || 
               (pegs[2] == pegs[4] && pegs[4] == pegs[6]);
    } else {
        return false;
    }
}

bool TicTacToe::game_over() {

    for(int i = 0; i < 3; i++) {
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

void TicTacToe::set_winner() {
    if (player == "X") {
        winner = "O";
    } else {
        winner = "X";
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
