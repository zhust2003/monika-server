#ifndef LOCKEDQUEUE_6YB8VSPT
#define LOCKEDQUEUE_6YB8VSPT

#include <boost/thread/recursive_mutex.hpp>
#include <boost/thread/locks.hpp>

template <class T, typename StorageType=std::deque<T>, class LockType=boost::recursive_mutex >
class LockedQueue
{
    LockType _lock;

    StorageType _queue;

    public:

        //! Create a LockedQueue.
        LockedQueue()
        {
        }

        //! Destroy a LockedQueue.
        virtual ~LockedQueue()
        {
        }

        //! Adds an item to the queue.
        void add(const T& item)
        {
            boost::lock_guard<LockType> g(this->_lock);
            _queue.push_back(item);
        }

        //! Gets the next result in the queue, if any.
        bool next(T& result)
        {
            boost::unique_lock<LockType> g(this->_lock, boost::try_to_lock_t());
            if (! g.owns_lock()) {
                return false;
            }

            if (_queue.empty())
                return false;

            result = _queue.front();
            _queue.pop_front();

            return true;
        }

        template<class Checker>
        bool next(T& result, Checker& check)
        {
            boost::unique_lock<LockType> g(this->_lock, boost::try_to_lock_t());
            if (! g.owns_lock()) {
                return false;
            }

            if (_queue.empty())
                return false;

            result = _queue.front();
            if(! check.process(result))
                return false;

            _queue.pop_front();
            return true;
        }

        
        ///! Checks if we're empty or not with locks held
        bool empty()
        {
            boost::lock_guard<LockType> g(this->_lock);
            return _queue.empty();
        }
};


#endif /* end of include guard: LOCKEDQUEUE_6YB8VSPT */
