#ifndef SERVICEPOOL_XQFCDOQ5

#define SERVICEPOOL_XQFCDOQ5

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

using namespace boost::asio;

class ServicePool {
public:
    ServicePool(std::size_t size);
    void run();
    void stop();
    io_service& getIOService();
    io_service& getAcceptService();

private:
    typedef boost::shared_ptr<io_service> IOServicePtr;
    typedef boost::shared_ptr<io_service::work> WorkPtr;

    std::vector<IOServicePtr> ioServices;
    std::vector<WorkPtr> works;
    std::size_t nextIOService;
};



#endif /* end of include guard: SERVICEPOOL_XQFCDOQ5 */
