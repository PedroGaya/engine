#pragma once

#include "defines.h"

// Disable assertions by commenting out the below line.
#define JC2D_ASSERTIONS_ENABLED

#ifdef JC2D_ASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

JC2D_API void report_assertion_failure(const char* expression, const char* message, const char* file, int line);

#define JC2D_ASSERT(expr)                                            \
    {                                                                \
        if (expr) {                                                  \
        } else {                                                     \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }

#define JC2D_ASSERT_MSG(expr, message)                                    \
    {                                                                     \
        if (expr) {                                                       \
        } else {                                                          \
            report_assertion_failure(#expr, message, __FILE__, __LINE__); \
            debugBreak();                                                 \
        }                                                                 \
    }

#ifdef _DEBUG
#define JC2D_ASSERT_DEBUG(expr)                                      \
    {                                                                \
        if (expr) {                                                  \
        } else {                                                     \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }
#else
#define JC2D_ASSERT_DEBUG(expr)  // Does nothing at all
#endif

#else
#define JC2D_ASSERT(expr)               // Does nothing at all
#define JC2D_ASSERT_MSG(expr, message)  // Does nothing at all
#define JC2D_ASSERT_DEBUG(expr)         // Does nothing at all
#endif