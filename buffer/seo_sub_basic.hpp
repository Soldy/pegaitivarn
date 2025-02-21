
#ifndef __PAI_BUFFER_SEO_BASIC
#define __PAI_BUFFER_SEO_BASIC

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "seo_sub_helper.hpp"

namespace pai_buffer{

class SeoSubBasic{
  private:
    std::shared_ptr<
      pai_buffer::SeoSubHelper
    > _helper;
    void addLayer(
      std::string property_,
      std::vector<std::string> values_
    ){
        this->_helper->add(
          property_,
          values_
        );
    };
  public:
    SeoSubBasic(){
        this->_helper = std::make_shared<
          pai_buffer::SeoSubHelper
        >();
        this->_helper->set({
          {"canonical", {2,"rel"}},
          {"keywords", {2,"name"}},
          {"description", {2,"name"}},
          {"subject", {2,"name"}},
          {"copyright", {2,"name"}},
          {"description", {2,"name"}},
          {"language", {2,"name"}},
          {"robots", {2,"name"}},
          {"revised", {2,"name"}},
          {"abstract", {2,"name"}},
          {"topic", {2,"name"}},
          {"summary", {2,"name"}},
          {"Classification", {2,"name"}},
          {"author", {2,"name"}},
          {"designer", {2,"name"}},
          {"copyright", {2,"name"}},
          {"reply-to", {2,"name"}},
          {"owner", {2,"name"}},
          {"url", {2,"name"}},
          {"identifier-URL", {2,"name"}},
          {"directory", {2,"name"}},
          {"category", {2,"name"}},
          {"coverage", {2,"name"}},
          {"distribution", {2,"name"}},
          {"rating", {2,"name"}},
          {"revisit-after", {2, "7 days"}},
          {"template_type", {2,"name"}},
          {"type", {2,"name"}},
          {"name-section", {2,"name"}},
          {"name-branding", {2,"name"}},
          {"theme", {2,"name"}},
          {"Expires", {2, "http-equiv"}},
          {"Pragma", {2, "http-equiv"}},
          {"Cache-Control", {2, "http-equiv"}}
        });
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
    void add(
      std::string property_,
      std::string value_
    ){
        this->addLayer(
          property_,
          {value_}
        );
    };
    std::vector<std::string> get(
      std::string property_
    ){  
        return this->_helper->get("og:"+property_);
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
