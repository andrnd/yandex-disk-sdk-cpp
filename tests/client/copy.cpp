#include <catch.hpp>
#include <yadisk/client.hpp>
using ydclient = yadisk::Client;

#include <string>
#include <list>

#include <url/path.hpp>
using url::path;

TEST_CASE("copy resource with overwriting", "[client][copy][file][overwrite]") {

	std::string token = "AQAAAAATPnx3AAQXOJS1w4zmPUdrsJNR1FATxEM";
	ydclient client{ token };
	path from{ "/foo/photo.png" };
	path to{ "/bar/photo.png" };
	bool overwrite = true;
	json meta = "{\"custom_properties\":{\"foo\":\"0\",\"bar\":\"1\"}}"_json;
	std::list<std::string> fields{ "custom_properties.foo", "custom_properties.bar" };

	auto info = client.copy(from, to, overwrite, fields);
	REQUIRE(not info.empty());
	auto href = info["href"].get<std::string>();
	REQUIRE(not href.empty());
	auto foo = info["custom_properties"]["foo"].get<std::string>();
	auto bar = info["custom_properties"]["bar"].get<std::string>();
	REQUIRE(foo == "0");
	REQUIRE(bar == "1");

}

TEST_CASE("copy resource w/o overwriting", "[client][copy][file]") {

	std::string token = "AQAAAAATPnx3AAQXOJS1w4zmPUdrsJNR1FATxEM";
	ydclient client{ token };
	path from{ "/foo/photo.png" };
	path to{ "/bar/photo.png" };
	bool overwrite = false;
	json meta = "{\"custom_properties\":{\"foo\":\"0\",\"bar\":\"1\"}}"_json;
	std::list<std::string> fields{ "custom_properties.foo", "custom_properties.bar" };

	auto info = client.copy(from, to, overwrite, fields);
	REQUIRE(not info.empty());
	auto href = info["href"].get<std::string>();
	REQUIRE(not href.empty());
	auto foo = info["custom_properties"]["foo"].get<std::string>();
	auto bar = info["custom_properties"]["bar"].get<std::string>();
	REQUIRE(foo == "0");
	REQUIRE(bar == "1");

}