/**
    @b Project: Wump
    @file        messages.h
    @author      Szymon Gutaj
    @brief       
    @date        11-04-2011
    @version     0.1
    @b History:
     - 11-04-2011
       - sgutaj
         - Initial creation
*/

#ifndef UOAM_TESTS_MESSAGES_H_INCLUDED_
#define UOAM_TESTS_MESSAGES_H_INCLUDED_

#include <iostream>

namespace {

void message_no_unit_tests()
{
    using namespace std;

    cout << "This build has been compiled in production version. Unit tests not present." << endl;
}

}


#endif /* UOAM_TESTS_MESSAGES_H_INCLUDED_ */
