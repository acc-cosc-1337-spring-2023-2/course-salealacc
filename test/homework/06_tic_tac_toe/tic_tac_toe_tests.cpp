#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification")
{
	REQUIRE(true == true);
}

TEST_CASE("Verify Tic Tac Toe game", "validation")
{
	TicTacToe game;
	game.start_game("X");
	for (int i = 1; i <= 9; i++) 
	{
		game.mark_board(i);
		if (i == 9) {
			REQUIRE(game.game_over() == true);
		} else {
			REQUIRE(game.game_over() == false);
		}
	}
	game.display_board();
}
