#include <iostream>
using namespace std;

class Node{
    private:
    int ele;
    Node* next;
    friend class SLL;
    public:
    Node(int a)
    {
        ele = a;
        next = NULL;
    }
    
};

class SLL
{
    private:
    Node* head;
    Node* tail;


    public:
    friend class stack;
    SLL(){
        head = NULL;
        tail = NULL;
    }
    ~SLL() {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
}

    bool empty()
    {
        if(head == NULL){
            return true;
        }
        return false;
    }

    
// i)  Insert an element x at the beginning of the singly linked list
    void insertAtBegin(int a)
    {
       Node* newNode = new Node(a);
       if(this->empty())
       {
        this->head = newNode;
        this->tail = newNode;
       }
       else{
        newNode->next = head;
        head = newNode;
       }
    }

    // ii) Insert an element x at ith position in the singly linked list
    void insertAtPos(int pos, int num){
        if (this->size() < pos)
        {
            cout<<"Specified position is out of bound"<<endl;

        }
        else{
            Node* temp = head;
            int posCount = 1;
            while(posCount != pos){
                temp = temp->next;
                posCount++;
            }
            Node* newNode = new Node(num);
            Node* tempNext = temp->next;
            temp->next = newNode;
            newNode->next = tempNext;

        }

    }

    // iii) Remove an element from the beginning of the doubly linked list
    void removeFrmBeg()
    {
        if(head != NULL)
        {
        Node* temp = head;
        head = head->next;
        delete temp;
        }
        else{
            cout<<"SLL is already empty."<<endl;
        }
        
    }



    // iv) Remove an element from ith position in the singly linked list.
    void removeAtPos(int pos){
        if (this->size() < pos)
        {
            cout<<"Specified position is out of bound"<<endl;

        }
        else{
            Node* temp = head;
            int posCount = 1;
            while(posCount != pos){
                temp = temp->next;
                posCount++;
            }
            Node* tempNext = temp->next;
            temp->next = tempNext->next;
            delete tempNext;
        }

    }

    // v)  Search for an element x in the singly linked list and return its pointer
    void searchElement(int a)
    {
        Node* temp = head;
        int pos = -1;
        while (temp != NULL) {
            pos++;
            if ( temp->ele == a)
            {
                cout<<"Element is found at "<<pos<<endl;
            }
            temp = temp->next;
        }
        cout << endl;
    }

   void removeFrmEnd()
    {
        Node* temp = head;
        while( temp->next != tail )
        {
            temp = temp->next;
        }
        Node* todelete = tail;
        tail = temp;
        tail->next = NULL;
        delete todelete;
    }
    void insertAtEnd(int a)
    {
        Node* temp = new Node(a);
        tail->next = temp;
        tail = temp;
        tail->next = NULL;
    }


    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->ele << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int size()
    {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

   
    void addFront(int& E);
    void removeFront();

};

class stack
{
    private:
    SLL stackSLL;
    public:
    void pop()
    {
        removeFrmEnd();

    }
    void push(int a)
    {
        insertAtEnd(a);

    }


};

int main()
{
    stack S;
    S.push(10);
    
}