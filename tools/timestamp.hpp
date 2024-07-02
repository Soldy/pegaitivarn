#ifndef __PEGAITIVARN_TIMESTAMP_
#define __PEGAITIVARN_TIMESTAMP_
#include <chrono>

namespace pai_time { 
int timestamp(){
    return static_cast<int>(time(NULL));
};
}
#endif

