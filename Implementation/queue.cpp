#include <iostream>
using namespace std;

template <typename E>
class Queue{
    public:
    int size() const;
    bool empty() const;
    const E& front() const throw(QueueEmpty);
    void enqueue(const E& e);
    void dequeue() const throw(QueueEmpty);



};

class QueueEmpty: public RuntimeException {
    public:
    QueueEmpty(const string& str) : RuntimeException(str){}
};

