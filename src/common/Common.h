/**
 * @file Common.h
 * @brief 通用常量
 * @author Dalton
 * @version 0.1
 * @date 2011-12-16
 */

#ifndef _DEFINE_H
#define _DEFINE_H

// 标准库
#include <cassert>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// 标准模板库
#include <algorithm>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>


// 基本数据类型
#include <boost/cstdint.hpp>

typedef boost::int64_t int64;
typedef boost::int32_t int32;
typedef boost::int16_t int16;
typedef boost::int8_t int8;
typedef boost::uint64_t uint64;
typedef boost::uint32_t uint32;
typedef boost::uint16_t uint16;
typedef boost::uint8_t uint8;

// 安全删除宏
#   define safeDelete( p )      { if( p != NULL ) { delete p; p = NULL; } }
#   define safeDeleteArray( p ) { if( p != NULL ) { delete[] p; p = NULL; } }
#   define safeFree( p )        { if( p != NULL ) { free( p ); p = NULL; } }

#ifndef M_PI
#  define M_PI          3.14159265358979323846
#endif

#ifndef M_PI_F
#  define M_PI_F        float(M_PI)
#endif

#endif
