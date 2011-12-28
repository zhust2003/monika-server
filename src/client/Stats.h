#ifndef STATS_JHZ0KXQ5

#define STATS_JHZ0KXQ5

#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>

class Stats {
public:
    Stats() : totalBytesWritten(0),
              totalBytesRead(0),
              mutex()
    {
    }

    void add(size_t w, size_t r) {
        boost::lock_guard<boost::mutex> g(mutex);
        totalBytesWritten += w;
        totalBytesRead += r;
    }

    void print() {
        boost::lock_guard<boost::mutex> g(mutex);
        sLogger.trace("总写入字节数: %d", totalBytesWritten);
        sLogger.trace("总读取字节数: %d", totalBytesRead);
    }

private:
    size_t totalBytesWritten;
    size_t totalBytesRead;
    boost::mutex mutex;
};

#define sStats Singleton<Stats>::instance()

#endif /* end of include guard: STATS_JHZ0KXQ5 */
