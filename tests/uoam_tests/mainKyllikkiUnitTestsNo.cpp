/**
    @b Project: Wump
    @file        mainKyllikkiUnitTestsNo.cpp
    @author      Szymon Gutaj
    @brief       Main interface function to UOAM tests for "tests disabled" case, Kyllikki build
    @date        30-03-2011
    @version     0.1
    @b History:
     - 30-03-2011
       - sgutaj
         - Initial creation
*/

#include <uoam_tests/messages.h>

namespace uoam_tests {

int run(int argc, char **argv)
{
    message_no_unit_tests();

    return 0;
}

}
