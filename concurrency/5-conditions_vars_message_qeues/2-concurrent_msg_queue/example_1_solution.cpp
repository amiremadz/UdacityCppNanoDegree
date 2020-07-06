#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <mutex>
#include <algorithm>
#include <queue>

class Vehicle
{
public:
    Vehicle(int id) : _id(id) {}
    int getID() { return _id; }

private:
    int _id;
};

template <typename T>
class MessageQueue {
public:
    MessageQueue() = default;
    
    void send(T &&message) {
       //std::this_thread::sleep_for(std::chrono::milliseconds(100));
       std::lock_guard<std::mutex> lock(_mtx);
        std::cout << "   Message #" << message << " will be added to the queue" << std::endl;
        _messages.push(std::move(message));
        _cond.notify_one();
    }
    
    T receive() {
        std::unique_lock<std::mutex> lock(_mtx);
        
        /*while (_messages.empty()) {
            _cond.wait(lock);
        }*/
        _cond.wait(lock, [this] { return !_messages.empty(); }); // pass unique lock to condition variable

        T m = std::move(_messages.front());
        _messages.pop();
        return m;
    }
    
private:
    std::queue<T> _messages;
    std::mutex _mtx;
    std::condition_variable _cond;    
};

int main()
{
    // create monitor object as a shared pointer to enable access by multiple threads
    std::shared_ptr<MessageQueue<int>> queue(new MessageQueue<int>());

    std::cout << "Spawning threads..." << std::endl;
    std::vector<std::future<void>> futures;
    for (int i = 0; i < 10; ++i)
    {
        // create a new Vehicle instance and move it into the queue
        int message = i;
        futures.emplace_back(std::async(std::launch::async, &MessageQueue<int>::send, queue, std::move(message)));
    }

    std::cout << "Collecting results..." << std::endl;
    while (true)
    {
        // popBack wakes up when a new element is available in the queue
        int message = queue->receive();
        std::cout << "   Maessage #" << message << " has been removed from the queue" << std::endl;
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
        ftr.wait();
    });

    std::cout << "Finished!" << std::endl;

    return 0;
}
