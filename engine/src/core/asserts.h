#pragma once

#include "defines.h"

// Disable assertions by commenting out the below line
#define JASSERTIONS_ENABLED

#ifdef JASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

JAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define JASSERT(expr)                                                   \
    {                                                                   \
        if(expr){                                                       \
        }else{                                                          \
            report_assertion_failure(#expr, "", __FILE__, __LINE__);    \
            debugBreak();                                               \
        }                                                               \
    } 

#define JASSERT_MSG(expr, message)                                              \
    {                                                                           \
        if(expr){                                                               \
        }else{                                                                  \
            report_assertion_failure(#expr, message, __FILE__, __LINE__);       \
            debugBreak();                                                       \
        }                                                                       \
    } 

#ifdef _DEBUG
#define JASSERT_DEBUG(expr)                                             \
    {                                                                   \
        if(expr){                                                       \
        }else{                                                          \
            report_assertion_failure(#expr, "", __FILE__, __LINE__);    \
            debugBreak();                                               \
        }                                                               \
    } 
#else
#define JASSERT_DEBUG(expr) // Does nothing at all
#endif

#else
#define JASSERT(expr)               // Does nothing at all
#define JASSERT_MSG(expr, message)  // Does nothing at all
#define JASSERT_DEBUG(expr)         // Does nothing at all
#endif
