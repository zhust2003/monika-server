/**
 * @file Logger.h
 * @brief 日志类
 * @author Dalton
 * @version 0.1
 * @date 2011-12-16
 */

#include "Logger.h"
#include "Common.h"
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::posix_time;

const char* const Logger::COLOR_TABLE[COLOR_COUNT] = {
    "\033[" "00"    "m",    // COLOR_DEFAULT
    "\033[" "30;22" "m",    // COLOR_BLACK
    "\033[" "31;22" "m",    // COLOR_RED
    "\033[" "32;22" "m",    // COLOR_GREEN
    "\033[" "33;01" "m",    // COLOR_YELLOW
    "\033[" "34;01" "m",    // COLOR_BLUE
    "\033[" "35;22" "m",    // COLOR_MAGENTA
    "\033[" "36;01" "m",    // COLOR_CYAN
    "\033[" "37;01" "m"     // COLOR_WHITE
};

Logger::Logger() : logFile(NULL),
                   logLevel(LOG_LVL_DEBUG) {
    setLogFile();
    debug("Log", "日志系统初始化");
}

Logger::~Logger() {
    debug("Log", "日志系统关闭");

    if (NULL != logFile) {
        fclose(logFile);
        logFile = NULL;
    }
}

void Logger::setLogLevel(LogLevel lv) {
    if (lv < LOG_LVL_DEBUG) {
        lv = LOG_LVL_DEBUG;
    } else if (lv > LOG_LVL_ERROR) {
        lv = LOG_LVL_ERROR;
    }
    logLevel = lv;

    debug("Log", "日志级别被设置为 %d\n", lv);
}

void Logger::trace(const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    printMsg(COLOR_BLUE, 'T', "Trace", format, ap);
    va_end(ap);
}

void Logger::success(const char* category, const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    printMsg(COLOR_GREEN, 'S', category, format, ap);
    va_end(ap);
}

void Logger::debug(const char* category, const char* format, ...) {
    if (logLevel > LOG_LVL_DEBUG) return;
    va_list ap;
    va_start(ap, format);
    printMsg(COLOR_CYAN, 'D', category, format, ap);
    va_end(ap);
}

void Logger::info(const char* category, const char* format, ...) {
    if (logLevel > LOG_LVL_INFO) return;
    va_list ap;
    va_start(ap, format);
    printMsg(COLOR_DEFAULT, 'L', category, format, ap);
    va_end(ap);
}

void Logger::warning(const char* category, const char* format, ...) {
    if (logLevel > LOG_LVL_WARNING) return;
    va_list ap;
    va_start(ap, format);
    printMsg(COLOR_YELLOW, 'W', category, format, ap);
    va_end(ap);
}

void Logger::error(const char* category, const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    printMsg(COLOR_RED, 'E', category, format, ap);
    va_end(ap);
}

void Logger::setLogFile() {
    //boost::lock_guard<boost::recursive_mutex> g(mutex);
    time_t t = time(NULL);
    tm* tm = localtime(&t);

    char fileName[PATH_MAX + 1];
    snprintf(fileName, PATH_MAX + 1, "logs/%02u.%02u.%04u.log", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);

    FILE* file = NULL;
    file = fopen(fileName, "a");
    // 打开失败
    if (NULL == file) {
        warning("Log", "无法打开日志文件 %s: %s", fileName, strerror(errno));
        return;
    }
    logFile = file;
    debug("Log", "打开日志文件 %s 成功", fileName);
}

void Logger::setColor(Color color) {
    fputs(COLOR_TABLE[color], stdout);
}

void Logger::printTime() {
    //time_t t = time(NULL);
    //tm* tm = localtime(&t);
    ptime nowTime(microsec_clock::local_time());
    std::string time = to_simple_string(nowTime);
    //time_duration d(nowTime.time_of_day());
    print("%s", time.c_str());
}

void Logger::print(const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    printVa(format, ap);
    va_end(ap);
}

void Logger::printVa(const char* format, va_list ap) {
    //boost::lock_guard<boost::recursive_mutex> g(mutex);
    if (NULL != logFile) {
        va_list ap2;
        va_copy(ap2, ap);
        vfprintf(logFile, format, ap2);
        fflush(logFile);
        va_end(ap2);
    }
    vprintf(format, ap);
}

void Logger::printMsg(Color color, char pfx, const char* category, const char* format, va_list ap) {
    //boost::lock_guard<boost::recursive_mutex> g(mutex);
    printTime();
    setColor(color);
    print(" %c", pfx);
    if (category && *category) {
        setColor(COLOR_WHITE);
        print(" %s ", category);
        setColor(color);
    }
    printVa(format, ap);
    print("\n");

    setColor(COLOR_DEFAULT);
    fflush(stdout);
}
