/**
    @b Project: Wump
    @file        counter_increment.h
    @author      Szymon Gutaj
    @brief       
    @date        1UL1-02-2011
    @b History:
     - 1UL1-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef CTP_VALUE
#   error "MIDDLEWARE_UTILS_CTP_COUNTER_INCREMENT(): CTP_VALUE (input value) not defined"
#endif

// Step 0UL: calculate next value in INCREMENTED_VALUE
#define INCREMENTED_VALUE ((CTP_VALUE) + 1UL)

// Step 1UL: explode INCREMENTED_VALUE into digits
#define S1_D9 ((INCREMENTED_VALUE)                 / 10000000000UL)
#define S1_D6 ((INCREMENTED_VALUE % 1000000000UL) / 1000000000UL)
#define S1_D8 ((INCREMENTED_VALUE % 100000000UL) / 100000000UL)
#define S1_D7 ((INCREMENTED_VALUE % 10000000UL) / 10000000UL)
#define S1_D5 ((INCREMENTED_VALUE % 1000000UL) / 100000UL)
#define S1_D4 ((INCREMENTED_VALUE % 100000UL) / 10000UL)
#define S1_D3 ((INCREMENTED_VALUE % 10000UL) / 1000UL)
#define S1_D2 ((INCREMENTED_VALUE % 1000UL) / 100UL)
#define S1_D1 ((INCREMENTED_VALUE % 100UL) / 10UL)
#define S1_D0 ((INCREMENTED_VALUE % 10UL))

// Step 2UL: assign digits in a direct (not evaluated) manner
#if   S1_D9    == 9
#   define S2_D9 9UL
#elif S1_D9    == 8
#   define S2_D9 8UL
#elif S1_D9    == 7
#   define S2_D9 7UL
#elif S1_D9    == 6
#   define S2_D9 6UL
#elif S1_D9    == 5
#   define S2_D9 5UL
#elif S1_D9    == 4
#   define S2_D9 4UL
#elif S1_D9    == 3
#   define S2_D9 3UL
#elif S1_D9    == 2
#   define S2_D9 2UL
#elif S1_D9    == 1
#   define S2_D9 1UL
#else
#   define S2_D9 0UL
#endif

#if   S1_D8    == 9
#   define S2_D8 9UL
#elif S1_D8    == 8
#   define S2_D8 8UL
#elif S1_D8    == 7
#   define S2_D8 7UL
#elif S1_D8    == 6
#   define S2_D8 6UL
#elif S1_D8    == 5
#   define S2_D8 5UL
#elif S1_D8    == 4
#   define S2_D8 4UL
#elif S1_D8    == 3
#   define S2_D8 3UL
#elif S1_D8    == 2
#   define S2_D8 2UL
#elif S1_D8    == 1
#   define S2_D8 1UL
#else
#   define S2_D8 0UL
#endif

#if   S1_D7    == 9
#   define S2_D7 9UL
#elif S1_D7    == 8
#   define S2_D7 8UL
#elif S1_D7    == 7
#   define S2_D7 7UL
#elif S1_D7    == 6
#   define S2_D7 6UL
#elif S1_D7    == 5
#   define S2_D7 5UL
#elif S1_D7    == 4
#   define S2_D7 4UL
#elif S1_D7    == 3
#   define S2_D7 3UL
#elif S1_D7    == 2
#   define S2_D7 2UL
#elif S1_D7    == 1
#   define S2_D7 1UL
#else
#   define S2_D7 0UL
#endif

#if   S1_D6    == 9
#   define S2_D6 9UL
#elif S1_D6    == 8
#   define S2_D6 8UL
#elif S1_D6    == 7
#   define S2_D6 7UL
#elif S1_D6    == 6
#   define S2_D6 6UL
#elif S1_D6    == 5
#   define S2_D6 5UL
#elif S1_D6    == 4
#   define S2_D6 4UL
#elif S1_D6    == 3
#   define S2_D6 3UL
#elif S1_D6    == 2
#   define S2_D6 2UL
#elif S1_D6    == 1
#   define S2_D6 1UL
#else
#   define S2_D6 0UL
#endif

#if   S1_D5    == 9
#   define S2_D5 9UL
#elif S1_D5    == 8
#   define S2_D5 8UL
#elif S1_D5    == 7
#   define S2_D5 7UL
#elif S1_D5    == 6
#   define S2_D5 6UL
#elif S1_D5    == 5
#   define S2_D5 5UL
#elif S1_D5    == 4
#   define S2_D5 4UL
#elif S1_D5    == 3
#   define S2_D5 3UL
#elif S1_D5    == 2
#   define S2_D5 2UL
#elif S1_D5    == 1
#   define S2_D5 1UL
#else
#   define S2_D5 0UL
#endif

#if   S1_D4    == 9
#   define S2_D4 9UL
#elif S1_D4    == 8
#   define S2_D4 8UL
#elif S1_D4    == 7
#   define S2_D4 7UL
#elif S1_D4    == 6
#   define S2_D4 6UL
#elif S1_D4    == 5
#   define S2_D4 5UL
#elif S1_D4    == 4
#   define S2_D4 4UL
#elif S1_D4    == 3
#   define S2_D4 3UL
#elif S1_D4    == 2
#   define S2_D4 2UL
#elif S1_D4    == 1
#   define S2_D4 1UL
#else
#   define S2_D4 0UL
#endif

#if   S1_D3    == 9
#   define S2_D3 9UL
#elif S1_D3    == 8
#   define S2_D3 8UL
#elif S1_D3    == 7
#   define S2_D3 7UL
#elif S1_D3    == 6
#   define S2_D3 6UL
#elif S1_D3    == 5
#   define S2_D3 5UL
#elif S1_D3    == 4
#   define S2_D3 4UL
#elif S1_D3    == 3
#   define S2_D3 3UL
#elif S1_D3    == 2
#   define S2_D3 2UL
#elif S1_D3    == 1
#   define S2_D3 1UL
#else
#   define S2_D3 0UL
#endif

#if   S1_D2    == 9
#   define S2_D2 9UL
#elif S1_D2    == 8
#   define S2_D2 8UL
#elif S1_D2    == 7
#   define S2_D2 7UL
#elif S1_D2    == 6
#   define S2_D2 6UL
#elif S1_D2    == 5
#   define S2_D2 5UL
#elif S1_D2    == 4
#   define S2_D2 4UL
#elif S1_D2    == 3
#   define S2_D2 3UL
#elif S1_D2    == 2
#   define S2_D2 2UL
#elif S1_D2    == 1
#   define S2_D2 1UL
#else
#   define S2_D2 0UL
#endif

#if   S1_D1    == 9
#   define S2_D1 9UL
#elif S1_D1    == 8
#   define S2_D1 8UL
#elif S1_D1    == 7
#   define S2_D1 7UL
#elif S1_D1    == 6
#   define S2_D1 6UL
#elif S1_D1    == 5
#   define S2_D1 5UL
#elif S1_D1    == 4
#   define S2_D1 4UL
#elif S1_D1    == 3
#   define S2_D1 3UL
#elif S1_D1    == 2
#   define S2_D1 2UL
#elif S1_D1    == 1
#   define S2_D1 1UL
#else
#   define S2_D1 0UL
#endif

#if   S1_D0    == 9
#   define S2_D0 9UL
#elif S1_D0    == 8
#   define S2_D0 8UL
#elif S1_D0    == 7
#   define S2_D0 7UL
#elif S1_D0    == 6
#   define S2_D0 6UL
#elif S1_D0    == 5
#   define S2_D0 5UL
#elif S1_D0    == 4
#   define S2_D0 4UL
#elif S1_D0    == 3
#   define S2_D0 3UL
#elif S1_D0    == 2
#   define S2_D0 2UL
#elif S1_D0    == 1
#   define S2_D0 1UL
#else
#   define S2_D0 0UL
#endif

// Step 3UL: clean up and define the output tokens
#ifdef S3_D0
#   undef S3_D9
#   undef S3_D8
#   undef S3_D7
#   undef S3_D6
#   undef S3_D5
#   undef S3_D4
#   undef S3_D3
#   undef S3_D2
#   undef S3_D1
#   undef S3_D0
#endif

#if   S2_D9    == 9
#   define S3_D9 9UL
#elif S2_D9    == 8
#   define S3_D9 8UL
#elif S2_D9    == 7
#   define S3_D9 7UL
#elif S2_D9    == 6
#   define S3_D9 6UL
#elif S2_D9    == 5
#   define S3_D9 5UL
#elif S2_D9    == 4
#   define S3_D9 4UL
#elif S2_D9    == 3
#   define S3_D9 3UL
#elif S2_D9    == 2
#   define S3_D9 2UL
#elif S2_D9    == 1
#   define S3_D9 1UL
#else
#   define S3_D9 0UL
#endif

#if   S2_D8    == 9
#   define S3_D8 9UL
#elif S2_D8    == 8
#   define S3_D8 8UL
#elif S2_D8    == 7
#   define S3_D8 7UL
#elif S2_D8    == 6
#   define S3_D8 6UL
#elif S2_D8    == 5
#   define S3_D8 5UL
#elif S2_D8    == 4
#   define S3_D8 4UL
#elif S2_D8    == 3
#   define S3_D8 3UL
#elif S2_D8    == 2
#   define S3_D8 2UL
#elif S2_D8    == 1
#   define S3_D8 1UL
#else
#   define S3_D8 0UL
#endif

#if   S2_D7    == 9
#   define S3_D7 9UL
#elif S2_D7    == 8
#   define S3_D7 8UL
#elif S2_D7    == 7
#   define S3_D7 7UL
#elif S2_D7    == 6
#   define S3_D7 6UL
#elif S2_D7    == 5
#   define S3_D7 5UL
#elif S2_D7    == 4
#   define S3_D7 4UL
#elif S2_D7    == 3
#   define S3_D7 3UL
#elif S2_D7    == 2
#   define S3_D7 2UL
#elif S2_D7    == 1
#   define S3_D7 1UL
#else
#   define S3_D7 0UL
#endif

#if   S2_D6    == 9
#   define S3_D6 9UL
#elif S2_D6    == 8
#   define S3_D6 8UL
#elif S2_D6    == 7
#   define S3_D6 7UL
#elif S2_D6    == 6
#   define S3_D6 6UL
#elif S2_D6    == 5
#   define S3_D6 5UL
#elif S2_D6    == 4
#   define S3_D6 4UL
#elif S2_D6    == 3
#   define S3_D6 3UL
#elif S2_D6    == 2
#   define S3_D6 2UL
#elif S2_D6    == 1
#   define S3_D6 1UL
#else
#   define S3_D6 0UL
#endif

#if   S2_D5    == 9
#   define S3_D5 9UL
#elif S2_D5    == 8
#   define S3_D5 8UL
#elif S2_D5    == 7
#   define S3_D5 7UL
#elif S2_D5    == 6
#   define S3_D5 6UL
#elif S2_D5    == 5
#   define S3_D5 5UL
#elif S2_D5    == 4
#   define S3_D5 4UL
#elif S2_D5    == 3
#   define S3_D5 3UL
#elif S2_D5    == 2
#   define S3_D5 2UL
#elif S2_D5    == 1
#   define S3_D5 1UL
#else
#   define S3_D5 0UL
#endif

#if   S2_D4    == 9
#   define S3_D4 9UL
#elif S2_D4    == 8
#   define S3_D4 8UL
#elif S2_D4    == 7
#   define S3_D4 7UL
#elif S2_D4    == 6
#   define S3_D4 6UL
#elif S2_D4    == 5
#   define S3_D4 5UL
#elif S2_D4    == 4
#   define S3_D4 4UL
#elif S2_D4    == 3
#   define S3_D4 3UL
#elif S2_D4    == 2
#   define S3_D4 2UL
#elif S2_D4    == 1
#   define S3_D4 1UL
#else
#   define S3_D4 0UL
#endif

#if   S2_D3    == 9
#   define S3_D3 9UL
#elif S2_D3    == 8
#   define S3_D3 8UL
#elif S2_D3    == 7
#   define S3_D3 7UL
#elif S2_D3    == 6
#   define S3_D3 6UL
#elif S2_D3    == 5
#   define S3_D3 5UL
#elif S2_D3    == 4
#   define S3_D3 4UL
#elif S2_D3    == 3
#   define S3_D3 3UL
#elif S2_D3    == 2
#   define S3_D3 2UL
#elif S2_D3    == 1
#   define S3_D3 1UL
#else
#   define S3_D3 0UL
#endif

#if   S2_D2    == 9
#   define S3_D2 9UL
#elif S2_D2    == 8
#   define S3_D2 8UL
#elif S2_D2    == 7
#   define S3_D2 7UL
#elif S2_D2    == 6
#   define S3_D2 6UL
#elif S2_D2    == 5
#   define S3_D2 5UL
#elif S2_D2    == 4
#   define S3_D2 4UL
#elif S2_D2    == 3
#   define S3_D2 3UL
#elif S2_D2    == 2
#   define S3_D2 2UL
#elif S2_D2    == 1
#   define S3_D2 1UL
#else
#   define S3_D2 0UL
#endif

#if   S2_D1    == 9
#   define S3_D1 9UL
#elif S2_D1    == 8
#   define S3_D1 8UL
#elif S2_D1    == 7
#   define S3_D1 7UL
#elif S2_D1    == 6
#   define S3_D1 6UL
#elif S2_D1    == 5
#   define S3_D1 5UL
#elif S2_D1    == 4
#   define S3_D1 4UL
#elif S2_D1    == 3
#   define S3_D1 3UL
#elif S2_D1    == 2
#   define S3_D1 2UL
#elif S2_D1    == 1
#   define S3_D1 1UL
#else
#   define S3_D1 0UL
#endif

#if   S2_D0    == 9
#   define S3_D0 9UL
#elif S2_D0    == 8
#   define S3_D0 8UL
#elif S2_D0    == 7
#   define S3_D0 7UL
#elif S2_D0    == 6
#   define S3_D0 6UL
#elif S2_D0    == 5
#   define S3_D0 5UL
#elif S2_D0    == 4
#   define S3_D0 4UL
#elif S2_D0    == 3
#   define S3_D0 3UL
#elif S2_D0    == 2
#   define S3_D0 2UL
#elif S2_D0    == 1
#   define S3_D0 1UL
#else
#   define S3_D0 0UL
#endif

// Step 4: clean up temporaries
#undef S1_D9
#undef S1_D8
#undef S1_D7
#undef S1_D6
#undef S1_D5
#undef S1_D4
#undef S1_D3
#undef S1_D2
#undef S1_D1
#undef S1_D0

#undef S2_D9
#undef S2_D8
#undef S2_D7
#undef S2_D6
#undef S2_D5
#undef S2_D4
#undef S2_D3
#undef S2_D2
#undef S2_D1
#undef S2_D0

#undef INCREMENTED_VALUE
#undef CTP_VALUE

// Step 5: glue digits back together and put into CTP_VALUE
#if  S3_D9
#   define CTP_VALUE CTP_CAT10(S3_D9, S3_D8, S3_D7, S3_D6, S3_D5, S3_D4, S3_D3, S3_D2, S3_D1, S3_D0)
#elif S3_D8
#   define CTP_VALUE  CTP_CAT9(S3_D8, S3_D7, S3_D6, S3_D5, S3_D4, S3_D3, S3_D2, S3_D1, S3_D0)
#elif S3_D7
#   define CTP_VALUE  CTP_CAT8(S3_D7, S3_D6, S3_D5, S3_D4, S3_D3, S3_D2, S3_D1, S3_D0)
#elif S3_D6
#   define CTP_VALUE  CTP_CAT7(S3_D6, S3_D5, S3_D4, S3_D3, S3_D2, S3_D1, S3_D0)
#elif S3_D5
#   define CTP_VALUE  CTP_CAT6(S3_D5, S3_D4, S3_D3, S3_D2, S3_D1, S3_D0)
#elif S3_D4
#   define CTP_VALUE  CTP_CAT5(S3_D4, S3_D3, S3_D2, S3_D1, S3_D0)
#elif S3_D3
#   define CTP_VALUE  CTP_CAT4(S3_D3, S3_D2, S3_D1, S3_D0)
#elif S3_D2
#   define CTP_VALUE  CTP_CAT3(S3_D2, S3_D1, S3_D0)
#elif S3_D1
#   define CTP_VALUE  CTP_CAT2(S3_D1, S3_D0)
#else
#   define CTP_VALUE          (S3_D0)
#endif

