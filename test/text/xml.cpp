

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "../../text/xml.hpp"

pai_text::XmlTag test;
TEST_CASE("pai_text::xml") {
    SUBCASE("prepare") {
        test.name = "a";
        test.attributes = {
          {"href", "http://test.est"},
          {"style", "nothing"},
          {"onclick", "function something"}
        };
    };
    SUBCASE("xmlSmart no data") {
      CHECK(
          pai_text::xmlSmart(test)
          == 
          "<a href=http://test.est onclick=\"function something\" style=nothing/>"
      );
    };
    SUBCASE("adding data") {
      test.data = "some extra link text";
    };
    SUBCASE("xmlSmart") {
      CHECK(
          pai_text::xmlSmart(test)
          == 
          "<a href=http://test.est onclick=\"function something\" style=nothing>some extra link text</a>"
      );
    };
    SUBCASE("xml") {
      CHECK(
          pai_text::xml(test)
          == 
          "<a href=\"http://test.est\" onclick=\"function something\" style=\"nothing\">some extra link text</a>"
      );
    };
    SUBCASE("xmlSingle") {
      CHECK(
          pai_text::xmlSingle(test)
          == 
          "<a href=\"http://test.est\" onclick=\"function something\" style=\"nothing\"/>"
      );
    };
};
