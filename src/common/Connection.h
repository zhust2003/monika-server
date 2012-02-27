#ifndef CONNECTION_L9I7GOTD

#define CONNECTION_L9I7GOTD

#include "ByteBuffer.h"
#include "Packet.h"
#include "LockedQueue.h"

#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

using namespace boost::asio;
using namespace boost::asio::ip;


class Connection {
public:
    explicit Connection(io_service& ioService) : socket(ioService),
                                                 headerBuffer(sizeof(Packet::Header)),
                                                 packet(),
                                                 closing(false),
                                                 sending(false)
    {

    }
    virtual ~Connection();
    tcp::socket& getSocket() {
        return socket;
    }
    void start();
    void startRecv();
    virtual void handleRecvHeader(const boost::system::error_code& error, size_t bytesTransferred);
    virtual void handleRecvBody(const boost::system::error_code& error, size_t bytesTransferred);

    void send(const Packet& packet);
    void startSend();
    virtual void handleSend(const boost::system::error_code& error, size_t bytesTransferred);
    const std::string& getIp() { return ip; }

    void close();
    bool isClose() const {
        return closing;
    }

    Packet* popPacket() {
        Packet* p = NULL;
        packets.next(p);
        return p;
    }

private:
    tcp::socket socket;
    ByteBuffer headerBuffer;
    std::auto_ptr<Packet> packet;
    std::string ip;
    bool closing;

    // 发送消息队列
    std::deque<ByteBuffer> sendQueue;
    boost::recursive_mutex sendLock;
    // 异步写入是否完成
    bool sending;

    // 接收的消息包队列
    LockedQueue<Packet*> packets;
};


#endif /* end of include guard: CONNECTION_L9I7GOTD */
