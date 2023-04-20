#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include<iostream>
#include<memory>

using std::unique_ptr, std::make_unique, std::move;

//
// TicTacToe3 Tests
// 

TEST_CASE("Verify Test Configuration", "verification")
{
	REQUIRE(true == true);
}

// Tests for player initialization
TEST_CASE("Test first player set to X", "validation")
{
	unique_ptr<TicTacToe3> game = make_unique<TicTacToe3>();
	game->start_game("X");
	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O", "validation")
{
	unique_ptr<TicTacToe3> game = make_unique<TicTacToe3>();
	game->start_game("O");
	REQUIRE(game->get_player() == "O");
}

// Tests for game over
TEST_CASE("Test game over if 9 slots are selected", "validation")
{
	unique_ptr<TicTacToe3> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(4);
	for (int i = 1; i <= 9; i++) 
	{
		if (i != 4) game->mark_board(i);
	}
	game->game_over();

	REQUIRE(game->get_winner() == "C");
}

// Tests for column wins
TEST_CASE("Test win by first column", "validation")
{
	unique_ptr<TicTacToe3> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(1);
	game->mark_board(9);
	game->mark_board(4);
	game->mark_board(5);
	game->mark_board(7);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second column", "validation")
{
	unique_ptr<TicTacToe3> game = make_unique<TicTacToe3>();
	game->start_game("O");

	game->mark_board(2);
	game->mark_board(9);
	game->mark_board(5);
	game->mark_board(4);
	game->mark_board(8);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test win by third column", "validation")
{
	unique_ptr<TicTacToe3> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(3);
	game->mark_board(1);
	game->mark_board(6);
	game->mark_board(4);
	game->mark_board(9);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

// Tests for row wins
TEST_CASE("Test win by first row", "validation")
{
	unique_ptr<TicTacToe3> game = make_unique<TicTacToe3>();
	game->start_game("O");

	game->mark_board(1);
	game->mark_board(9);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(3);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test win by second row", "validation")
{
	unique_ptr<TicTacToe3> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(4);
	game->mark_board(9);
	game->mark_board(5);
	game->mark_board(3);
	game->mark_board(6);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third row", "validation")
{
	unique_ptr<TicTacToe3> game = make_unique<TicTacToe3>();
	game->start_game("O");

	game->mark_board(7);
	game->mark_board(1);
	game->mark_board(8);
	game->mark_board(4);
	game->mark_board(9);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

// Tests for diagonal wins
TEST_CASE("Test win by top left diagonal", "validation")
{
	unique_ptr<TicTacToe3> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(3);
	game->mark_board(9);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by bottom left diagonal", "validation")
{
	unique_ptr<TicTacToe3> game = make_unique<TicTacToe3>();
	game->start_game("O");

	game->mark_board(7);
	game->mark_board(9);
	game->mark_board(5);
	game->mark_board(4);
	game->mark_board(3);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test TicTacToeManager get winner total", "validation")
{	
	TicTacToeManager manager;
	unique_ptr<TicTacToe> game;

	int x_wins, o_wins, ties;

	// Game 1: Win for O
	game = make_unique<TicTacToe3>();
	game->start_game("O");
	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(3);
	game->mark_board(9);
	game->game_over();

	manager.save_game(game);

	// Game 2: Win for X
	game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(7);
	game->mark_board(2);
	game->mark_board(8);
	game->mark_board(3);
	game->mark_board(9);
	game->game_over();
	manager.save_game(game);

	// Game 3: Tie
	game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(4);
	for (int i = 1; i <= 9; i++) 
	{
		if (i != 4) game->mark_board(i);
	}
	game->game_over();

	manager.save_game(game);


	std::cout << manager;


	manager.get_winner_total(o_wins, x_wins, ties);
	REQUIRE(x_wins == 1);
	REQUIRE(o_wins == 1);
	REQUIRE(ties == 1);
}

// 
// TicTacToe4 Tests
// 

// Tests for player initialization
TEST_CASE("Test first player set to X 4", "validation")
{
	unique_ptr<TicTacToe4> game = make_unique<TicTacToe4>();
	game->start_game("X");
	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O 4", "validation")
{
	unique_ptr<TicTacToe4> game = make_unique<TicTacToe4>();
	game->start_game("O");
	REQUIRE(game->get_player() == "O");
}

// Tests for game over
TEST_CASE("Test game over if 16 slots are selected 4", "validation")
{
	unique_ptr<TicTacToe4> game = make_unique<TicTacToe4>();
	game->start_game("X");
	
	game->mark_board(1);
	game->mark_board(3);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(4);
	game->mark_board(6);
	game->mark_board(7);
	game->mark_board(8);
	game->mark_board(9);
	game->mark_board(10);
	game->mark_board(11);
	game->mark_board(13);
	game->mark_board(12);
	game->mark_board(15);
	game->mark_board(14);
	game->mark_board(16);

	game->game_over();

	REQUIRE(game->get_winner() == "C");
}

// Tests for column wins
TEST_CASE("Test win by first column 4", "validation")
{
	unique_ptr<TicTacToe4> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(1);
	game->mark_board(7);
	game->mark_board(5);
	game->mark_board(2);
	game->mark_board(9);
	game->mark_board(3);
	game->mark_board(13);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second column 4", "validation")
{
	unique_ptr<TicTacToe4> game = make_unique<TicTacToe4>();
	game->start_game("O");

	game->mark_board(2);
	game->mark_board(9);
	game->mark_board(6);
	game->mark_board(4);
	game->mark_board(10);
	game->mark_board(7);
	game->mark_board(14);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test win by third column 4", "validation")
{
	unique_ptr<TicTacToe4> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(3);
	game->mark_board(1);
	game->mark_board(7);
	game->mark_board(4);
	game->mark_board(11);
	game->mark_board(6);
	game->mark_board(15);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by fourth column 4", "validation")
{
	unique_ptr<TicTacToe4> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(4);
	game->mark_board(1);
	game->mark_board(8);
	game->mark_board(3);
	game->mark_board(12);
	game->mark_board(13);
	game->mark_board(16);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

// Tests for row wins
TEST_CASE("Test win by first row 4", "validation")
{
	unique_ptr<TicTacToe4> game = make_unique<TicTacToe4>();
	game->start_game("O");

	game->mark_board(1);
	game->mark_board(9);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(3);
	game->mark_board(6);
	game->mark_board(4);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test win by second row 4", "validation")
{
	unique_ptr<TicTacToe4> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(5);
	game->mark_board(9);
	game->mark_board(6);
	game->mark_board(3);
	game->mark_board(7);
	game->mark_board(11);
	game->mark_board(8);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third row 4", "validation")
{
	unique_ptr<TicTacToe4> game = make_unique<TicTacToe4>();
	game->start_game("O");

	game->mark_board(9);
	game->mark_board(1);
	game->mark_board(10);
	game->mark_board(4);
	game->mark_board(11);
	game->mark_board(5);
	game->mark_board(12);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test win by fourth row 4", "validation")
{
	unique_ptr<TicTacToe4> game = make_unique<TicTacToe4>();
	game->start_game("O");

	game->mark_board(13);
	game->mark_board(1);
	game->mark_board(14);
	game->mark_board(4);
	game->mark_board(15);
	game->mark_board(5);
	game->mark_board(16);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

// Tests for diagonal wins
TEST_CASE("Test win by top left diagonal 4", "validation")
{
	unique_ptr<TicTacToe4> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(6);
	game->mark_board(3);
	game->mark_board(11);
	game->mark_board(5);
	game->mark_board(16);

	std::cout<<*game;

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by bottom left diagonal 4", "validation")
{
	unique_ptr<TicTacToe4> game = make_unique<TicTacToe4>();
	game->start_game("O");

	game->mark_board(4);
	game->mark_board(9);
	game->mark_board(7);
	game->mark_board(3);
	game->mark_board(10);
	game->mark_board(5);
	game->mark_board(13);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test TicTacToeManager get winner total 4", "validation")
{	
	TicTacToeManager manager;
	unique_ptr<TicTacToe> game;

	int x_wins, o_wins, ties;

	// Game 1: Win for O
	game = make_unique<TicTacToe4>();
	game->start_game("O");
	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(3);
	game->mark_board(9);
	game->mark_board(7);
	game->mark_board(13);
	game->game_over();

	manager.save_game(game);

	// Game 2: Win for X
	game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(5);
	game->mark_board(1);
	game->mark_board(6);
	game->mark_board(2);
	game->mark_board(7);
	game->mark_board(3);
	game->mark_board(8);
	game->game_over();
	manager.save_game(game);

	// Game 3: Tie
	game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(3);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(4);
	game->mark_board(6);
	game->mark_board(7);
	game->mark_board(8);
	game->mark_board(9);
	game->mark_board(10);
	game->mark_board(11);
	game->mark_board(13);
	game->mark_board(12);
	game->mark_board(15);
	game->mark_board(14);
	game->mark_board(16);
	game->game_over();

	manager.save_game(game);


	std::cout << manager;


	manager.get_winner_total(o_wins, x_wins, ties);
	REQUIRE(x_wins == 1);
	REQUIRE(o_wins == 1);
	REQUIRE(ties == 1);
}