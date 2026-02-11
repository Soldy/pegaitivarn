#ifndef __CPP_JUST_TRIM_HPP_
#error "Just trim is not included. Please include just_trim.hpp. https://github.com/Soldy/cpp_just_trim "
#endif
#ifndef __PEGAITIVARN_FILE_SIMPLE_LIST_HPP_
#define __PEGAITIVARN_FILE_SIMPLE_LIST_HPP_
#include <string>
#include <vector>
#include <fstream>
#include "../text/trim.hpp"

namespace pai_file{
std::vector<std::string> simpleListRead (std::string file_name){
    std::vector<std::string> out;
    std::string line;
    std::ifstream list_file;
    list_file.open(file_name);
    if(!list_file.is_open()){
        throw std::runtime_error(
            std::string("File not opened : "+file_name)
        );
    }
    while(getline(list_file, line)){
        pai_text::trim(line);
        out.push_back(line);
    }
    return out;
}

}
#endif
