#include "biblioteka.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

bool IfProtingi(double vidurkis)
{
	if (vidurkis >= 5)
		return true;
	else return false;
}
bool IfKvaili(double vidurkis)
{
	if (vidurkis < 5)
		return true;
	else return false;
}

double GP(double vidurkis, int egzaminas)
{
	return 0.4 * vidurkis + 0.6 * egzaminas;
}

TEST_CASE("GP") {

	REQUIRE(GP(5.1, 7) == 6.24);
	REQUIRE(GP(4.1, 10) == 7.64);
	REQUIRE(GP(9.2, 4) == 6.08);
	REQUIRE(GP(8.5, 9) == 8.8);
	REQUIRE(GP(8.5, 3) == 5.2);

}

TEST_CASE("Protingi") {

	REQUIRE(IfProtingi(9) == true);
	REQUIRE(IfProtingi(4) == false);
	REQUIRE(IfProtingi(10) == true);
	REQUIRE(IfProtingi(7) == true);
	REQUIRE(IfProtingi(5) == true);

}
TEST_CASE("Kvaili") {

	REQUIRE(IfKvaili(7) == false);
	REQUIRE(IfKvaili(5) == false);
	REQUIRE(IfKvaili(4) == true);
	REQUIRE(IfKvaili(1) == true);
	REQUIRE(IfKvaili(3) == true);

}
