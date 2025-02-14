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
  std::string data = "";
};

std::string tagAtributtesValueSmart(
  std::string value_
){
    if(value_.contains(' ') || value_.contains(':'))
        return (
          "\""+
          value_+
          "\""
        );
    return value_;
};

std::string tagAtributtesSmart(
  std::map<std::string, std::string> attributes_
){
    std::string out;
    for (const auto & [k, v]  : attributes_) {
        out += (
          " "+
          k+
          "="+
          tagAtributtesValueSmart(v)
        );
    }
    return out;
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

std::string xmlOpenSmart(
  pai_text::XmlTag tag_
){
  return (
    "<"+
    tag_.name+
    tagAtributtesSmart(
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

std::string xmlSingleSmart(
  pai_text::XmlTag tag_
){
  return (
    "<"+
    tag_.name+
    tagAtributtesSmart(
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


std::string xmlSmart(
  pai_text::XmlTag tag_
){
  if (tag_.data == "")
      return xmlSingleSmart(tag_);
  return (
    xmlOpenSmart(tag_)+
    tag_.data+
    xmlClose(tag_)
  );
};


}
#endif
