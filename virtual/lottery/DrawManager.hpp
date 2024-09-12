#ifndef _DRAW_MANAGER
#define _DRAW_MANAGER

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "PoolDraw.hpp"

class DrawManager{
  private:
    std::vector<std::unique_ptr<DrawPool>> _pools;
  public:
    DrawManager(
      std::vector<poolDetails> pools_
    ){
      for (size_t i = 0; pools_.size() > i ; i++ ){
        this->_pools.push_back(
          std::make_unique<DrawPool>(pools_[i])
        );
      }
    };
    bool add(
      std::vector<std::vector<uint8_t>> numbers_
    ){
      if(numbers_.size() != this->_pools.size())
        return false;
      for (size_t i = 0; numbers_.size() > i ; i++)
        if(!this->_pools[i]->check(numbers_[i]))
          return false;
      for (size_t i = 0; numbers_.size() > i ; i++)
        if(!this->_pools[i]->add(numbers_[i]))
          return false;
      return true;
    }
};

#endif
