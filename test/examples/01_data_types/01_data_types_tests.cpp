#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "int.h" //C++ will fetch echo_variable func code
#include "decimals.h" //C++ will fetch echo_variable func code
#include "char.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true); //use as guide to build test
}

/*test case echo_variable */
TEST_CASE("Test Echo variable", "validation") {
	REQUIRE(echo_variable(5) == 5); // Test 1
	REQUIRE(echo_variable(10) == 10); // Test 2
	REQUIRE(echo_variable(100) == 100); // Test 3
}

/*test case add_to_double_1 with 0 as parameter*/
TEST_CASE("Test Double + 1", "testing inconsistencies when comparing doubles") {
	REQUIRE(add_to_double_1(0) == .9); // Test 1
}

/*test case add_to_double_1 with 1 as parameter*/
TEST_CASE("Test get char ascii values", "testing inconsistencies when comparing doubles") {
	REQUIRE(get_char_ascii('A') == 1); // Test 1
}

/*test case add_to_double_2 with 0 as parameter*/

/*test case add_to_double_2 with 1 as parameter*/

/*test case char test ASCII values */

/*test case string test ASCII values Joe characters are equal to 74, 111, and 101*/

