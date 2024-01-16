#include <iostream>
using namespace std;


template <typename E>
class Node {
    private:
    E ele;
    Node<E>* next;
    friend class LinkedList;
};

template <typename E>
class LinkedList {
    public:
    LinkedList();
    ~LinkedList();
    bool empty() const;
    const E& front() const;
    void addFront( const E& e);
    void removeFront();

    private:
    Node<E> * head;
};

template <typename E>
LinkedList<E>:: LinkedList() {
    head = NULL;
}

template<typename E>
LinkedList<E> :: ~LinkedList() {
    while(!empty())
    {removeFront();}

}

template <typename E>
bool LinkedList<E> :: empty() const {
    return head == NULL;
}

template <typename E>
const E& LinkedList:: front() const {
    return head->ele;
}

template <typename E>
void LinkedList:: addFront(const E& e) {
    Node<E> * v = new Node<E>;
    v->elem = e;
    v->next = head;
    head = v;
}

template <typename E>
void LinkedList<E>::removeFront() {
    Node<E>* old = head;
    head = old->next;
    delete old;

}

int main()
{
    Node<int> Node1(30);
    Node<int> Node2(20);

    LinkedList<int> LL1;
    LL1.addFront(30);


}
    