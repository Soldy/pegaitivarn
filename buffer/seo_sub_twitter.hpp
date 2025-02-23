#ifndef __PAI_BUFFER_SEO_TWITTER
#define __PAI_BUFFER_SEO_TWITTER

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "seo_sub_helper.hpp"

namespace pai_buffer{

class SeoSubTwitter{
  private:
    std::shared_ptr<
      pai_buffer::SeoSubHelper
    > _helper;
  public:
    SeoSubTwitter(){
        this->_helper = std::make_shared<
          pai_buffer::SeoSubHelper
        >();
        this->_helper->set({
          {"me", {2,"rel"}}, // url of twitter page
          {"twitter:widgets:theme", {2,"name"}}, // card thame dark 
          {"twitter:dnt", {2,"name"}}, // do not track on off 
          {"twitter:widgets:csp", {2,"name"}}, //Content Security Policy on off 
          {"twitter:card", {2,"name"}},
          {"twitter:site", {2,"name"}},
          {"twitter:creator", {2,"name"}},
          {"twitter:title", {2,"name"}},
          {"twitter:description", {2,"name"}},
          {"twitter:image", {2,"name"}},
          {"twitter:image:alt", {2,"name"}},
          {"twitter:domain", {2,"property"}},
          {"twitter:url", {2,"property"}}
        });
    };
    void add(
      std::string property_,
      std::vector<std::string> values_
    ){
        this->_helper->add(
          ("twitter:"+property_),
          values_
        );
    };
    std::vector<std::string> get(
      std::string property_
    ){  
        return this->_helper->get("twitter:"+property_);
    };
    std::vector<pai_text::XmlTag> xml(){
        return this->_helper->xml();
    };
    std::string render(){
        return this->_helper->render();
    };
};

};

#endif
