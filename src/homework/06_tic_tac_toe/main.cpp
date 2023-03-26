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

void gameloop(TicTacToe game) 
{
	int position;
	do {
		cout << "Player " << game.get_player() << " enter a position (1 - 9 to play, 0 to quit): ";
		cin >> position;
		
		if (position != 0) {
			game.mark_board(position);
			game.display_board();
		}
	} while(position != 0 && !game.game_over());
	cout << "END OF GAME\n";
}


int main() 
{
	string first_player;
	char prompt;
	TicTacToe game;

	do {

		titlescreen(first_player);

		game.start_game(first_player);

		gameloop(game);

		cout << "Do you want to play again? (y/n): ";
		cin >> prompt;

	} while (tolower(prompt) == 'y');

	return 0;
}