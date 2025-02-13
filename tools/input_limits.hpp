
#ifndef __PEGAITIVARN_INPUT_LIMITS_
#define __PEGAITIVARN_INPUT_LIMITS_
#include <cstdint>

namespace pai_input { 

struct size_limits {
    uint16_t minimum = 0; 
    uint16_t maximum = 255;
};

struct number_limits {
    int32_t minimum = 0; 
    int32_t maximum = 255;
};

}

#endif
