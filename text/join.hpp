/**
 *
 *  @author: Soldy
 *  @email: soldy@gidigi.com
 *  @todo: code impprovement
 *  @desc: string join
 *  This is not an effective solution. But DRY
 *  I currently have at least six different
 *  codes that achieve the same join operation,
 *  and maybe this is one of the least preferable methods available right now.
 *  However, the primary objective at the moment is to use this specific function
 *  rather than the others.
 *  others like:
 *   boost::algorithm::join
 *   std::views::join_with
 *   std::accumulate
 *   That is a SOLID violation.
 *   But this specific function is definitely open for code change.
 *   However not for behavior change!!!
**/
#include <string>
#include <vector>


#ifndef __PAI_TEXT_JOIN_
#define __PAI_TEXT_JOIN_
namespace pai_text{

std::string join(
   std::vector<std::string> input_,
   std::string delimiter_
){
     std::string out;
     bool looper = false;
     for (std::string i : input_){
         if(looper){
             i = delimiter_ + i;
         }else{
             looper = true;
         }
         out += i;
     }
     return out;
};
/**
 * Not ready for use yet.
 * Do not use it.
 *
**/
std::string joinDir(
   std::vector<std::string> input_
){
     std::string out;
     for (std::string i : input_){
         out += "/"+i;
     }
     return out;
};

}
#endif
