

#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include "../../text/safe.hpp"

int main(){

    std::string example = "fine";
    std::vector<std::string> filter = {"i", "e"};
    std::cout << example << std::endl;
    pai_text::safe(example, filter);
    std::cout << example << std::endl;
}
