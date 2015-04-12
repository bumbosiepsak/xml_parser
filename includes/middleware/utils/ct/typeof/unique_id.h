/**
    @b Project: Wump
    @file        unique_id.h
    @author      Szymon Gutaj
    @brief       
    @date        11-02-2011
    @b History:
     - 11-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_TYPEOF_UNIQUE_ID_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_TYPEOF_UNIQUE_ID_H_INCLUDED_

#include <middleware/utils/ctp/counter.h>

#define CTP_VALUE 0UL

#define MIDDLEWARE_UTILS_CT_TYPEOF_UNIQUE_ID_GROUP_INCREMENT() CTP_COUNTER_INCREMENT()

// Future use: related types (*, const, volatile) registration/recognition
#define MIDDLEWARE_UTILS_CT_TYPEOF_UNIQUE_ID_GROUP_RELATED_TYPES_CNT 10UL

#define MIDDLEWARE_UTILS_CT_TYPEOF_UNIQUE_ID ((CTP_VALUE * 0x0100000) + (__LINE__ * MIDDLEWARE_UTILS_CT_TYPEOF_UNIQUE_ID_GROUP_RELATED_TYPES_CNT))

#endif /* MIDDLEWARE_UTILS_CT_TYPEOF_UNIQUE_ID_H_INCLUDED_ */
