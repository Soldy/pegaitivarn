#ifndef __PAI_BUFFER_SEO_OPENGRAPH
#define __PAI_BUFFER_SEO_OPENGRAPH

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "seo_sub_helper.hpp"

namespace pai_buffer{

class SeoSubOpengraph{
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
        std::string _ext_prop = ("og:"+property_);
        if(this->_helper->propertyCheck(_ext_prop))
          return this->_helper->add(
            _ext_prop,
            values_
          );
        _ext_prop = ("article:"+property_);
        if(this->_helper->propertyCheck(_ext_prop))
          return this->_helper->add(
            _ext_prop,
            values_
          );
        _ext_prop = ("fb:"+property_);
        if(this->_helper->propertyCheck(_ext_prop))
          return this->_helper->add(
            _ext_prop,
            values_
          );
    };
  public:
    SeoSubOpengraph(){
        this->_helper = std::make_shared<
          pai_buffer::SeoSubHelper
        >();
        this->_helper->set({
          {"og:title", {2, "name"}},
          {"og:url", {2, "name"}},
          {"og:description", {2,"name"}},
          {"og:image", {2, "name"}},
          {"og:site_name", {2, "name"}},
          {"og:email", {2, "name"}},
          {"og:phone_number", {2, "name"}},
          {"og:fax_number", {2, "name"}},
          {"og:latitude", {2, "name"}},
          {"og:longitude", {2, "name"}},
          {"og:street-address", {2, "name"}},
          {"og:locality", {2, "name"}},
          {"og:region", {2, "name"}},
          {"og:post-code", {2, "name"}},
          {"og:country-name", {2, "name"}},
          {"og:type", {2, "property"}},
          {"og:points", {2, "property"}},
          {"og:video", {2, "property"}},
          {"og:video:type", {2, "property"}},
          {"og:video:height", {2, "property"}},
          {"og:video:width", {2, "property"}},
          {"og:audio", {2, "property"}},
          {"og:audio:title", {2, "property"}},
          {"og:audio:artist", {2, "property"}},
          {"og:audio:album", {2, "property"}},
          {"og:audio:type", {2, "property"}},
          {"article:publisher_time", {2, "property"}},
          {"article:modified_time", {2, "property"}},
          {"article:section", {2, "property"}},
          {"article:tag", {2, "property"}},
          {"fb:page_id", {2, "name"}},
          {"fb:admins", {2, "property"}}
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
