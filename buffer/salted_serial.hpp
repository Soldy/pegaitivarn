#ifndef __PEGAITIVARN_BUFFER_SALTED_SERIAL_HPP
#define __PEGAITIVARN_BUFFER_SALTED_SERIAL_HPP
#include <string>
#include <memory>
#include "serial.hpp"
#include "../tools/random/string.hpp"


namespace pai_buffer{
class SaltedSerial{
    std::shared_ptr<
      pai_buffer::Serial
    > _serial;
  public:
    SaltedSerial(){
        this->_serial = std::make_shared<pai_buffer::Serial>();
    };
    std::string get(){
        return (
          pai_random::string(2)+
          std::to_string(this->_serial->get())+
          pai_random::string(2)
        );
    };
    bool set(
      const uint64_t number
    ){
        return this->_serial->set(number);
    };
};
}
#endif
