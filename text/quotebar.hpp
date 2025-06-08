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
#ifndef __PAI_TEXT_QUOTEBAR
#define __PAI_TEXT_QUOTEBAR

#include <string>

namespace pai_text{

std::string quotebar(
  std::string quote,
  double percent
){
    if (1 > percent)
        return ("_ "+quote+" _");
    if(10 > percent)
        return ("▁ "+quote+" ▁");
    if(20 > percent)
        return ("▂ "+quote+" ▂");
    if(40 > percent)
       return ("▃ "+quote+" ▃");
    if(60 > percent)
       return ("▄ "+quote+" ▄");
    if(80 > percent)
       return ("▅ "+quote+" ▅");
    if(90 > percent)
       return ("▆ "+quote+" ▆");
    return ("█ "+quote+" █");
};
std::string quotebar(
  std::string quote,
  int percent
){
    if (1 > percent)
        return ("_ "+quote+" _");
    if(10 > percent)
        return ("▁ "+quote+" ▁");
    if(20 > percent)
        return ("▂ "+quote+" ▂");
    if(40 > percent)
       return ("▃ "+quote+" ▃");
    if(60 > percent)
       return ("▄ "+quote+" ▄");
    if(80 > percent)
       return ("▅ "+quote+" ▅");
    if(90 > percent)
       return ("▆ "+quote+" ▆");
    return ("█ "+quote+" █");
};
}

#endif
