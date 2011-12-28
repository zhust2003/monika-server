/**
 * @file Time.cpp
 * @brief 时间管理
 * @author Dalton
 * @version 0.1
 * @date 2011-12-26
 */

#include "Time.h"

// 服务器启动时间
static ptime startTime(microsec_clock::local_time());

uint64 getTimer() {
    ptime nowTime(microsec_clock::local_time());
    time_duration d = nowTime - startTime;
    return d.total_milliseconds();
}
