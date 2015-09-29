cmake_minimum_required(VERSION 2.8)

include(cmake/base.cmake)
# This additional include is needed to use pkg-config macros
include(cmake/pkg-config.cmake)

set(PROJECT_NAME jrl-cmakemodules-tutorials-02-dependencies)
set(PROJECT_DESCRIPTION "A project description")
set(PROJECT_URL https://github.com/jrl-cmakemodules-tutorials)

setup_project()

# We are going to enable C++11 on this project
if(NOT WIN32)
  add_definitions(-std=c++0x)
endif()

# The following macro uses pkg-config to get the appropriate flags for compilation
add_required_dependency(yaml-cpp)
# Note: the call may include a version string, e.g.
#add_required_dependency("yaml-cpp > 0.5")

# An optional package can be searched this way
add_optional_dependency(not-a-real-package)

add_subdirectory(src)

setup_project_finalize()
