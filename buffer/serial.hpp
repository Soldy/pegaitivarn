/**
 *
 *  @author: Soldy
 *  @email: soldy@gidigi.com
 *  @todo: code impprovement
 *  @desc:
 *   This is a not thread-safe simple serializer.
 *   The point is to force the code to run an agent
 *  in one threat. For then,
 *      The serializer strictly called only one threat.
 *      A locking method is not needed
 *      That has performance benefits.
 *  The agents communicate with a message queue.
**/
#ifndef __PAI_BUFFER_SERIAL_HPP
#define __PAI_BUFFER_SERIAL_HPP
#include <cstdint>


namespace pai_buffer{

class Serial{
  private:
    uint64_t _serial = 0;
  public:
    uint64_t get(){
        this->_serial++;
        return (uint64_t) this->_serial;
    };
    bool set(
        const uint64_t number_
    ){
        this->_serial = number_;
        return true;
    };
    uint64_t current(){
        return (uint64_t) this->_serial;
    };
};
}
#endif
