

#include <iostream>
#include "../../text/xml.hpp"

void title(
  std::string title_
){
    std::cout << std::endl;
    std::cout << 
      "=========================" <<
      std::endl;
    std::cout << 
      "    " << 
      title_ << 
      std::endl;
    std::cout << 
      "-------------------------" <<
      std::endl;
};

void line(
  std::string line_
){
    std::cout << 
      " " << 
      line_ << 
      std::endl;
};
void section(
  std::string title_,
  std::string line_
){
    title(title_);
    line(line_);
    std::cout << std::endl;
};

int main(){
    pai_text::XmlTag test;
    test.name = "a";
    test.attributes = {
      {"href", "http://test.est"},
      {"style", "nothing"},
      {"onclick", "function something"}
    };
    section("xmlSmart no data", pai_text::xmlSmart(test));
    test.data = "some extra link text";
    section("xmlSmart with data", pai_text::xmlSmart(test));
    section("xml", pai_text::xml(test));
    section("xmlSingle", pai_text::xmlSingle(test));

}
