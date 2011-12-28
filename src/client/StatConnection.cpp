#include "StatConnection.h"


StatConnection::~StatConnection() {
    stats.add(bytesWritten, bytesRead);
    stats.print();
}

void StatConnection::handleRecvHeader(const boost::system::error_code& error, size_t bytesTransferred) {
    bytesRead += bytesTransferred;
    Connection::handleRecvHeader(error, bytesTransferred);
}

void StatConnection::handleRecvBody(const boost::system::error_code& error, size_t bytesTransferred) {
    bytesRead += bytesTransferred;
    Connection::handleRecvBody(error, bytesTransferred);
}

void StatConnection::handleSend(const boost::system::error_code& error, size_t bytesTransferred) {
    bytesWritten += bytesTransferred;
    Connection::handleSend(error, bytesTransferred);
}
