/**
    @b Project: Wump
    @file        gtest-port-ose.cpp
    @author      Szymon Gutaj
    @brief       This file defines functions missing in OSE standard clib
    @date        28-03-2011
    @version     0.1
    @b History:
     - 28-03-2011
       - sgutaj
         - Initial creation
*/

#include <frameworks/gtest_extra/gtest-port-ose.h>

#ifdef TESTS_APPEND_WCHAR_FUNCTIONS_TO_OSE_CLIB

int wcscmp(const wchar_t *ss1, const wchar_t *ss2)
{
    wchar_t *s1 = (wchar_t*)ss1;
    wchar_t *s2 = (wchar_t*)ss2;

    while((*s1 && *s2) && (*s1 == *s2)) {
        s1++,s2++;
    }

    return *s1 - *s2;
}

wint_t towlower(const wchar_t wideChar)
{
    return (wint_t)tolower((char)wideChar);
}

wchar_t *wcsstr(const wchar_t *haystack, const wchar_t *needle)
{
    const wchar_t *p;
    const wchar_t *q;
    const wchar_t *r;

    if (!*needle)
    {
        return (wchar_t *) haystack;
    }
    if (wcslen (haystack) < wcslen (needle))
    return 0;

    p = haystack;
    q = needle;

    while (*p)
    {
        q = needle;
        r = p;

        while (*q)
        {
            if (*r != *q)
            break;
            q++;
            r++;
        }
        if (!*q)
        {
            return (wchar_t *) p;
        }
        p++;
    }
    return 0;
}

#endif //TESTS_APPEND_WCHAR_FUNCTIONS_TO_OSE_CLIB
