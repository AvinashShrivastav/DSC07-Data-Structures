#include <iostream>
using namespace std;

class Node{
    private:
    int ele;
    Node* next;
    public:
    Node(int a)
    {
        ele = a;
        next = NULL;
    }
    friend class CLL;
};

class CLL
{
    private:
    Node* cursor;
    public:
    CLL()
    {
        cursor = NULL;
    }
~CLL() {
    if (cursor != NULL) {
        Node* current = cursor;
        do {
            Node* next = current->next;
            delete current;
            current = next;
        } while (current != cursor);
        cursor = NULL;
    }
}
    void insertEle(int x)
    {
        Node* newNode = new Node(x);
        if(cursor == NULL)
        {
            cursor = newNode;
            cursor->next = newNode;
        }
        else{
            newNode->next = cursor->next;
            cursor->next = newNode;
            cursor = cursor->next;
        }

    }

    void removeElem(int num) {
    if (cursor == NULL) {
        cout << "CLL is already empty" << endl;
        return;
    }

    Node* pointer = cursor;
    do {
        if (pointer->next->ele == num) {
            Node* pnode = pointer->next;
            if (pnode == cursor) {
                cursor = pointer; // Update cursor if necessary
            }
            pointer->next = pnode->next;
            delete pnode;
            return;
        }
        pointer = pointer->next;
    } while (pointer != cursor);

    cout << "Element not found" << endl;
}
    Node* searchElement(int num)
    {
        if (cursor == NULL) {
        cout << "CLL is empty" << endl;
        return NULL;
    }

    Node* pointer = cursor;
    do {
        if (pointer->next->ele == num) {
            Node* pnode = pointer->next;
            cout<<"Element "<<pnode->ele<<" found at "<<pnode<<endl;
            return pnode;
        }
        pointer = pointer->next;
    } while (pointer != cursor);

    cout << "Element not found" << endl;

    }




    void print()
    {
        Node* pointer = cursor;
        do {
            cout<<pointer->ele<<" "<<endl;
            pointer = pointer->next;
        }while(pointer != cursor);

    }


};

int main()
{
    CLL A;
    A.insertEle(4);
    A.insertEle(14);
    A.insertEle(114);
    A.insertEle(1194);
    A.insertEle(131);
    A.insertEle(113);
    A.removeElem(113);
    A.print();
    Node* point = A.searchElement(14);
    cout<<point;
}
