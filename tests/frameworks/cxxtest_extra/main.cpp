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

#define _CXXTEST_HAVE_STD

#include <uoam_tests/frameworks.h>
#include <cxxtest/ErrorPrinter.h>

#include <cxxtest_generated_tests.h>

namespace frameworks { namespace cxxtest {

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    return CxxTest::ErrorPrinter().run();
}

uoam_tests::frameworks::binder b((main));

}}
