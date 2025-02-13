/**
 *
 *  @author: Soldy 
 *  @email: soldy@gidigi.com
 *  @desc: xml and html tag generator
**/


#ifndef __PAI_TEXT_XML_
#define __PAI_TEXT_XML_
#include <map>
#include <vector>
#include <string>


namespace pai_text{

struct XmlTag {
  std::string name;
  std::map<std::string, std::string> attributes;
  std::string data;
};


std::string tagAtributtes(
  std::map<std::string, std::string> attributes_
){
    std::string out;
    for (const auto & [k, v]  : attributes_) {
        out += (
          " "+
          k+
          "=\""+
          v+
          "\""
        );
    }
    return out;
};

std::string xmlOpen(
  pai_text::XmlTag tag_
){
  return (
    "<"+
    tag_.name+
    tagAtributtes(
      tag_.attributes
    )+
    ">"
  );
};

std::string xmlSingle(
  pai_text::XmlTag tag_
){
  return (
    "<"+
    tag_.name+
    tagAtributtes(
      tag_.attributes
    )+
    "/>"
  );
};


std::string xmlClose(
  pai_text::XmlTag tag_
){
  
  return (
    "</"+
    tag_.name+
    ">"
  );
};

std::string xml(
  pai_text::XmlTag tag_
){
  return (
    xmlOpen(tag_)+
    tag_.data+
    xmlClose(tag_)
  );
};


}
#endif
