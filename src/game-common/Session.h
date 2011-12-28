/**
 * @file Session.h
 * @brief 基本会话类
 * @author Dalton
 * @version 0.1
 * @date 2011-12-26
 */

#ifndef SESSION_3Q6CQNT4

#define SESSION_3Q6CQNT4

#include "common/Connection.h"

class Session {
public:
    Session(Connection* conn) : conn(conn) {

    }
    virtual ~Session();

    bool update();

private:
    Connection* conn;
};



#endif /* end of include guard: SESSION_3Q6CQNT4 */
