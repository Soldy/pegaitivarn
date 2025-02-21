#ifndef __PAI_BUFFER_SERIAL_HPP
#define __PAI_BUFFER_SERIAL_HPP
#include <cstdint>
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>


namespace pai_buffer{

class Serial{
  private:
     std::atomic_ullong _serial = 0;
  public:
    uint64_t get(){
        this->_serial++;
        return (uint64_t) this->_serial;
    };
    bool set(
        const uint64_t number
    ){
        this->_serial = number;
        return true;
    };
    uint64_t current(){
        return (uint64_t) this->_serial;
    };
};
}
#endif
