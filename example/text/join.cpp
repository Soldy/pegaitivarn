
#include <iostream>
#include "../../text/join.hpp"

int main(){
    std::vector<std::string> example = {
      "Lorem",
      "ipsum",
      "dolor",
      "sit",
      "amet",
      "consectetur",
      "adipiscing",
      "elit"
    };
    std::cout << pai_text::join(example, "/") << std::endl;
    std::cout << pai_text::joinDir(example) << std::endl;
}
