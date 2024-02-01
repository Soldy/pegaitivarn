#include <map>
#include <string>
#include <iostream>
#include <memory>
#include "../../file/ini.hpp"

int main(){
    std::shared_ptr<
      pai_file::Ini
    > ini (new pai_file::Ini());
    ini->read("example/file/ini.ini");
    std::map<
      std::string, 
      std::map<
        std::string, std::string
      >
    > test = ini->all();
    std::cout <<
        test["test section"]["test_number"] << 
        std::endl;
    std::cout <<
        test["test section"]["test_string"] <<
        std::endl;
    return 0;
}
