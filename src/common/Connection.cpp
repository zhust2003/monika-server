#include "Connection.h"
#include "Logger.h"
#include "boost/bind.hpp"

Connection::~Connection() {
    // FIXME 由于这里的next是不阻塞锁，会不会导致直接返回了，没释放资源
    Packet* p;
    while (packets.next(p)) {
        safeDelete(p);
    }

    sLogger.debug("Conn", "%x 连接被回收", this);
}

void Connection::start() {
    tcp::endpoint remoteEp = socket.remote_endpoint();
    address remoteAddress = remoteEp.address();
    ip = remoteAddress.to_string();

    // TCP/IP选项
    // 设置发送缓冲区大小
    socket.set_option(socket_base::send_buffer_size(64 * 1024));
    // 设置接收缓冲区大小
    socket.set_option(socket_base::receive_buffer_size(64 * 1024));
    // 关闭延迟算法
    socket.set_option(tcp::no_delay(true));

    // 开始接收
    startRecv();
}

void Connection::startRecv() {
    //if (closing) return;
    headerBuffer.resize(sizeof(Packet::Header));
    async_read(socket, buffer((char*)headerBuffer.contents(), sizeof(Packet::Header)), boost::bind(&Connection::handleRecvHeader, shared_from_this(), placeholders::error, boost::asio::placeholders::bytes_transferred));

}

void Connection::handleRecvHeader(const boost::system::error_code& error, size_t bytesTransferred) {
    //if (closing) return;
    //sLogger->debug("Net", "%s %d %s %d", ip.c_str(), error.value(), error.message().c_str(), bytesTransferred);
    if (! error) {
        uint16 size, cmd;
        headerBuffer >> size;
        headerBuffer >> cmd;
        cmd = ntohs(cmd);
        size = ntohs(size);
        packet.reset(new Packet(cmd, size));

        // 需要先初始化空间
        packet->resize(size);
        async_read(socket, buffer((char*)packet->contents(), size), boost::bind(&Connection::handleRecvBody, shared_from_this(), placeholders::error, placeholders::bytes_transferred));
    } else if (error > 0 && bytesTransferred == 0) {
        sLogger.debug("Net", "%x %s 连接离开", this, ip.c_str());
        doClose();
    } else if (error < 0) {
        sLogger.debug("Net", "%s 连接离开 %s", ip.c_str(), error.message().c_str());
        doClose();
    }
}

void Connection::handleRecvBody(const boost::system::error_code& error, size_t bytesTransferred) {
    //if (closing) return;
    if (! error) {
        //sLogger.trace("接收到完整的包");
        //packet->hexdump();
        // 不自动释放资源
        packets.add(packet.release());
        startRecv();
    } else if (error > 0 && bytesTransferred == 0) {
        sLogger.debug("Net", "%s 连接离开", ip.c_str());
        doClose();
    } else if (error < 0) {
        sLogger.debug("Net", "%s 连接离开 %s", ip.c_str(), error.message().c_str());
        doClose();
    }
}

void Connection::doSend(const Packet& packet) {
    ByteBuffer b(packet.size() + sizeof(Packet::Header));
    Packet::Header header = { htons(packet.size()), htons(packet.getOpcode()) };
    b.append<Packet::Header>(header);
    b.append((const ByteBuffer&)packet);

   
    //boost::lock_guard<boost::recursive_mutex> g(sendLock);

    //if (closing) return;

    sendQueue.push_back(b);

    if (! sendQueue.empty() && ! sending) {
        startSend();
    }
}

void Connection::startSend() {
//    boost::lock_guard<boost::recursive_mutex> g(sendLock);
//    if (closing) return;
    //std::cout << "发包" << std::endl;
    const ByteBuffer& b = sendQueue.front();
    async_write(socket, buffer(b.contents(), b.size()), boost::bind(&Connection::handleSend, shared_from_this(), placeholders::error, placeholders::bytes_transferred));
    sending = true;
}

void Connection::handleSend(const boost::system::error_code& error, size_t bytesTransferred) {
    if (! error) {
        //boost::lock_guard<boost::recursive_mutex> g(sendLock);
        //if (closing) return;
        sendQueue.pop_front();
        if (! sendQueue.empty()) {
            startSend();
        }
    }
    sending = false;
}

void Connection::doClose() {
    if (closing) return;
    closing = true;
    sLogger.debug("Net", "%x 连接关闭", this);
    boost::system::error_code ignored_ec;
    socket.cancel(ignored_ec);
    socket.shutdown(tcp::socket::shutdown_both, ignored_ec);
    socket.close(ignored_ec);
}