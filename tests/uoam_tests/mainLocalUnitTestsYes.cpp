/**
    @b Project: Wump
    @file        mainLocalUnitTests.cpp
    @author      Szymon Gutaj
    @brief       Main interface function to UOAM tests for "tests enabled" case
    @date        29-03-2011
    @version     0.1
    @b History:
     - 29-03-2011
       - sgutaj
         - Initial creation
*/

#include <uoam_tests/frameworks.h>

namespace uoam_tests {

int run(int argc, char **argv)
{
    return uoam_tests::frameworks::run(argc, argv);
}

}
