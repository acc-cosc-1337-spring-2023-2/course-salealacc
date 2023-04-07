#include "tic_tac_toe_manager.h"
#include "tic_tac_toe.h"
#include <iostream>
#include <string>

using std::cout, std::cin, std::tolower;

void titlescreen(string &first_player) 
{
	cout << "\n---TIC TAC TOE---\n";
	do {
		cout << "Please input the first player (X or O): ";
		cin >> first_player;
	} while (first_player != "X" && first_player != "O");
}

void gameloop(TicTacToe& game, TicTacToeManager& manager) 
{
	do {
		cin >> game;
		cout << game;
	} while (!game.game_over());

	cout << "END OF GAME\n";
	cout << "WINNER: " << game.get_winner() << "\n";

	manager.save_game(game);
}


int main() 
{
	string first_player;
	char prompt;
	TicTacToe game;
	TicTacToeManager manager;
	int owins, xwins, ties;

	do {

		titlescreen(first_player);

		game.start_game(first_player);

		gameloop(game, manager);

		manager.get_winner_total(owins, xwins, ties);
		cout << "SCORE: X - " << xwins << " | O - " << owins << " | Ties - " << ties << "\n"; 

		cout << "Do you want to play again? (y/n): ";
		cin >> prompt;

	} while (tolower(prompt) == 'y');

	cout << "SESSION OVERVIEW:\n";
	cout << manager;

	return 0;
}