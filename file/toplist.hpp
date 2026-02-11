#ifndef __PEGAITIVARN_FILE_TOPLIST_HPP_
#define __PEGAITIVARN_FILE_TOPLIST_HPP_
#include <algorithm>
#include <cctype>
#include <fstream>
#include <string>
#include <tuple>
#include <map>
#include <vector>
#include <iostream>
#include "../text/trim.hpp"


namespace pai_file{

struct TopList_line {
    bool success = false;
    std::string key;
    uint64_t value;
};

class TopList { 
  private:
    std::map<
      std::string, uint64_t
    > db;
    std::vector<std::string> order;
    uint64_t added = 0;
    uint64_t incremented = 0;
    uint32_t size_min = 0;
    uint32_t size_max = 256;
    uint32_t min = 1;
    uint64_t max = 999999999999999999;
    uint64_t current = 0;
    TopList_line splitter (std::string &input_){
        TopList_line out;
        pai_text::trim(input_);
        int i;
        int size = input_.size();
        if(
          input_[0] == '=' &&
          input_[0] == '#'
        )
            return out;
        for(i = 0; size > i ; i++)
            if(input_[i] == '|')
               break;
        if (i == size)
            return out;
        out.key = input_.substr(0,i-1);
        std::string value_s = input_.substr(i+1,size);
        out.value = std::stoi(value_s);
        if( 
          (out.key.size() > this->size_min)  && 
          (out.key.size() < this->size_max) &&
          (out.value > this->min) &&
          (out.value < this->max)
        )
            out.success = true;
        return out;
    };
  public:
    void read (std::string file_name){
        std::string section_name = "default";
        std::string line;
        TopList_line one;
        std::ifstream top_file;
        top_file.open(file_name);
        while(getline(top_file, line)){
            one = this->splitter(line);
            if(one.success == true)
                if (this->db.find(one.key) == this->db.end()){
                    this->added ++;
                    this->db[one.key] = one.value;
                    this->order.push_back(one.key);
                } else {
                    this->incremented ++;
                    this->db[one.key] += one.value;
                }
        }
    };
    void write(std::string filename_){
        std::ofstream file(filename_);
        for(const std::string& key : this->order) 
            file << 
              key <<
              " | " <<
              this->db[key] <<
              "\n";
        file.close();
    };
    std::map<std::string, uint64_t> all(){
        return this->db;
    };
    uint64_t increments(){
        return this->incremented;
    };
    uint64_t adds(){
        return this->added;
    };
    size_t size(){
        return this->db.size();
    };

    std::tuple<
      uint64_t,
      std::string,
      uint64_t
    > get(
      uint64_t num_
    ){
        std::tuple<
          uint64_t,
          std::string,
          uint64_t
        > out;
        uint64_t num = num_;
        if (num < 0 )
            num = 0;
        if (num >= this->order.size())
            return out;
         out =  std::tuple<
                uint64_t,
                std::string,
                uint64_t
              >{
                num,
                this->order[num],
                this->db[this->order[num]]
        };
        return out;
    };

    std::vector<
      std::tuple<
        uint64_t,
        std::string,
        uint64_t
      >
    > get(
      uint64_t begin_,
      uint64_t end_
    ){
        std::vector< 
          std::tuple<
           uint64_t,
           std::string,
           uint64_t
        >> out;
        uint64_t begin = begin_;
        uint64_t end = end_;
        // Do not touch this part yet.
        // We need to consider all possible scenarios carefully.
        // Optimization is not a priority at the moment.
        if (begin < 0)
            begin = 0;
        if (begin >= this->order.size())
            return out;
        if (end >= this->order.size())
            end = (this->order.size()-1);
        if (begin > end_)
            return out;
        if (begin == end_){
            out.push_back(
              this->get(begin)
            );
            return out;
        }
        // extend here :

        for ( uint64_t i = begin ; i < end; i++)
            out.push_back(
              std::tuple<
                uint64_t,
                std::string,
                uint64_t
              >{
                i,
                this->order[i],
                this->db[this->order[i]]
            });
        return out;
    };

    void sort(){
        std::sort(
          this->order.begin(),
          this->order.end(),
          [this](
            std::string a,
            std::string b
        ){
              int ai;
              try {
                  ai = this->db[a];
              } catch (const std::invalid_argument& e) {
                 ai = 0;
                 std::cout << a << std::endl;
              }
              int bi;
              try {
                  bi = this->db[b];
              } catch (const std::invalid_argument& e) {
                 bi = 0;
                 std::cout << b << std::endl;
              }
              return bi < ai;
          }
        );
    };

};
}

#endif
