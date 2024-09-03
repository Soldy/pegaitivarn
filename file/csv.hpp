#ifndef __CPP_JUST_CSV_HPP_
#define __CPP_JUST_CSV_HPP_
#include <algorithm> 
#include <cctype>
#include <locale>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


namespace pai_file{

std::vector<std::string> csvSplitter (
  std::string input_,
  std::string separator_
){
    std::vector<std::string> out;
    int size = input_.size();
    int sep_size = separator_.size();
    int i;
    int last = 0;
    int serial = 0; // element serial
    int next = 0;
    for(i = 0; size > i ; i++){
        if(input_[i] == separator_[0]){
            next = (i+sep_size);
            if(input_.substr(i, sep_size) == separator_ ){
                serial++;
                out.push_back(input_.substr(last, i-last));
                i = next;
                last = next;
                continue;
            }
        }
    }
    return out;
};
std::vector<
  std::vector<std::string>
> csvRead (
   std::string file_name,
   std::string separator_
){
    std::vector<
      std::vector<std::string>
    > out;
    std::string line;
    std::ifstream csv_file;
    csv_file.open(file_name);
    if(!csv_file.is_open()){
        throw std::runtime_error(
            std::string("File not opened : "+file_name)
        );
    }
    while(getline(csv_file, line)){
      out.push_back(pai_file::csvSplitter(line,separator_));
    }
    csv_file.close();
    return out;

};
}


#endif
