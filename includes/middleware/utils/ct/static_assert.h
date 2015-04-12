/**
    @b Project: Wump
    @file        static_assert.h
    @author      Szymon Gutaj
    @brief       Static (compile-time) assertion
    @date        17-03-2011
    @b History:
     - 17-03-2011 (sgutaj)
      - Initial creation
*/

#ifndef UOAM_RP1_INNER_STATIC_ASSERT_H_INCLUDED_
#define UOAM_RP1_INNER_STATIC_ASSERT_H_INCLUDED_

#define MIDDLEWARE_UTILS_CT_STATIC_ASSERT_CAT(TEXT1, TEXT2, TEXT3, TEXT4) \
    MIDDLEWARE_UTILS_CT_STATIC_ASSERT_CAT_(TEXT1, TEXT2, TEXT3, TEXT4)

#define MIDDLEWARE_UTILS_CT_STATIC_ASSERT_CAT_(TEXT1, TEXT2, TEXT3, TEXT4) \
    TEXT1##TEXT2##TEXT3##TEXT4

#define MIDDLEWARE_UTILS_CT_STATIC_ASSERT_TO_BOOL(CONDITION) \
    (CONDITION) ? 1 : -1

/**
 * @def ct_static_assert(CONDITION, TEXT)
 * @arg \c CONDITION Boolean (or convertible to bool) condition
 * @arg \c TEXT Descriptive text printed on failure. Must be a valid C\C++ name (no spaces)
 */
#define ct_static_assert(CONDITION, TEXT) \
    typedef int MIDDLEWARE_UTILS_CT_STATIC_ASSERT_CAT(STATIC_ASSERTION_FAILED_AT_LINE_,__LINE__,__,TEXT) \
        [MIDDLEWARE_UTILS_CT_STATIC_ASSERT_TO_BOOL(CONDITION)]

#endif /* UOAM_RP1_INNER_STATIC_ASSERT_H_INCLUDED_ */
