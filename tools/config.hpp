#ifndef __PEGAITIVARN_TOOL_CONFIG
#define __PEGAITIVARN_TOOL_CONFIG
#include <string>
#include <vector>
#include <map>
#include "../buffer/config.hpp"

namespace pai_config{
    pai_buffer::Config *conf = new pai_buffer::Config();

    void set (
      const std::string name,
      const std::string val
    ){
          pai_config::conf->set(
          name,
          val
        );
    };
    void map (
        std::map<std::string, std::string> map_
    ){
        for(auto const & [name, val] : map_){
            pai_config::conf->set(
                name,
                val
            );
        }
    };
    std::map<std::string, std::string> map(){
        return pai_config::conf->map();
    };
    std::string get (const std::string name){
        return pai_config::conf->get(
          name
        );
    };
    std::string get (const std::string name, std::string def){
        return pai_config::conf->get(
          name,
          def
        );
    };
    int getInt (const std::string name){
        return pai_config::conf->getInt(
          name
        );
    };
    int getInt (const std::string name, int def){
        return pai_config::conf->getInt(
          name,
          def
        );
    };
};


#endif
