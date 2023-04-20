#include "tic_tac_toe_manager.h"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_data.h"
#include <iostream>
#include <string>
#include <memory>

using std::cout, std::cin, std::tolower, std::unique_ptr, std::make_unique;

void titlescreen(unique_ptr<TicTacToe>& game, string &first_player) 
{
	cout << "\n---TIC TAC TOE---\n";

	int selection;

	do {
		cout << "Choose a grid size (3 or 4): ";
		cin >> selection;
	} while(selection != 3 && selection != 4);

	if(selection == 3) {
		game = make_unique<TicTacToe3>();
	} else {
		game = make_unique<TicTacToe4>();
	}

	do {
		cout << "Please input the first player (X or O): ";
		cin >> first_player;
	} while (first_player != "X" && first_player != "O");
}

void gameloop(unique_ptr<TicTacToe>& game, TicTacToeManager& manager) 
{
	do {
		cin >> *game;
		cout << *game;
	} while (!game->game_over());

	cout << "END OF GAME\n";
	cout << "WINNER: " << game->get_winner() << "\n";

	manager.save_game(game);
}


int main() 
{
	string first_player;
	char prompt;
	unique_ptr<TicTacToe> game;
	TicTacToeData data;
	TicTacToeManager manager(data);

	int owins, xwins, ties;

	do {

		titlescreen(game, first_player);

		game->start_game(first_player);

		gameloop(game, manager);

		manager.get_winner_total(owins, xwins, ties);
		cout << "SCORE: X - " << xwins << " | O - " << owins << " | Ties - " << ties << "\n"; 

		cout << "Do you want to play again? (y/n): ";
		cin >> prompt;

	} while (tolower(prompt) == 'y');

	cout << "GAME HISTORY:\n";
	cout << manager;

	return 0;
}