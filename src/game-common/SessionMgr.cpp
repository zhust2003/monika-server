/**
 * @file SessionMgr.h
 * @brief 会话管理器
 * @author Dalton
 * @version 0.1
 * @date 2011-12-26
 */

#include "SessionMgr.h"

SessionMgr::SessionMgr() {

}

SessionMgr::~SessionMgr() {
    for (std::deque<Session*>::iterator i = sessions.begin(); i != sessions.end(); ++i) {
        safeDelete(*i);
    }
    sessions.clear();
}

void SessionMgr::addSession(Session* s) {
    sessions.push_back(s);
}

void SessionMgr::update() {
    for (std::deque<Session*>::iterator i = sessions.begin(); i != sessions.end();) {
        Session* s = *i;
        // 如果掉线或者出错
        if (! s->update()) {
            // 删除会话
            safeDelete(s);
            i = sessions.erase(i);
        } else {
            ++i;
        }
    }
}
