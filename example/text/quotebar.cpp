

#include <iostream>
#include "../../text/quotebar.hpp"

int main(){
    std::cout <<
      pai_text::quotebar("sometext", 1) <<
      std::endl;
    std::cout <<
      pai_text::quotebar("sometext", 75) <<
      std::endl;
    std::cout <<
      pai_text::quotebar("sometext", 99.01) <<
      std::endl;
}
