

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "../../text/safe.hpp"

TEST_CASE("pai_text::safe") {
    SUBCASE("fix") {
        std::string example = "fine";
        std::vector<std::string> filter = {"i", "e"};
        CHECK(
           example
           ==
           "fine"
        );
        pai_text::safe(example, filter);
        CHECK(
           example
           ==
           "f_n_"
        );
    };
    SUBCASE("defined") {
        std::string example = "fine";
        std::vector<std::string> filter = {"i", "e"};
        CHECK(
           example
           ==
           "fine"
        );
        pai_text::safe(example, filter, "0");
        CHECK(
           example
           ==
           "f0n0"
        );
    };
};
