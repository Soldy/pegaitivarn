/**
 *  @author: Soldy
 *  @email: soldy@gidigi.com
 *  @desc: path check collection
 *  This function is only used at both times.
 *  For this reason, the code is simpler rather than faster.
 *  Any other points in the code are considered a waste of memory.
 *  The namespace and function name should be changed in the near future.
**/
#ifndef __CPP_PAI_PATH_HPP_
#define __CPP_PAI_PATH_HPP_
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include "../text/join.hpp"


namespace pai_file{

int32_t pathCheck(
  std::vector<std::string> input_
){
    std::vector<std::string> pn;
    uint32_t size = input_.size();
    for(uint32_t i = 0; i < size; i++){
       pn.push_back(
         input_[i]
       );
       if(!std::filesystem::exists(
         pai_text::joinDir(pn)
       )){
         return i;
       };
    }
    return -1;
};
}


#endif
