#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification")
{
	REQUIRE(true == true);
}

// Tests for player initialization
TEST_CASE("Test first player set to X", "validation")
{
	TicTacToe game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O", "validation")
{
	TicTacToe game;
	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}

// Tests for game over
TEST_CASE("Test game over if 9 slots are selected", "validation")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(4);
	for (int i = 1; i <= 9; i++) 
	{
		if (i != 4) game.mark_board(i);
	}
	game.game_over();
	// game.display_board();

	REQUIRE(game.get_winner() == "C");
}

// Tests for column wins
TEST_CASE("Test win by first column", "validation")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1);
	game.mark_board(9);
	game.mark_board(4);
	game.mark_board(5);
	game.mark_board(7);
	// 	game.display_board();

	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by second column", "validation")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(2);
	game.mark_board(9);
	game.mark_board(5);
	game.mark_board(4);
	game.mark_board(8);
	// game.display_board();
	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by third column", "validation")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(3);
	game.mark_board(1);
	game.mark_board(6);
	game.mark_board(4);
	game.mark_board(9);
	// game.display_board();

	REQUIRE(game.game_over() == true);
}

// Tests for row wins
TEST_CASE("Test win by first row", "validation")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1);
	game.mark_board(9);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(3);
	// 	game.display_board();

	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by second row", "validation")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(4);
	game.mark_board(9);
	game.mark_board(5);
	game.mark_board(3);
	game.mark_board(6);
	// game.display_board();
	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by third row", "validation")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(7);
	game.mark_board(1);
	game.mark_board(8);
	game.mark_board(4);
	game.mark_board(9);
	// game.display_board();

	REQUIRE(game.game_over() == true);
}

// Tests for diagonal wins
TEST_CASE("Test win by top left diagonal", "validation")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(3);
	game.mark_board(9);
	// game.display_board();

	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by bottom left diagonal", "validation")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(7);
	game.mark_board(9);
	game.mark_board(5);
	game.mark_board(4);
	game.mark_board(3);
	// game.display_board();
	REQUIRE(game.game_over() == true);
}