#include<iostream>
using namespace std;
void fun(int x)
{
    if(x>0)
    {
        fun(x-1);
        cout<<x;
        fun(x-1);
    }
}
int main()
{
    fun(3);
}