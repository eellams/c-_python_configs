#ifndef _CONFIG_CLASS_H
#define _CONFIG_CLASS_H

#include "config_macros.hpp"

#include <boost/python.hpp>
#include <iostream>

namespace bpy = boost::python;

namespace config {
  class BaseClass {
  protected:
    BaseClass() {}
    ~BaseClass() {}

  public:
    virtual void overrideMe() {
      std::cout << "Base function" << std::endl;
    }
  };


  class BaseWrap : WRAPPER_CLASS(BaseClass) {
  public:
    BaseWrap() : BaseClass() {}
    ~BaseWrap() {}

    WRAPPER(void, BaseClass, overrideMe)

  };
}

#endif
