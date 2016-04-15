// based on boost python tutorial: http://www.boost.org/doc/libs/1_58_0/libs/python/doc/tutorial/doc/html/python/embedding.html
// usage: g++ -I/usr/include/boost  -I/usr/include/python3.4 main.cpp -o main -lpython3.4m -lboost_python3

#include <string>
#include <boost/python.hpp>
#include <boost/python/object.hpp>
#include <boost/filesystem.hpp>
#include <boost/timer/timer.hpp>
#include <iostream>

#include "config.hpp"

//using namespace boost::python;

namespace bpy = boost::python;
namespace bfs = boost::filesystem;

int main(int argc, char *argv[]) {
  std::cout << "Program startup!" << std::endl;

  boost::timer::auto_cpu_timer t;

  bfs::path basedir = bfs::system_complete(argv[0]).parent_path();
  bfs::path libdir = basedir / bfs::path("../lib");
  bfs::path confdir = basedir / bfs::path("../doc");

  try {
    // If you're going to use threads: PyEval_InitThreads();
    Py_Initialize();

    bpy::object main_module = bpy::import("__main__");
    bpy::object main_namespace = main_module.attr("__dict__");

    bpy::object sys = bpy::import("sys");
    bpy::object os = bpy::import("os");

    // Set up the environment variables (path and environment)
    sys.attr("path").attr("append")(libdir.string());
    sys.attr("path").attr("append")(confdir.string());

    os.attr("environ").attr("__setitem__")("LD_LIBRARY_PATH", libdir.string());

    // Now path has been set, we can import our own modules (yay!)
    bpy::object config = bpy::import("config");

    /* Put yur Python tizz 'ere */
    //bpy::object pythontest = bpy::exec("print('Hello from Python!');", main_namespace);

    // Python file
    bpy::object mainconfig = bpy::import("mainconfig");

    // Extracted code
    config::BaseWrap bw = bpy::extract<config::BaseWrap>(config.attr("Configs").attr("ClassConfig"));

    // Python code
    bpy::object x = config.attr("Configs").attr("ClassConfig");

    // Python Object
    std::cout << "Python function:" << std::endl;
    bpy::call_method<void>(x.ptr(), "overrideMe");

    // C++ class extracted from Python object
    std::cout << "Extracted C++ function:" << std::endl;
    bw.overrideMe();

    // Could get access to the parent function (the original C++ function) if required, but no need here

    // C++ function, hidden from python 'wrapping'
    //cg.print_resolution();

    std::cout << "Program finished!" << std::endl;
  }
  catch (bpy::error_already_set const&) {
    PyErr_Print();
  }

  return 0;
}
