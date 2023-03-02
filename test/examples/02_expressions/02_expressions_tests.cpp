#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "expressions.h"
#include "casting.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify operator_precedence_1", "validating operator precedence") {
	REQUIRE(operator_precedence_1(3, 6, 3) == 5);
}

TEST_CASE("Verify operator_precedence_2", "validating operator precedence with parenthesis") {
	REQUIRE(operator_precedence_2(3, 6, 3) == 3);
}

TEST_CASE("Verify convert_int_to_double", "validating int to double casting") {
	REQUIRE(convert_int_to_double(2, 1.5) == 3);
}

TEST_CASE("Verify convert_double_to_int", "validating double to int casting") {
	REQUIRE(convert_double_to_int(1.5) == 1);
	REQUIRE(convert_double_to_int(15.94245245234) == 15);
}
