#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include<iostream>

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

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second column", "validation")
{
	TicTacToe game;
	game.start_game("O");

	game.mark_board(2);
	game.mark_board(9);
	game.mark_board(5);
	game.mark_board(4);
	game.mark_board(8);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
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

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

// Tests for row wins
TEST_CASE("Test win by first row", "validation")
{
	TicTacToe game;
	game.start_game("O");

	game.mark_board(1);
	game.mark_board(9);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(3);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
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

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third row", "validation")
{
	TicTacToe game;
	game.start_game("O");

	game.mark_board(7);
	game.mark_board(1);
	game.mark_board(8);
	game.mark_board(4);
	game.mark_board(9);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
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

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by bottom left diagonal", "validation")
{
	TicTacToe game;
	game.start_game("O");

	game.mark_board(7);
	game.mark_board(9);
	game.mark_board(5);
	game.mark_board(4);
	game.mark_board(3);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}

TEST_CASE("Test TicTacToeManager get winner total", "validation")
{	
	TicTacToeManager manager;
	TicTacToe game;

	int x_wins, o_wins, ties;

	// Game 1: Win for O
	game.start_game("O");
	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(3);
	game.mark_board(9);
	game.game_over();

	manager.save_game(game);


	// Game 2: Win for X
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(3);
	game.mark_board(9);
	game.game_over();
	manager.save_game(game);


	// Game 3: Tie
	game.start_game("X");
	game.mark_board(4);
	for (int i = 1; i <= 9; i++) 
	{
		if (i != 4) game.mark_board(i);
	}
	game.game_over();

	manager.save_game(game);


	std::cout << manager;


	manager.get_winner_total(o_wins, x_wins, ties);
	REQUIRE(x_wins == 1);
	REQUIRE(o_wins == 1);
	REQUIRE(ties == 1);
}