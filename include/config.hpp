#ifndef _CONFIG_H
#define _CONFIG_H

#include "config_graphics.hpp"
#include "config_class.hpp"

#include <boost/python.hpp>

namespace bpy = boost::python;

namespace config {

  // configs contains all of the structures that can be changed in the config files
  struct config {
    //config_graphics GraphicsConfig;
    conifig_graphics_wrapper GraphicsConfig;

    BaseWrap ClassConfig;

  } configs;

}

#endif
