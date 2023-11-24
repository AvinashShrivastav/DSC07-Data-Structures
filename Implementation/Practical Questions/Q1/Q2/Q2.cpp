#include <iostream>
using namespace std;

class Node
{
    private:
    int ele;
    Node* prev;
    Node* next;

    public:
    Node(int num)
    {
        ele = num;
        prev = NULL;
        next = NULL;
    }
    friend class DLL;


};


class DLL{
    private:
    Node* header = new Node(NULL);
    Node* trailer = new Node(NULL);

    public:
    DLL()
    {
        header->next = NULL;
        trailer->prev = NULL;
    
    }
    ~DLL()
    {

    }
    void insertAtBeg(int num)
    {
        Node * newNode = new Node(num);
        if(header->next == NULL)
        {
            header->next = newNode;
            trailer->prev = newNode;
            cout<<"DLL initiated"<<endl;
        }
        else{
            Node* temp = this->header;
            this->header = newNode;
            newNode->next = temp;
            cout<<"Element inserted at beginning"<<endl;
        }

    }

    void insertAtEnd(int num)
    {
        Node * newNode = new Node(num);
        if(trailer->prev == NULL)
        {
            header->next = newNode;
            trailer->prev = newNode;
            cout<<"DLL initiated"<<endl;
        }
        else{
            Node* pnode = trailer->prev;
            pnode->next = newNode;
            newNode->prev = pnode;
            newNode->next = trailer;
            trailer->prev = newNode;
            cout<<"Element inserted at the end"<<endl;
        }



    }

    void removeFrmBeg()
    {
        if(header->next == NULL)
        {
            cout<<"DLL is empty"<<endl;
        }
        else{
            Node* frontNode = header->next;
            header->next = frontNode->next;
            delete frontNode;
            cout<<"Elment removed from front node"<<endl;

        }
        

    }

    void removeFrmEnd()
    {
        if(header->next == NULL)
        {
            cout<<"DLL is empty"<<endl;
        }
        else{
            Node* lastNode = trailer->prev;
            Node* last2ndNode = lastNode->prev;
            last2ndNode->next = trailer;
            trailer->prev = last2ndNode;
            delete lastNode;
            cout<<"Element removed from end"<<endl;

        }
        

    }

    void print() {
        Node* temp = header->next;
        while (temp->next != NULL) {
            cout << temp->ele << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    DLL A;
    A.insertAtBeg(77);
    A.insertAtEnd(67);
    A.print();
    A.removeFrmEnd();
    A.removeFrmEnd();
    A.print();
}
