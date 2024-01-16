#include<iostream>
using namespace std;

class StringNode {
    private:
    string elem;
    StringNode* next;
    friend class StringLinkedList;
};

class StringLinkedList {
    public:
    StringLinkedList();
    ~StringLinkedList();
    bool empty() const;
    const string& front() const; // return front element
    void addFront(const string& e); 
    void removeFront();
    private:
    StringNode* head;
};

StringLinkedList::StringLinkedList() : head(NULL) {}
StringLinkedList::~StringLinkedList() {
    while(!empty()) removeFront();
}

bool StringLinkedList::empty() const {
    return head == NULL;
}

const string& StringLinkedList::front() const {
    return head->elem;
}


void StringLinkedList::addFront(const string& e) {
    StringNode* v = new StringNode;
    v->elem = e;
    v->next = head;
    head = v;
}

void StringLinkedList::removeFront() {
    StringNode* old = head;
    head = old->next;
    delete old;
}

int main() {
    StringLinkedList* list = new StringLinkedList();
    list->addFront("Hello");
    list->addFront("World");
    cout << list->front() << endl;
    list->removeFront();
    cout << list->front() << endl;
    delete list;
    return 0;
}
