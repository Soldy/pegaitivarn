

#include <iostream>
#include "../../text/xml.hpp"

int main(){

    std::string example = "fine";
    pai_text::XmlTag test;
    test.name = "a";
    test.attributes = {
      {"href", "http://test.est"},
      {"style", "nothing"},
      {"onclick", "function something"}
    };
    test.data = "some extra link text";

    std::cout << pai_text::xml(test) << std::endl;
    std::cout << pai_text::xmlSingle(test) << std::endl;
}
