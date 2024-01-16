#include <iostream>
using namespace std;

template <typename T>
class Node {
private:
    T elem;
    Node<T>* next;
    template <typename U> friend class LinkedList;
};

template <typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    bool empty() const;
    const T& front() const;
    void addFront(const T& e);
    void removeFront();
private:
    Node<T>* head;
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    while (!empty()) removeFront();
}

template <typename T>
bool LinkedList<T>::empty() const {
    return head == nullptr;
}

template <typename T>
const T& LinkedList<T>::front() const {
    return head->elem;
}

template <typename T>
void LinkedList<T>::addFront(const T& e) {
    Node<T>* v = new Node<T>;
    v->elem = e;
    v->next = head;
    head = v;
}

template <typename T>
void LinkedList<T>::removeFront() {
    Node<T>* old = head;
    head = old->next;
    delete old;
}

int main() {
    LinkedList<string> stringList;
    stringList.addFront("Hello");
    stringList.addFront("World");
    cout << stringList.front() << endl;
    stringList.removeFront();
    cout << stringList.front() << endl;

    LinkedList<int> intList;
    intList.addFront(42);
    intList.addFront(23);
    cout << intList.front() << endl;
    intList.removeFront();
    cout << intList.front() << endl;

    return 0;
}

