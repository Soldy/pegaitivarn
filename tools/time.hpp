#ifndef __PEGAITIVARN_TIME_
#define __PEGAITIVARN_TIME_
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdint>


namespace pai_time{
uint64_t stamp(){
    return static_cast<uint64_t>(
      std::time(nullptr)
    );
};
bool outdated(uint64_t end){
    return (
      pai_time::stamp() > end
    );
};
}
#endif
