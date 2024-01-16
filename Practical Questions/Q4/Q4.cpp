#include <iostream>
using namespace std;

class stack
{
    private:
    int* Array;
    int capacity;
    int t;

    public:
    stack(int cap)
    {
        Array = new int[cap];
        capacity = cap;
        t = -1;

    }

    int size()
    {
        return t+1;
    }

    bool empty()
    {
        if(t<0)
        {
            return true;
        }
        else{
            return false;
        }
    }

    int& top()
    {
        if(!this->empty())
        {
            return(Array[t]);
        }
        cout<<"Empty stack"<<endl;
        
    }
    void push(int num)
    {
        if (size() == capacity)
        {
            cout<<"Full stack"<<endl;
        }
        else{
            Array[++t] = num;
        }
        
    }
    void pop()
    {
        if(this->empty())
        {
            cout<<"Empty stack"<<endl;
        }
        else{
            --t;
        }
    }
    void print(){
        for(int i = 0; i <=t; i++)
        {
            cout<<Array[i]<<" ";
        }
        cout<<endl;
    }


    int evaluatePostfix(string exp) {
        for (int i = 0; i < exp.length(); i++) {
            if (isdigit(exp[i]))
                push(exp[i] - '0');
            else {
                int val1 = top();
                pop();
                int val2 = top();
                pop();
                switch (exp[i]) {
                    case '+': push(val2 + val1); break;
                    case '-': push(val2 - val1); break;
                    case '*': push(val2 * val1); break;
                    case '/': push(val2 / val1); break;
                }
            }
        }
        return top();
    }

    int evaluatePrefix(string exp) {
    for (int i = exp.length() - 1; i >= 0; i--) {
        if (isdigit(exp[i]))
            push(exp[i] - '0');
        else {
             int val1 = top();
            pop();
                int val2 = top();
                pop();
            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return top();
}


};
void deleteStackElements(stack s) {
    if(s.empty()) {
        return;
    } else {
        s.pop();
        deleteStackElements(s);
    }
}

int main()
{
    stack A(10);
    A.print();
    cout<<A.top()<<endl;
    cout<<A.empty()<<endl;
    A.push(5);
    A.push(6);
    A.print();
    cout<<A.top()<<endl;
    A.pop();
    cout<<A.top()<<endl;
    A.print();
    deleteStackElements(A);
    
    A.print();
    // stack B(100);
    // cout << B.evaluatePostfix("56+") << endl;
    // stack C(100);
    // cout << C.evaluatePrefix("+78") << endl;

}