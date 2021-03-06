#ifndef CONNECTION_L9I7GOTD

#define CONNECTION_L9I7GOTD

#include "ByteBuffer.h"
#include "Packet.h"
#include "LockedQueue.h"

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace boost::asio;
using namespace boost::asio::ip;


class Connection : public boost::enable_shared_from_this<Connection> {
public:
    explicit Connection(io_service& ioService) : socket(ioService),
                                                 headerBuffer(sizeof(Packet::Header)),
                                                 packet(),
                                                 closing(false)
    {

    }
    virtual ~Connection();

    typedef boost::shared_ptr<Connection> pointer;
    
    static pointer create(boost::asio::io_service& io_service) {
        return pointer(new Connection(io_service));
    }
    tcp::socket& getSocket() {
        return socket;
    }
    void start();

    const std::string& getIp() { return ip; }

    void send(const Packet& packet) {
        socket.get_io_service().post(boost::bind(&Connection::doSend, shared_from_this(), packet));
    }
    void close() {
        socket.get_io_service().post(boost::bind(&Connection::doClose, shared_from_this()));
    }
    bool isClose() const {
        return closing;
    }

    Packet* popPacket() {
        Packet* p = NULL;
        packets.next(p);
        return p;
    }
protected:

    void startRecv();
    virtual void handleRecvHeader(const boost::system::error_code& error, size_t bytesTransferred);
    virtual void handleRecvBody(const boost::system::error_code& error, size_t bytesTransferred);

    void doSend(const Packet& packet);

    void startSend();
    virtual void handleSend(const boost::system::error_code& error, size_t bytesTransferred);


private:
    tcp::socket socket;
    ByteBuffer headerBuffer;
    std::auto_ptr<Packet> packet;
    std::string ip;
    bool closing;

    // 发送消息队列
    std::deque<ByteBuffer> sendQueue;

    // 接收的消息包队列
    LockedQueue<Packet*> packets;

    void doClose();
};


#endif /* end of include guard: CONNECTION_L9I7GOTD */
