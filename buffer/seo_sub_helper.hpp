#ifndef __PAI_BUFFER_SEO_HELPER
#define __PAI_BUFFER_SEO_HELPER

#include <string>
#include <map>
#include <vector>
#include <memory>

namespace pai_buffer{

struct MetaTwo {
  std::string tag = "meta";
  std::string property = "name";
  std::string content = "content";
};

std::map<std::string, MetaTwo> MetaTwoList{
 {"rel", {"link", "rel", "href"}},
 {"name", {"meta", "name", "content"}},
 {"property", {"meta", "property", "content"}},
 {"http-equiv", {"meta", "http-equiv", "content"}}
};

struct MetaType{
  uint64_t size;
  std::string list;
};


pai_text::XmlTag metaTwoBuild(
  std::string list_,
  std::string property_,
  std::string content_
){
   MetaTwo attrs = pai_buffer::MetaTwoList[list_];
   pai_text::XmlTag out {
       attrs.tag,
       {
       {attrs.property, property_},
       {attrs.content, content_}
     }
   };
   return out;
};

/**
 * Seo sub helper
 *
 * This helps establish distinct SEO subpart standards.
 * The class should specify the meta tags as string,
 * integer, float, enum, or array types. This is not an
 * abstract class, as instances can be created multiple
 * times in a sub-manager class. Do not relocate the set
 * method to the constructor or call in there, as the set
 * method needs to be called multiple times in the future.
 *
**/
class SeoSubHelper{
  private:
    std::map<std::string, std::vector<std::string>> _db;
    std::map<std::string, MetaType> _types;
  public:
    void add(
      std::string property_,
      std::vector<std::string> values_
    ){  
        if(this->_types.contains(property_)){
          if(this->_types[property_].size - 1 == values_.size() ){
            this->_db[property_] = values_;
          }
        }
    };
    bool propertyCheck(
      std::string property_
    ){
        if(this->_types.contains(property_))
          return true;
        return false;
    };
    void set(
      std::map<std::string, MetaType> types_
    ){  
        this->_types = types_;
    };
    std::vector<std::string> get(
      std::string property_
    ){  
        if(this->_db.contains(property_))
          return this->_db[property_];
        std::vector<std::string> out;
        return out;
    };
    std::vector<pai_text::XmlTag> xml(){
      std::vector<pai_text::XmlTag> out;
       for (const auto& [key, value]: this->_db)
         if(this->_types[key].size == 2)
           out.push_back(
             pai_buffer::metaTwoBuild(
               this->_types[key].list,
               key,
               value[0]
             )
           );
       return out;

    };
    std::string render(){
        std::string out;
        for (const auto & c: this->_db){
          if(this->_types[c.first].size == 2)
            out += pai_text::xmlSmart(
              pai_buffer::metaTwoBuild(
                this->_types[c.first].list,
                c.first,
                c.second[0]
              )
            );
        };
        return out;
    };
};


};

#endif
