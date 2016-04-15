#ifndef _CONFIG_GRAPHICS_H
#define _CONFIG_GRAPHICS_H

#include "config_macros.hpp"

#include <boost/python.hpp>
#include <iostream>

namespace bpy = boost::python;

namespace config {
  class conifig_graphics_base {
  protected:
    conifig_graphics_base() {}
    ~conifig_graphics_base() {}

  public:
    void set_resolution(int x, int y) {
      _x = x;
      _y = y;
    }

  private:
    int _x;
    int _y;
  };


  class conifig_graphics_wrapper : WRAPPER_CLASS(conifig_graphics_base) {
  public:
    conifig_graphics_wrapper(boost::reference_wrapper<const config::conifig_graphics_base>::type& x) : conifig_graphics_base(x) {}
    conifig_graphics_wrapper() : conifig_graphics_base() {}
    ~conifig_graphics_wrapper() {}

    //WRAPPER(void, conifig_graphics_base, overrideMe)

  };
}

#endif
