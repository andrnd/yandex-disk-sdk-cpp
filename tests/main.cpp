#include <catch.hpp>
#include <yadisk/client.hpp>
using ydclient = yadisk::Client;

#include <string>

TEST_CASE("initialize after receiving token", "[client][initialize][class][token]") {

	std::string token = "AQAAAAATPnx3AAQXOJS1w4zmPUdrsJNR1FATxEM";
	REQUIRE(not token.empty());
	ydclient client{ token };

}
