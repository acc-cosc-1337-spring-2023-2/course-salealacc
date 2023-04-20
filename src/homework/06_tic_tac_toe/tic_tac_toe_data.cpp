//cpp
#include "tic_tac_toe_data.h"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>

using std::vector, 
      std::unique_ptr, std::make_unique, 
      std::ofstream, std::ifstream, 
      std::cout;

const string GAME_DATA_FILE = "tictactoe.dat";

void TicTacToeData::save_games(const vector<unique_ptr<TicTacToe>>& games)
{
    cout << "Saving games...\n";
    ofstream file(GAME_DATA_FILE);
    
    for (const auto& game : games) 
    {
        for (auto ch : game->get_pegs())
        {
            file << ch;
        }
        file << game->get_winner() << "\n";
    }
    file.close();
    cout << "Games saved!\n";
}

vector<unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
    vector<unique_ptr<TicTacToe>> boards;
    ifstream file(GAME_DATA_FILE);
    string line;

    if(file.is_open())
    {
        cout << "Loading data...\n";

        while(getline(file, line))
        {
            unique_ptr<TicTacToe> board;
            vector<string> pegs;
            string winner;

            for (int i = 0; i < line.length()-1; i++) {
                pegs.emplace_back(string(1, line[i]));
            }
            winner = line.back();

            if (pegs.size() == 9) {
                board = make_unique<TicTacToe3>(pegs, winner);
            } else {
                board = make_unique<TicTacToe4>(pegs, winner);
            }

            boards.emplace_back(std::move(board));
        }
        file.close();

        cout << "Data loaded.\n";
    }
    else
    {
        cout<<"Unable to open the file\n";
    }

    return boards;
}