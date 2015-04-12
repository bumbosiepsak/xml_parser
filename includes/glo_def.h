/**
*******************************************************************************
* @file                  glo_def.h
* @version               wn#1.4
* @date                  09-FEB-2007 10:34:27
* @author                MAROJALA
*
* Item Specification     WCDMA:A506.A-SRC
*
* Status                 DRAFT
*
* Original author        Näsi Petri
*
* Copyright (c) Nokia 2007. All rights reserved.
*******************************************************************************/

#ifndef _GLO_DEF_H
#define _GLO_DEF_H

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

/* Global defition */
#define GLO_TRUE    1
#define GLO_FALSE   0
#define GLO_NULL  0
#define MAX_NUM_OF_FAULT_INFO 5

/* Global type defintions */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;     /* int == long */
typedef signed char    i8;
typedef signed short   i16;
typedef signed int     i32;     /* int == long */
typedef float          r32;     /* Do not use this in DSP */
typedef double         r64;     /* Do not use this in DSP */
typedef long double    r128;    /* Do not use this in DSP */
typedef unsigned char  *pu8;
typedef u8             *pu8h;
typedef unsigned short *pu16;
typedef unsigned int   *pu32;
typedef signed char    *pi8;
typedef signed short   *pi16;
typedef signed int     *pi32;

typedef unsigned char       GLO_BOOLEAN;

typedef u32            TBoolean;
typedef unsigned long MESSAGEID;
typedef MESSAGEID TMsgId;


/* For AGERE SC100 C complier */
/* For compilation only, X. Song 14.06.2001*/
typedef struct {
    long first;
    long second;
} sc100_u64;


#ifdef __DCC__ /* For diab compiler environment */

typedef unsigned long long u64;
typedef signed long long i64;

#endif

#ifdef __GNUC__ /* For GNU C compiler environment */

typedef unsigned long long u64;
typedef signed long long i64;

#endif



#ifdef __MSC__ /* For microsoft compiler environment */

typedef unsigned __int64 u64;
typedef __int64 i64;

#endif



#ifdef __TCC__ /* For texas compiler environment */

typedef unsigned long long u64;
typedef signed long long i64;

#endif

#ifdef __SC100__ /* For AGERE SC100 C complier */
 /* For compilation only, X. Song 14.06.2001*/
typedef sc100_u64 u64;
typedef sc100_u64 i64; /* WARNING Note: Starpro2000 DSP does not support U64 or i64 data type */

#endif



#ifdef __cplusplus
}
#endif

#endif /* _GLO_DEF_H */

/**
*******************************************************************************
* @typedef glo_def
* Development Workset : WCDMA:BTS_ENV_WS
*
* Design Part         : WCDMA:COMMON
*
* Description         : GLOBAL BS DEFINITIONS
*
* Reference           : <type interface spec., version, location here>
*                       <type 3GPP or other spec. notation here>
*
*
* Additional Information : <type additional information if needed>
*
* Definition Provided by : BTS-RAN1 SACK / Lomu Mika
*
* Remember to put an empty line in the end of each definition
* file. Otherwise the compiler will generate a warning.
************************************************************************/



