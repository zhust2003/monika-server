/**
 * @file Logger.h
 * @brief 日志类
 * @author Dalton
 * @version 0.1
 * @date 2011-12-16
 */
 
#ifndef _LOGGER_H
#define _LOGGER_H

#include "Singleton.h"
#include <stdarg.h>
#include <stdio.h>
#include <boost/thread/recursive_mutex.hpp>
#include <boost/thread/locks.hpp>

enum LogLevel {
    LOG_LVL_DEBUG,
    LOG_LVL_INFO,
    LOG_LVL_WARNING,
    LOG_LVL_ERROR,
};

class Logger
{
    public:
        Logger();
        ~Logger();

        // 各种日志级别
        void success(const char* category, const char* format, ...);
        void debug(const char* category, const char* format, ...);
        void info(const char* category, const char* format, ...);
        void warning(const char* category, const char* format, ...);
        void error(const char* category, const char* format, ...);

        // 简易调用
        void trace(const char* format, ...);

        void setLogLevel(LogLevel lv);

        void print(const char* format, ...);

    protected:
        enum Color {
            COLOR_DEFAULT, ///< A default color.
            COLOR_BLACK,   ///< Black color.
            COLOR_RED,     ///< Red color.
            COLOR_GREEN,   ///< Green color.
            COLOR_YELLOW,  ///< Yellow color.
            COLOR_BLUE,    ///< Blue color.
            COLOR_MAGENTA, ///< Magenta color.
            COLOR_CYAN,    ///< Cyan color.
            COLOR_WHITE,   ///< White color.
            COLOR_COUNT    ///< Number of colors.
        };
        void setColor(Color color);
        void printTime();
        void printVa(const char* format, va_list ap);
        void printMsg(Color color, char pfx, const char* category, const char* format, va_list ap);
        void setLogFile();

    private:
        FILE* logFile;
        LogLevel logLevel;
        boost::recursive_mutex mutex;
        static const char* const COLOR_TABLE[COLOR_COUNT];
};

#define sLogger Singleton<Logger>::instance()

#endif /* _LOGGER_H */
