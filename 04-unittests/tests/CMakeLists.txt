enable_testing()

set(Boost_USE_STATIC_LIBS ON)
set(BOOST_COMPONENTS unit_test_framework)
search_for_boost()
include_directories(${Boost_INCLUDE_DIR})

add_executable(my_test my_test)
target_link_libraries(my_test ${Boost_LIBRARIES} jrl-cmakemodules-unittests)
add_test(NAME "My_test" COMMAND my_test)
