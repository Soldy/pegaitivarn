#ifndef _POOL_DETAILS
#define _POOL_DETAILS

/**
 * Pool details are define the pool variable 
 * definatons. So the important information abaout the pool.
 *
**/
#include <string>

struct poolDetails{
  std::string name = "";
  uint8_t min = 1;
  uint8_t max = 45;
  uint8_t balls = 5;
  uint8_t extra = 0;
};

#endif
