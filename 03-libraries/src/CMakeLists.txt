add_library(jrl-cmakemodules-libraries SHARED lib.cpp)
pkg_config_use_dependency(jrl-cmakemodules-libraries yaml-cpp)
# Linking to boost libraries
target_link_libraries(jrl-cmakemodules-libraries ${Boost_LIBRARIES})

# This adds Libs entries in the pkg-config file
pkg_config_append_libs(jrl-cmakemodules-libraries)
pkg_config_append_libs(${Boost_LIBRARIES})

install(TARGETS jrl-cmakemodules-libraries 
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
