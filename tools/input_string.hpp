#ifndef __PEGAITIVARN_INPUT_STRING_
#define __PEGAITIVARN_INPUT_STRING_
#include <string>
#include "input_limits.hpp"

/**
* cin based not raw string input fields. 
* for usage example check the: 
* example/tools/input_integer.cpp
*/

namespace pai_input { 

struct string_details{
    std::string title = " ";
    std::string value = " ";
    pai_input::size_limits size;
};

bool stringCheck(
  std::string value,
  pai_input::string_details details
){
    if(
        value.size() < details.size.maximum &&
        value.size() >= details.size.minimum 
    ){
        return true;
    }
    return false;
};

std::string stringToDefault(
  std::string value,
  pai_input::string_details details
){
    if(
      value == "." &&
      details.value.size() < details.size.maximum &&
      details.value.size() >= details.size.minimum 
    ){
        return details.value;
    }
    return value;
};

std::string string (std::string title, std::string value){
    std::string out;
    std::cout << 
      title << 
      " \n" << 
      "\u001b[38;2;155;155;155m" <<  
      value << 
      "\u001b[0m" <<
      std::endl;
    std::cout << 
     "\u001b[A";
    std::getline(std::cin, out);
    return out;
};

std::string string (std::string title){
    return pai_input::string(
      title,
      " "
    );
};

std::string string (pai_input::string_details details){
    bool failed {true};
    std::string out;
    while (failed){
        out = stringToDefault(
          pai_input::string(
            details.title,
            details.value
          ),
          details
        );
        failed = (!pai_input::stringCheck(out, details));
    }
    return out;
};

}
#endif
