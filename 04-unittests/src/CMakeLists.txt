add_library(jrl-cmakemodules-unittests SHARED foo.cpp)

# This adds Libs entries in the pkg-config file
pkg_config_append_libs(jrl-cmakemodules-unittests)

install(TARGETS jrl-cmakemodules-unittests
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
