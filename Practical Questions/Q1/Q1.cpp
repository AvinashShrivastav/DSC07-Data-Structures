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
    public:
    Node* head;
    Node* tail;


    public:
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

    // iii) Remove an element from the beginning of the singly linked list
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
    // public:
    // Node*s = head->next;
    // void fun2(Node*s = s)
    // {
    //     if (s == NULL)
    //     {
    //         return;
    //     }
    //     cout<<s->ele;

    //     if ( s->next !=NULL)
    //     {
    //         fun2(s->next->next)
    //     }
    //     cout<<s->ele;
    // }

    void displayReverse()
    {
        if (head->next == NULL)
        {
            return;
        }
        else {
            head = head->next;
            displayReverse();
            cout<<head->ele<<" "; 
        }
        

    }


    
};

void printReverse(Node* head)
{   if(head == NULL)
    return;
    else{
        printReverse(head->next);
        cout<<head->ele<<" ";
    }

}
void deleteith(int i)
{
    if (i < 0)
    {
        return;
    }
    Node* curent = head;
    int posCount = 0;
    while(posCount != i && current != NULL)
    { 
        current = current->next;
        posCount++;

    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;

}


void fun2(Node* s)
{
    if(s == NULL)
    return;
    cout<<s->data;
    if(s->next!=NULL)
    fun2(s->next->next);
cout<<s->data;

}

int main()
{
    SLL A;
    A.insertAtBegin(1);
    A.insertAtEnd(2);
    A.insertAtEnd(3);
    A.insertAtEnd(4);
    A.insertAtEnd(5);
    A.insertAtEnd(6);
    A.print();
    A.displayReverse();

    // cout<<A.empty();
    // A.insertAtBegin(5);
    // A.print();
    // A.insertAtBegin(51);
    // A.print();
    // A.insertAtPos(2,3);
    // A.print();
    // A.removeAtPos(2);
    // A.print();
    // A.removeFrmEnd();
    // A.print();
    // A.insertAtEnd(5);
    // A.print();
    // A.searchElement(51);
    // A.removeFrmBeg();
    // A.removeFrmBeg();
    // A.removeFrmBeg();
    // A.print();

    
    
}



void traverse(node* p)
{
    // create an empty stack
    stack<node*> s;
    // push the root node into the stack
    s.push(p);
    // while the stack is not empty
    while(!s.empty())
    {
        if(curr->right != NULL)
        {
            s.push(curr->right);
        }
        // if the node has a left child, push it into the stack
        if(curr->left != NULL)
        {
            s.push(curr->left);
        }
        // pop the top node from the stack
        node* curr = s.top();
        s.pop();
        // visit the node by printing its data or performing some other operation
        visit(curr);
        // if the node has a right child, push it into the stack
        
    }
}

void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left) {
            s1.push(current->left);
        }

        if (current->right) {
            s1.push(current->right);
        }
    }

    while (!s2.empty()) {
        Node* current = s2.top();
        s2.pop();
        cout << current->data << " ";
    }
}
