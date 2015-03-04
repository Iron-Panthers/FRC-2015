#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"

int testNum()
{
	return 41;
}

TEST_CASE("Numbers is correct", "[number]") {
	REQUIRE(testNum() == 42);	
}
