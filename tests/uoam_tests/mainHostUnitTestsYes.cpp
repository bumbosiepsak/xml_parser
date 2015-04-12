/**
    @b Project: Wump
    @file        mainHostUnitTestsYes.cpp
    @author      Szymon Gutaj
    @brief       Main interface function to UOAM tests for "tests on host" case, tests included
    @date        28-03-2011
    @version     0.1
    @b History:
     - 28-03-2011
       - sgutaj
         - Initial creation
*/

#include <uoam_tests/frameworks.h>

int main(int argc, char **argv)
{
    return uoam_tests::frameworks::run(argc, argv);
}
