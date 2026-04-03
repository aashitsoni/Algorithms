#ifndef MM_LOGGER_H
#define MM_LOGGER_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

inline std::string _mm_now() {
    using namespace std::chrono;
    auto t = system_clock::now();
    std::time_t tt = system_clock::to_time_t(t);
    char buf[32];
    std::strftime(buf, sizeof(buf), "%F %T", std::localtime(&tt));
    return std::string(buf);
}

#define LOG_BASE(level, msg) \
    do { std::cerr << _mm_now() << " [" level "] " << msg << " (" << __FILE__ << ":" << __LINE__ << ")" << std::endl; } while(0)

#define LOG_INFO(msg)  LOG_BASE("INFO",  msg)
#define LOG_WARN(msg)  LOG_BASE("WARN",  msg)
#define LOG_ERROR(msg) LOG_BASE("ERROR", msg)

#ifndef NDEBUG
#define LOG_DEBUG(msg) LOG_BASE("DEBUG", msg)
#else
#define LOG_DEBUG(msg) do {} while(0)
#endif

#endif