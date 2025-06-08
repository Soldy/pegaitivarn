/**
 *
 *  @author: Soldy
 *  @email: soldy@gidigi.com
 *  @desc: quoted one line bar
 * This is fine.
 * Only used in 0ne specific place so it is
 * not worth changing; just copy-paste it for now.
 *
 *
 *
**/
#ifndef __PAI_TEXT_ONELINEBAR
#define __PAI_TEXT_ONELINEBAR

#include <string>

namespace pai_text{

std::string onelinebar(
  double percent
){
    if (10 > percent)
        return "_";
    if(20 > percent)
        return "▁";
    if(30 > percent)
       return "▂";
    if(40 > percent)
       return "▃";
    if(60 > percent)
       return "▄";
    if(80 > percent)
       return "▅";
    if(90 > percent)
       return "▆";
    return "▇";
};

std::string onelinebar(
  int percent
){
    if (10 > percent)
        return "_";
    if(20 > percent)
        return "▁";
    if(30 > percent)
       return "▂";
    if(40 > percent)
       return "▃";
    if(60 > percent)
       return "▄";
    if(80 > percent)
       return "▅";
    if(90 > percent)
       return "▆";
    return "█";
};
}
#endif
