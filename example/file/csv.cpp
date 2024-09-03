#include <map>
#include <string>
#include <iostream>
#include <memory>
#include "../../file/csv.hpp"

int main(){
  std::vector<
    std::vector<std::string>
  > csv = pai_file::csvRead("example/file/csv.csv",",");
  for (uint32_t l = 0; csv.size() > l ; l++){
    for (uint32_t c = 0; csv[l].size() > c ; c++){
       std::cout << csv[l][c] << " | ";
    } 
    std::cout << std::endl;
  }
  return 0;
}
