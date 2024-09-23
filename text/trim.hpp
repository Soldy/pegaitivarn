#ifndef __PAI_TEXT_TRIM
#define __PAI_TEXT_TRIM

#include <algorithm> 
#include <cctype>
#include <locale>
#include <string>

namespace pai_text{

bool spaceCheck(char c){
    return !std::isspace(c);
};

void leftTrim(std::string &input_) {
    input_.erase(
      input_.begin(),
      std::find_if(
        input_.begin(),
        input_.end(),
        pai_text::spaceCheck
      )
    );
};

void rightTrim(std::string &input_) {
    input_.erase(
      std::find_if(
        input_.rbegin(),
        input_.rend(),
        pai_text::spaceCheck
      ).base(),
      input_.end()
    );
};

void trim(std::string &input_) {
    pai_text::rightTrim(input_);
    pai_text::leftTrim(input_);
};
}

#endif
