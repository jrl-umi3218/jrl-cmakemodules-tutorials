#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MY_TEST

#include <boost/test/unit_test.hpp>

#include <jrl-cmakemodules/unittests/foo.h>

BOOST_AUTO_TEST_CASE(myTest)
{
  int a = 42;
  BOOST_CHECK_EQUAL(2*a, mylib::foo(a));
}
