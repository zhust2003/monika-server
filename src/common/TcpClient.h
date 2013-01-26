/**
 * @file TcpClient.h
 * @brief TCP客户端
 * @author Dalton
 * @version 0.1
 * @date 2011-12-19
 */

#ifndef TCPCLIENT_Z2L89R0I

#define TCPCLIENT_Z2L89R0I

#include "Common.h"

#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

using namespace boost::asio;
using namespace boost::asio::ip;

template<class T>
class TcpClient {
public:
    TcpClient(const std::string& address, const std::string& port, io_service& service) : ioService(service),
                                                                                          connected(false)
    {
        tcp::resolver resolver(ioService);
        tcp::resolver::query query(address, port);
        tcp::resolver::iterator endpoint = resolver.resolve(query);


        startConnect(endpoint);
    }
    ~TcpClient() {
        sLogger.trace("清理客户端");
    }

    void startConnect(const tcp::resolver::iterator& endpoint) {
        conn = T::create(ioService);
        async_connect(conn->getSocket(), endpoint, boost::bind(&TcpClient::handleConnect, this, placeholders::error)); 
    }

    void handleConnect(const boost::system::error_code& error) {
        if (! error) {
            connected = true;
            sLogger.debug("Net", "连接成功");
            conn->start();
        } else {
            sLogger.debug("Net", "连接失败");
            conn.reset();
        }
    }


    T* getConn() const {
        return conn.get();
    }

    bool isConnected() {
        return connected;
    }

private:
    io_service& ioService;
    typename T::pointer conn;
    bool connected;
};

#endif /* end of include guard: TCPCLIENT_Z2L89R0I */
