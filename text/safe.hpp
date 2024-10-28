/**
 *
 *  @author: Soldy 
 *  @email: soldy@gidigi.com
 *  @desc: safe char filter 
 *  Thats are a simple and safe filter. 
 *  In some situations, they perform faster than regexp.
**/


#ifndef __PAI_TEXT_SAFE_
#define __PAI_TEXT_SAFE_
#include <map>
#include <vector>
#include <string>


namespace pai_text{

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
