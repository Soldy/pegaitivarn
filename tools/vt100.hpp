#ifndef __PEGAITIVARN_VT100_
#define __PEGAITIVARN_VT100_
#include <string>

namespace pai_vt100 {
std::string curPos (
  std::string col,
  std::string row
){
    return (
      "\x1b["+
      col+
      ";"+
      row+
      "H"
    );
};
}

std::string str (
  std::string text,
  std::string color,
  std:string background
){
    return (
       "\x1b[38;2;"+
       color+
       "m\x1b[48;2;"+
       background+
       "m"+
       text+
       "\x1b[0m"
    );
};
}
#endif
