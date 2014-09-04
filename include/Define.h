// ***********************************************************************
// Filename         : Define.h
// Author           : LIZHENG
// Created          : 2014-07-01
// Description      :
//
// Last Modified By : LIZHENG
// Last Modified On : 2014-07-01
//
// Copyright (c) lizhenghn@gmail.com. All rights reserved.
// ***********************************************************************
#ifndef ZL_STDDEFINE_H
#define ZL_STDDEFINE_H
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include "OsDefine.h"

#define NAMESPACE_ZL_START namespace ZL {
#define NAMESPACE_ZL_END   }  /* namespace ZL */

#ifdef OS_WINDOWS
#define ZL_SNPRINTF  _snprintf
#else
#define ZL_SNPRINTF  snprintf
#endif

#define Safe_Delete(p)        do { delete p; p = NULL; } while (0)
#define Safe_Delete_Array(p)  do { delete[] p; p = NULL; } while (0)


// Run-time assertion
// #define ZL_NDEBUG
#ifdef  ZL_NDEBUG
#define ZL_ASSERT(expr) ((void) 0)
#define ZL_ASSERTEX(expr, file, lineno, func) ((void) 0)
#else
#define ZL_ASSERT(expr)                                    \
			((void) ((expr) ? 0 :                          \
		    printf("%s:%d: %s:  Assertion `%s' failed.\n", \
			__FILE__, __LINE__, __FUNCTION__, #expr)))
#define ZL_ASSERTEX(expr, file, lineno, func)              \
	        ((void) ((expr) ? 0 :                          \
		    printf("%s:%d: %s: Assertion `%s' failed. "    \
		    "(called from %s:%d:%s)\n",                    \
		     __FILE__, __LINE__, __FUNCTION__, #expr,      \
            file, lineno, func)))
#endif

// Compile-time assertion 
#define ZL_STATIC_ASSERT(expr) ZL_STATIC_ASSERT_IMPL(expr, __FILE__, __LINE__)
#define ZL_STATIC_ASSERT_IMPL(expr, file, line) typedef char static_assert_fail_on_##file_and_##line[2*((expr)!=0)-1]


#endif /* ZL_STDDEFINE_H */