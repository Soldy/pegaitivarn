
#include <vector>
#include <string>
#include <iostream>
#include "../../text/safe.hpp"

int main(){

    std::string example = "fine";
    std::string example2 = example;
    std::vector<std::string> filter = {"i", "e"};
    std::cout << example << std::endl;
    pai_text::safe(example, filter);
    std::cout << example << std::endl;
    pai_text::safe(example2, filter, "0");
    std::cout << example2 << std::endl;
}
