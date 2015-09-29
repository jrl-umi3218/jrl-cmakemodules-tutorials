cmake_minimum_required(VERSION 2.8)

include(cmake/base.cmake)

# These variables have to be defined before running setup_project
set(PROJECT_NAME jrl-cmakemodules-tutorials-01-introduction)
set(PROJECT_DESCRIPTION "A project description")
set(PROJECT_URL https://github.com/jrl-cmakemodules-tutorials)

setup_project()

add_subdirectory(src)

# This should be called at the end
setup_project_finalize()
