
#include <iostream>
#include "../../file/path.hpp"

int main(){
    std::vector<std::string> example = {
      "var",
      "log"
    };
    std::cout << example[pai_file::pathCheck(example)] << std::endl;
}
