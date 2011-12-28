/**
 * @file SessionMgr.h
 * @brief 会话管理器
 * @author Dalton
 * @version 0.1
 * @date 2011-12-26
 */

#ifndef SESSIONMGR_DNNF7YI1

#define SESSIONMGR_DNNF7YI1

#include "Session.h"

class SessionMgr {
public:
    SessionMgr();
    ~SessionMgr();

    void addSession(Session* s);
    void update();

private:
    std::deque<Session*> sessions;
};



#endif /* end of include guard: SESSIONMGR_DNNF7YI1 */
