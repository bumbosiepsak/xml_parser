/**
    @b Project: Wump
    @file        cat.h
    @author      Szymon Gutaj
    @brief       
    @date        11-02-2011
    @b History:
     - 11-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CTP_CAT_H_INCLUDED_
#define MIDDLEWARE_UTILS_CTP_CAT_H_INCLUDED_

#define  _CTP_CAT2(U1, U0)                                  U1##U0
#define  _CTP_CAT3(U2, U1, U0)                              U2##U1##U0
#define  _CTP_CAT4(U3, U2, U1, U0)                          U3##U2##U1##U0
#define  _CTP_CAT5(U4, U3, U2, U1, U0)                      U4##U3##U2##U1##U0
#define  _CTP_CAT6(U5, U4, U3, U2, U1, U0)                  U5##U4##U3##U2##U1##U0
#define  _CTP_CAT7(U6, U5, U4, U3, U2, U1, U0)              U6##U5##U4##U3##U2##U1##U0
#define  _CTP_CAT8(U7, U6, U5, U4, U3, U2, U1, U0)          U7##U6##U5##U4##U3##U2##U1##U0
#define  _CTP_CAT9(U8, U7, U6, U5, U4, U3, U2, U1, U0)      U8##U7##U6##U5##U4##U3##U2##U1##U0
#define _CTP_CAT10(U9, U8, U7, U6, U5, U4, U3, U2, U1, U0)  U9##U8##U7##U6##U5##U4##U3##U2##U1##U0

#define  CTP_CAT2(T1, T0)                                  _CTP_CAT2(T1,T0)
#define  CTP_CAT3(T2, T1, T0)                              _CTP_CAT3(T2,T1,T0)
#define  CTP_CAT4(T3, T2, T1, T0)                          _CTP_CAT4(T3,T2,T1,T0)
#define  CTP_CAT5(T4, T3, T2, T1, T0)                      _CTP_CAT5(T4,T3,T2,T1,T0)
#define  CTP_CAT6(T5, T4, T3, T2, T1, T0)                  _CTP_CAT6(T5,T4,T3,T2,T1,T0)
#define  CTP_CAT7(T6, T5, T4, T3, T2, T1, T0)              _CTP_CAT7(T6,T5,T4,T3,T2,T1,T0)
#define  CTP_CAT8(T7, T6, T5, T4, T3, T2, T1, T0)          _CTP_CAT8(T7,T6,T5,T4,T3,T2,T1,T0)
#define  CTP_CAT9(T8, T7, T6, T5, T4, T3, T2, T1, T0)      _CTP_CAT9(T8,T7,T6,T5,T4,T3,T2,T1,T0)
#define CTP_CAT10(T9, T8, T7, T6, T5, T4, T3, T2, T1, T0) _CTP_CAT10(T9,T8,T7,T6,T5,T4,T3,T2,T1,T0)

#endif /* MIDDLEWARE_UTILS_CTP_CAT_H_INCLUDED_ */
