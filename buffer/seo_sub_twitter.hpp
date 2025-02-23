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
    void addLayer(
      std::string property_,
      std::vector<std::string> values_
    ){
        if(this->_helper->propertyCheck(property_))
          return this->_helper->add(
            property_,
            values_
          );
        std::string _ext_prop = ("twitter:"+property_);
        if(this->_helper->propertyCheck(_ext_prop))
          return this->_helper->add(
            _ext_prop,
            values_
          );
    };
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
      std::string value_
    ){
        this->addLayer(
          property_,
          {value_}
        );
    };
    void add(
      std::string property_,
      std::vector<std::string> values_
    ){
        this->addLayer(
          property_,
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
