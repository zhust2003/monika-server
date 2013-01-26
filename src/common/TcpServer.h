#ifndef TCPSERVER_9H0GC7GA

#define TCPSERVER_9H0GC7GA

#include "Common.h"
#include "Connection.h"
#include "ServicePool.h"
#include "LockedQueue.h"

class TcpServer {
public:

    TcpServer(uint16 port, std::size_t poolSize = 1);
    virtual ~TcpServer();
    void startAccept();
    void handleAccept(Connection::pointer newConn, const boost::system::error_code& e);
    void run();
    void stop();
    void handleStop(const boost::system::error_code& e, int s);
    Connection::pointer popConn() {
        Connection::pointer p;
        connections.next(p);
        return p;
    }

private:
    // 服务池
    ServicePool servicePool;
    // 信号处理器
    signal_set signals;
    // 接收器
    tcp::acceptor acceptor;

    // 连接管理队列
    LockedQueue<Connection::pointer> connections;

    // 新连接
    //typedef std::auto_ptr<Connection> ConnectionPtr;
    //ConnectionPtr conn;
};


#endif /* end of include guard: TCPSERVER_9H0GC7GA */
