/**
 * @file Session.cpp
 * @brief 会话类
 * @author Dalton
 * @version 0.1
 * @date 2011-12-26
 */

#include "Session.h"
#include "common/Packet.h"

Session::~Session() {
    safeDelete(conn);
}

bool Session::update() {
    // 如果已经掉线
    if (conn->isClose()) {
        return false;
    }

    Packet* p = conn->popPacket();
    while (p) {
        std::auto_ptr<Packet> packet(p);
        Packet sPacket(*p);
        // 派发消息给处理器
        conn->send(sPacket);
        p = conn->popPacket();
    }
    return true;
}
