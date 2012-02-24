#include <iostream>
#include "common/Logger.h"
#include "common/TcpServer.h"
#include "common/Config.h"
#include "common/Time.h"
#include "common/Common.h"
#include "game-common/SessionMgr.h"



#include <boost/thread/thread.hpp> 

static TcpServer* server;
static bool run = true;
static const uint32 LOOP_DELAY = 100;


// 基本的逻辑循环
void loop() {
    Connection* conn = NULL;
    SessionMgr sessionMgr;

    while(run == true) {
        uint64 startTime = getTimer();
        conn = server->popConn();
        while(conn) {
            // 创建新会话
            Session* s = new Session(conn);
            sessionMgr.addSession(s);
            conn = server->popConn();
        }
        // 会话更新
        sessionMgr.update();
        // 物件更新
        // 场景更新
        // 活动更新
        //

        // 计算运行时间
        uint64 endTime = getTimer();
        uint64 dtime = endTime - startTime;
        // 保证总的时间差值为 LOOP_DELAY
        if (LOOP_DELAY > dtime) {
            boost::this_thread::sleep(boost::posix_time::milliseconds(LOOP_DELAY - dtime));
        }
    }
}

void catchSignal(int s) {
    sLogger.info("Signal", "捕获信号 %d", s);
    run = false;
    server->stop();
}

void setupSignals() {
    signal(SIGINT, catchSignal);
    signal(SIGTERM, catchSignal);
    signal(SIGABRT, catchSignal);
}

int main(int argc, char* argv[]) {
    // 读取配置文件
    read_info("monika.conf", sConfig);

    uint16 port = sConfig.get("net.port", 6061);
    size_t threadSize = sConfig.get("net.threadSize", 1);


    //sLogger.setLogLevel(LOG_LVL_WARNING);

    // 注册信号处理
    setupSignals();

    // 初始化网络
    server = new TcpServer(port, threadSize);
    // 网络线程
    boost::shared_ptr<boost::thread> NetThread(new boost::thread(boost::bind(&TcpServer::run, server)));
    
    // 初始化逻辑线程
    boost::shared_ptr<boost::thread> LogicThread(new boost::thread(loop));
    // 等待逻辑线程结束
    LogicThread->join();
    
    delete server;

    return 0;
}
