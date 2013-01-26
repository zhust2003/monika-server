#include <iostream>
#include "common/Config.h"
#include "common/Logger.h"
#include "common/TcpClient.h"
#include "common/ServicePool.h"
#include "common/Time.h"
#include "game-common/Session.h"
#include "game-common/SessionMgr.h"
#include "StatConnection.h"

#include <boost/asio/deadline_timer.hpp>
#include <boost/thread/thread.hpp> 

#define CLIENT_COUNT 1

#define Client TcpClient<StatConnection>

static bool run = true;
static const uint32 LOOP_DELAY = 100;
static const uint32 BLOCK_SIZE = 10000;
static std::deque<Client*> clients;
static ServicePool* pool;


void handleTimeout(const boost::system::error_code& error) {
    sLogger.trace("虚拟客户端停止");
    pool->stop();
    run = false;
}

void catchSignal(int s) {
    sLogger.info("Signal", "捕获信号 %d", s);
    boost::system::error_code ignore;
    handleTimeout(ignore);
}

void setupSignals() {
    signal(SIGINT, catchSignal);
    signal(SIGTERM, catchSignal);
    signal(SIGABRT, catchSignal);
}

void loop() {
    //SessionMgr sessionMgr;

    while(run == true) {
        // 获取开始时间
        uint64 startTime = getTimer();

        // 遍历所有客户端
        for (std::deque<Client*>::iterator i = clients.begin(); i != clients.end();) {
            Client* c = *i;
            // 如果已经连接上了
            if (c->isConnected()) {
                // 发送第一个echo
                Packet p(0);        
                for (uint32 j = 0; j < BLOCK_SIZE; ++j) {
                    p << (uint8)1;
                }
                c->getConn()->send(p);
                //Session* s = new Session(c->getConn());
                //sessionMgr.addSession(s);
                
                //c->setConn(NULL);
                //safeDelete(c);
                //i = clients.erase(i);
                //run = false;                
                ++i;
            } else {
                ++i;
            }
        }

        // 会话更新
        //sessionMgr.update();

        // 计算运行时间
        uint64 endTime = getTimer();
        uint64 dtime = endTime - startTime;

        // 保证总的时间差值为 LOOP_DELAY
        if (LOOP_DELAY > dtime) {
            boost::this_thread::sleep(boost::posix_time::milliseconds(LOOP_DELAY - dtime));
        }
    }
}

int main() {
    pool = new ServicePool(1);
    // 初始化多个客户端
    for (int i = 0; i < CLIENT_COUNT; ++i) {
        Client* c = new Client("127.0.0.1", "6061", pool->getIOService());
        clients.push_back(c);
    }

    // 超时定时器
    //boost::asio::deadline_timer stopTimer(pool->getAcceptService());
    //stopTimer.expires_from_now(boost::posix_time::seconds(10));
    //stopTimer.async_wait(handleTimeout);
    
    // 信号处理
    setupSignals();

    // 网络线程
    boost::shared_ptr<boost::thread> NetThread(new boost::thread(boost::bind(&ServicePool::run, pool)));

    // 初始化逻辑线程
    boost::shared_ptr<boost::thread> LogicThread(new boost::thread(loop));
    // 等待逻辑线程结束
    LogicThread->join();
    NetThread->join();

    for (std::deque<Client*>::iterator i = clients.begin(); i != clients.end(); ++i) {
        Client* c = *i;
        safeDelete(c);
    }
    clients.clear();
    delete pool;
}
