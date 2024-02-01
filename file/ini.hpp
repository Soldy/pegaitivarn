#ifndef __PEGAITIVARN_FILE_INI_HPP_
#define __PEGAITIVARN_FILE_INI_HPP_
#include <algorithm> 
#include <cctype>
#include <locale>
#include <fstream>
#include <string>
#include <map>
#include "../text/trim.hpp"


namespace pai_file{

struct Ini_line {
    bool success = false;
    std::string section;
    std::string key;
    std::string value;
};

class Ini { 
  private:
    std::string section_name;
    std::map<
      std::string, 
      std::map<
        std::string, std::string
      >
    > db;
    Ini_line splitter (std::string &input_){
        Ini_line out;
        pai_text::trim(input_);
        int i;
        int size = input_.size();
        if(
          input_[0] == '=' &&
          input_[0] == '#'
        )
            return out;
        if(
          input_[0] == '[' &&
          input_[input_.size()-1] == ']'
        ){
            this->sectionNameRead(input_);
            return out;
        }
        for(i = 0; size > i ; i++)
            if(input_[i] == '=')
               break;
        if (i == size)
            return out;
        out.key = input_.substr(0,i-1);
        out.value = input_.substr(i+1,size);
        out.section = this->section_name;
        pai_text::trim(out.key);
        pai_text::trim(out.value);
        if( out.key.size() > 0 && out.value.size() > 0)
            out.success = true;
        return out;
    };
    void sectionNameRead(std::string &input_){
        int i;
        int size = input_.size();
        std::string section = "";
        for(i = 1; size-1 > i ; i++)
            section += input_[i];
        if (1 > section.size())
            return ;
        this->section_name = section;
    };
  public:
    void read (std::string file_name){
         std::string section_name = "default";
         std::string line;
         Ini_line one;
         std::ifstream ini_file;
         ini_file.open(file_name);
         while(getline(ini_file, line)){
             one = splitter(line);
             if(one.success == true)
                 this->db[one.section][one.key] = one.value;
         }
    };
    std::map<std::string, std::map<std::string, std::string>> all(){
        return this->db;
    };

};
}

#endif
