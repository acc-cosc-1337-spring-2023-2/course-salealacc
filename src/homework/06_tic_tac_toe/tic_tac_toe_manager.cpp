#include<iostream>
#include<memory>
#include"tic_tac_toe_manager.h"
#include "tic_tac_toe_data.h"

using std::cout, std::string, std::ostream,
      std::unique_ptr, std::move;
//cpp

TicTacToeManager::TicTacToeManager(TicTacToeData& d) : data(d)
{
    for (auto& game : data.get_games())
    {
        save_game(game);
    }
}

TicTacToeManager::~TicTacToeManager()
{
    data.save_games(games);
}

void TicTacToeManager::save_game(unique_ptr<TicTacToe>& game)
{
    update_winner_count(game->get_winner());
    games.push_back(move(game));
}

void TicTacToeManager::get_winner_total(int& o, int& x, int& t)
{
    o = o_win;
    x = x_win;
    t = ties;   
}

void TicTacToeManager::update_winner_count(string winner)
{
    if(winner == "X") {
        x_win++;

    } else if (winner == "O") {
        o_win++;
    } 
    else {
        ties++;
    }
}

ostream& operator<<(ostream& out, const TicTacToeManager& manager)
{
    for (int i = 0; i < manager.games.size(); i++) {
        out << "GAME " << i+1 << "\n";
        out << *manager.games[i];
    }
    return out;
}