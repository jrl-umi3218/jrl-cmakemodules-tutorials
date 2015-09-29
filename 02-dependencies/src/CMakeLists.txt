add_executable(jrl-cmakemodules-dependencies main.cpp)
# This is necessary to use the flags provided by pkg-config
pkg_config_use_dependency(jrl-cmakemodules-dependencies yaml-cpp)

# Since this dependency is optional, we need to check if it was found
if(NOT_A_REAL_PACKAGE_FOUND)
  pkg_config_use_dependency(jrl-cmakemodules-dependencies not-a-real-package)
endif()

install(TARGETS jrl-cmakemodules-dependencies DESTINATION bin)
