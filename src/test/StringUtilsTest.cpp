#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../StringUtils.hpp"

TEST_CASE("Split on delimeter", "i dunno...") {
    string testStr = "asdf//asdf//asdf//as";
    vector<string> testVec = splitOnDelimeter(testStr, "//");

    REQUIRE(testVec.size() == 4);
}