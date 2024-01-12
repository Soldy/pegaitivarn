#ifndef __PEGAITIVARN_SIMPLE_INI_HPP_
#define __PEGAITIVARN_SIMPLE_INI_HPP_
#include <algorithm> 
#include <cctype>
#include <locale>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "../text/trim.hpp"


namespace pai_simple_ini{

struct ini_line {
    bool success = false;
    std::string key;
    std::string value;
};


ini_line splitter (std::string &input_){
    ini_line out;
    int size = input_.size();
    if(
      1 > size         ||
      input_[0] == '=' ||
      input_[0] == '#' ||
      input_[0] == '['
    )
         return out;
    int i;
    for(i = 0; size > i ; i++)
        if(input_[i] == '=')
           break;
    if (i != size){
        out.key = input_.substr(0,i-1);
        out.value = input_.substr(i+1,size);
        pai_text::trim(out.key);
        pai_text::trim(out.value);
        out.success = true;
    }
    return out;
};

std::map<std::string, std::string> read (std::string file_name){
    std::map<std::string, std::string> out;
    std::string line;
    ini_line one;
    std::ifstream ini_file;
    ini_file.open(file_name);
    if(!ini_file.is_open()){
        throw std::runtime_error(
            std::string("File not opened : "+file_name)
        );
    }
    while(getline(ini_file, line)){
        one = splitter(line);
        if(one.success == true)
            out[one.key] = one.value;
    }
    return out;
};
}

#endif
