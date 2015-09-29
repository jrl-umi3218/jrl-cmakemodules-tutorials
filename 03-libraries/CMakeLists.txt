cmake_minimum_required(VERSION 2.8)

include(cmake/base.cmake)
# We are going to find Boost here
include(cmake/boost.cmake)
include(cmake/pkg-config.cmake)

set(PROJECT_NAME jrl-cmakemodules-tutorials-03-libraries)
set(PROJECT_DESCRIPTION "A project description")
set(PROJECT_URL https://github.com/jrl-cmakemodules-tutorials)

set(HEADERS
  ${PROJECT_SOURCE_DIR}/include/jrl-cmakemodules-libraries/foo.h
)

setup_project()

# We are going to enable C++11 on this project
if(NOT WIN32)
  add_definitions(-std=c++0x)
endif()

# Note: this also add yaml-cpp to the Requires entry in the
# pkg-config file so we do not need to worry about that
add_required_dependency(yaml-cpp)

# Boost is found using the native cmake module
# The default set of components is: filesystem system thread program_options unit_test_framework
# We override it here
set(BOOST_COMPONENTS thread)
search_for_boost()

add_subdirectory(src)

header_install(${HEADERS})
setup_project_finalize()
