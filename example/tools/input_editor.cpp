#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "../../tools/input_editor.hpp"


int main(){
  std::shared_ptr<
    pai_input::TextEditor
  > textEditor = std::make_shared<
    pai_input::TextEditor
  >();
  std::string text = "why why";
  std::string ext = "txt";
  std::cout <<
    textEditor->editor( text, ext ) <<
    std::endl;
  return 0;
}

