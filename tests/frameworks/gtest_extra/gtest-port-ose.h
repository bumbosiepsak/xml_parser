/**
    @b Project: Wump
    @file        gtest-port-ose.h
    @author      Szymon Gutaj
    @brief       
    @date        06-04-2011
    @version     0.1
    @b History:
     - 06-04-2011
       - sgutaj
         - Initial creation
*/

#ifndef TESTS_GTEST_GTEST_PORT_OSE_H_INCLUDED_
#define TESTS_GTEST_GTEST_PORT_OSE_H_INCLUDED_

#if defined(TESTS_OS_WINDOWS)

#elif defined(TESTS_OS_OSE)
 #define GTEST_OS_OSE 1
 #define MAX_PATH 30
#endif

#ifdef TESTS_APPEND_WCHAR_FUNCTIONS_TO_OSE_CLIB

#include <wchar.h>
#include <ctype.h>

int wcscmp(const wchar_t *ss1, const wchar_t *ss2);

wint_t towlower(const wchar_t wideChar);

wchar_t *wcsstr(const wchar_t *haystack, const wchar_t *needle);

#endif // TESTS_APPEND_WCHAR_FUNCTIONS_TO_OSE_CLIB

#if TESTS_OS_OSE
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
#endif  // TESTS_OS_OSE

#endif /* TESTS_GTEST_GTEST_PORT_OSE_H_INCLUDED_ */
