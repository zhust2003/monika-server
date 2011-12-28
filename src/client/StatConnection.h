#ifndef STATCONNECTION_GAOJ9APB

#define STATCONNECTION_GAOJ9APB

#include "common/Connection.h"
#include "Stats.h"

class StatConnection : public Connection {
public:
    StatConnection(io_service& ioService) : Connection(ioService),
                                            bytesWritten(0),
                                            bytesRead(0),
                                            stats()
    {


    }
    ~StatConnection();
    void handleRecvHeader(const boost::system::error_code& error, size_t bytesTransferred);
    void handleRecvBody(const boost::system::error_code& error, size_t bytesTransferred);
    void handleSend(const boost::system::error_code& error, size_t bytesTransferred);

private:
    size_t bytesWritten;
    size_t bytesRead;
    Stats stats;
};



#endif /* end of include guard: STATCONNECTION_GAOJ9APB */
