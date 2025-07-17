/**
 *
 *  @author: Soldy
 *  @email: soldy@gidigi.com
 *  @desc: safe char filter
 *  Thats are a simple, safe filter.
 *  In some situations, they perform faster than regexp.
 *
 *  Consider not using this functions.
 *  It is designed for a specific purpose and 
 *  is unnecessary for your needs.
 *  You are seeking that:
 *  https://en.cppreference.com/w/cpp/regex/regex_replace.html
**/


#ifndef __PAI_TEXT_SAFE_
#define __PAI_TEXT_SAFE_
#include <map>
#include <vector>
#include <string>


namespace pai_text{

void safe(
  std::string & checked,
  std::vector<std::string> unsafe,
  std::string replace
){
  for(std::string::size_type i = 0; i < checked.size(); ++i)
    for(size_t c = 0; c < unsafe.size(); c++)
      if(checked[i] == unsafe[c][0])
        checked[i] = replace[0];
};

void safe(
  std::string & checked,
  std::vector<std::string> unsafe
){
  // There are many alternatives
  // one of them :
  // str.erase (std::remove(str.begin(), str.end(), char_to_remove), str.end());
  std::string replace("_");
  for(std::string::size_type i = 0; i < checked.size(); ++i)
    for(size_t c = 0; c < unsafe.size(); c++)
      if(checked[i] == unsafe[c][0])
        checked[i] = replace[0];
};

}
#endif
