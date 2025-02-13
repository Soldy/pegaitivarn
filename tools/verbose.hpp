#ifndef __PEGAITIVARN_VERBOSE_
#define __PEGAITIVARN_VERBOSE_
#include <string>
#include <cstdint>
#include <iostream>

namespace pai_verbose{
    uint16_t level = 5;
    void msg(
      std::string msg,
      std::string element,
      uint16_t level
    ){
        if( pai_verbose::level >= level)
            std::cout << msg << " : " << element << std::endl;
    };
    void msg(
      std::string msg,
      std::string element,
      std::string error,
      uint16_t level
    ){
        if( pai_verbose::level >= level)
            std::cout <<
                msg << " : " <<
                element <<
                " - " <<
                error <<
                std::endl;
    };
    void msg(
      std::string msg,
      std::string element
    ){
        pai_verbose::msg(msg,element,1);
    };
    void msg(
      std::string msg,
      std::string element,
      std::string error
    ){
        pai_verbose::msg(msg,element,error,1);
    };
};
#endif
