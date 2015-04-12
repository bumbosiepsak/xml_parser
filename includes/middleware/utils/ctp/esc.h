/**
    @b Project: Wump
    @file        esc.h
    @author      Szymon Gutaj
    @brief       Wrapper for escaping commas in preprocessor's macro arguments
    @date        11-04-2011
    @b History:
     - 11-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CTP_ESC_H_INCLUDED_
#define MIDDLEWARE_UTILS_CTP_ESC_H_INCLUDED_

#define  CTP_ESC(...) __VA_ARGS__

#endif /* MIDDLEWARE_UTILS_CTP_ESC_H_INCLUDED_ */
