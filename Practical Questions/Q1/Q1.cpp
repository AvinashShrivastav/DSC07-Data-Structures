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
    SLL(){
        head = NULL;
        tail = NULL;
    }
    // ~SLL();

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

int main()
{
    SLL A;
    cout<<A.empty();
    A.insertAtBegin(5);
    A.print();
    A.insertAtBegin(51);
    A.print();
    A.insertAtPos(2,3);
    A.print();
    A.removeAtPos(2);
    A.print();
    A.searchElement(51);
    // A.removeFrmBeg();
    // A.removeFrmBeg();
    // A.removeFrmBeg();
    // A.print();
    
    
}
