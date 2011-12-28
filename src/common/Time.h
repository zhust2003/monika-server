/**
 * @file Time.h
 * @brief 时间相关
 * @author Dalton
 * @version 0.1
 * @date 2011-12-26
 */

#ifndef TIME_YF6Z260Z

#define TIME_YF6Z260Z

#include "Common.h"
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::posix_time;

// 获取服务器启动到当前的运行毫秒数
uint64 getTimer();


#endif /* end of include guard: TIME_YF6Z260Z */
