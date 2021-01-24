cmake_minimum_required(VERSION 3.0)

project(COMPUTERATOR VERSION 0.0.0 LANGUAGES CXX C)

find_package(wxWidgets REQUIRED core base xrc)
include(${wxWidgets_USE_FILE})

#compiler settings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2")
include_directories(${wxWidgets_INCLUDE_DIRS})

#project directories
add_subdirectory(Computerator)
add_subdirectory(Resources)
