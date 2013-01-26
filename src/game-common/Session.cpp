/**
 * @file Session.cpp
 * @brief 会话类
 * @author Dalton
 * @version 0.1
 * @date 2011-12-26
 */

#include "Session.h"
#include "common/Packet.h"

bool Session::update() {
    // 如果已经掉线
    if (conn->isClose()) {
        return false;
    }

    Packet sendp(0);
    for (uint32 j = 0; j < 100; ++j) {
        sendp << (uint8)1;
    }
    // 派发消息给处理器
    conn->send(sendp);

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
