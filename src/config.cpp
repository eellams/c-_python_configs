#include "config.hpp"

BOOST_PYTHON_MODULE(config)
{
  // The Configs class contains singleton
  bpy::class_<config::config>("Configs")
    .def_readwrite("GraphicsConfig", &config::configs.GraphicsConfig)

    .def_readwrite("ClassConfig", &config::configs.ClassConfig)
  ;

  // Python accessible parts of the graphcis config
  bpy::class_<config::conifig_graphics_wrapper>("GraphicsConfig")
    .def("setResolution", &config::conifig_graphics_wrapper::set_resolution, bpy::args("x", "y"), "Set the resolution")
  ;

  bpy::class_<config::BaseWrap, boost::noncopyable>("BaseClass")
    .def("overrideMe", &config::BaseClass::overrideMe, &config::BaseWrap::default_overrideMe)
    ;
}
