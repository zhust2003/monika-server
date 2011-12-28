#include "TcpServer.h"
#include "Logger.h"
#include <boost/bind.hpp>

TcpServer::TcpServer(uint16 port, 
                     std::size_t poolSize) : servicePool(poolSize),
                                             signals(servicePool.getAcceptService()),
                                             acceptor(servicePool.getAcceptService()),
                                             conn()
{
    // 设置信号处理
    //signals.add(SIGINT);
    //signals.add(SIGTERM);
    //signals.async_wait(boost::bind(&TcpServer::handleStop, this, placeholders::error, placeholders::signal_number));

    tcp::endpoint endpoint(tcp::v4(), port);
    acceptor.open(endpoint.protocol());

    // 地址重用
    acceptor.set_option(tcp::acceptor::reuse_address(true));

    // XXX 这里是否需要设置非阻塞，查看代码看异步IO是否已经做了

    acceptor.bind(endpoint);
    acceptor.listen();

    sLogger.debug("Net", "TCP服务启动成功 %u", port);

    startAccept();
}

TcpServer::~TcpServer() {
    //stop();
    Connection* conn;
    // FIXME 由于这里的next是不阻塞锁，会不会导致直接返回了，没释放资源
    while (connections.next(conn)) {
        safeDelete(conn);
    }
}

void TcpServer::run() {
    servicePool.run();
}

void TcpServer::handleStop(const boost::system::error_code& e, int s) {
    sLogger.trace("信号 %d 产生:%s", s, e.message().c_str());
    stop();
}

void TcpServer::stop() {
    servicePool.stop();
}

void TcpServer::startAccept() {
    conn.reset(new Connection(servicePool.getIOService()));
    acceptor.async_accept(conn->getSocket(), boost::bind(&TcpServer::handleAccept, this, placeholders::error));
}

void TcpServer::handleAccept(const boost::system::error_code& e) {
    if (!e) {
        // 释放所有权，自己处理资源释放
        conn->start();
        connections.add(conn.get());
        sLogger.debug("Net", "%s 连接进入", conn->getIp().c_str());
        conn.release();
    }
    startAccept();
}
