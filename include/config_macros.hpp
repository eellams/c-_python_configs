#ifndef _CONFIG_MACROS_H
#define _CONFIG_MACROS_H

#define STRINGIFY(x) #x

#define WRAPPER(TYPE, CLASS, FUNCTION, ARGS...) TYPE FUNCTION(ARGS) { \
    if (boost::python::override FUNCTION = this->get_override( STRINGIFY(FUNCTION) )) { FUNCTION(ARGS); } \
    else return CLASS::FUNCTION(ARGS); \
  } \
  TYPE default_##FUNCTION(ARGS) { return this->CLASS::FUNCTION(ARGS); }

#define WRAPPER_CLASS(CLASS) public CLASS, public boost::python::wrapper<CLASS>

#endif
