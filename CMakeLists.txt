cmake_minimum_required(VERSION 3.16)

project(cpp_sphinx_documentation)

add_subdirectory(cpp_exe)

include(cmake/doxygen.cmake)
include(cmake/sphinx.cmake)
