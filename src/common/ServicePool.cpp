#include "ServicePool.h"
#include "Logger.h"
#include <boost/thread/thread.hpp>

ServicePool::ServicePool(std::size_t size) : nextIOService(1) {
    if (size <= 0) size = 1;
    size++;
    
    // 增加work，否则ioservice会退出
    for (std::size_t i = 0; i < size; ++i) {
        IOServicePtr ioService(new io_service);
        WorkPtr work(new io_service::work(*ioService));
        ioServices.push_back(ioService);
        works.push_back(work);
    }
}

void ServicePool::run() {
    // 创建一个线程池
    // 一个线程 <-> 一个io_service 故不需要做线程同步
    std::vector<boost::shared_ptr<boost::thread> > threads;

    // 初始化所有线程
    for (std::size_t i = 0; i < ioServices.size(); ++i) {
        boost::shared_ptr<boost::thread> thread(new boost::thread(boost::bind(&io_service::run, ioServices[i])));
        threads.push_back(thread);
    }

    // 等待所有线程退出
    for (std::size_t i = 0; i < threads.size(); ++i) {
        std::ostringstream os;
        os << threads[i]->get_id();
        threads[i]->join();
        sLogger.debug("Net", "网络从线程 %d [%s] 退出", i, os.str().c_str());
    }
}

void ServicePool::stop() {
    // 明确的关闭所有服务
    for (std::size_t i = 0; i < ioServices.size(); ++i) {
        ioServices[i]->stop();
    }
}

io_service& ServicePool::getIOService() {
    // 循环读取可用IO服务，从第二个服务开始，第一个服务默认给accept用
    io_service& ioService = *ioServices[nextIOService];
    ++nextIOService;
    if (nextIOService == ioServices.size()) {
        nextIOService = 1;
    }
    return ioService;
}

io_service& ServicePool::getAcceptService() {
    return *ioServices[0];
}
