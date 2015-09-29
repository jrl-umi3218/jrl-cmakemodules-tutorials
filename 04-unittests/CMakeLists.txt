cmake_minimum_required(VERSION 2.8)

include(cmake/base.cmake)
include(cmake/boost.cmake)
include(cmake/pkg-config.cmake)

set(PROJECT_NAME jrl-cmakemodules-tutorials-04-unittests)
set(PROJECT_DESCRIPTION "A project description")
set(PROJECT_URL https://github.com/jrl-cmakemodules-tutorials)

set(HEADERS
  ${PROJECT_SOURCE_DIR}/include/jrl-cmakemodules/unittests/foo.h
)

setup_project()

add_subdirectory(src)
add_subdirectory(tests)

header_install(${HEADERS})
setup_project_finalize()
