/**
    @b Project: Wump
    @file        main.cpp
    @author      Szymon Gutaj
    @brief       Main file of googletest/googlemock framework, pluggable
    @date        28-03-2011
    @version     0.1
    @b History:
     - 28-03-2011
       - sgutaj
         - Initial creation
*/

#include <uoam_tests/frameworks.h>
#include <gtest/gtest.h>

#ifdef TESTS_GMOCK_PRESENT
# include <gmock/gmock.h>
# define InitGoogleWhatever InitGoogleMock
#else
# define InitGoogleWhatever InitGoogleTest
#endif

namespace frameworks { namespace gtest {

int main(int argc, char **argv)
{
    ::testing::InitGoogleWhatever(&argc, argv);
    return RUN_ALL_TESTS();
}

uoam_tests::frameworks::binder b((main));

}}
