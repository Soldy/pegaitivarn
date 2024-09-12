#ifndef _DRAW_POOL_
#define _DRAW_POOL_

#include <string>
#include <vector>
#include "PoolDetails.hpp"

class DrawPool {
  private:
    uint8_t _min;
    uint8_t _max;
    uint8_t _balls;
    uint8_t _extra;
    std::vector<uint8_t> _pool;
    std::vector<uint32_t> _count;
    std::vector<uint32_t> _last;
    std::vector<std::vector<uint32_t>> _distance;
    std::vector<std::vector<uint8_t>> _draw;
  public:
    DrawPool(
      poolDetails pool_
    ){
      this->_min = pool_.min;
      this->_max = pool_.max;
      this->_balls = pool_.balls;
      this->_extra = pool_.extra;
    };
    bool check(
      std::vector<uint8_t> numbers
    ){
      if (numbers.size() != this->_balls)
        return false;
      for (size_t i = 0 ; numbers.size() > i ; i++){
         if(numbers[i] > this->_max || numbers[i] < this->_min)
           return false;
      }
      return true;
    }
    bool add(
      std::vector<uint8_t> numbers
    ){
      if( this->check(numbers)){
        this->_draw.push_back(
          numbers
        );
        return true;
      }
      return false;
    }
};

#endif
