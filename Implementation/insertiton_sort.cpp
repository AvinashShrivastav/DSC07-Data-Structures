#include <iostream>
using namespace std;

int main()
{
    int a[5] = {3,4,1,2,5};
    for (int i = 1; i <5; i++)
    {
        int j = i-1;
        while(j >= 0 && a[j]> a[j+1]){
            int temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
            j--;
        }
    }

    for(int i = 0; i < 5; i++)
    {
        cout << a[i] <<" ";
    }
}


// 1. Create an array of n elements to be sorted
// 2. For i = 1 to n-1
//     a. Set j = i-1
//     b. While j >= 0 and a[j] > a[j+1]
//         i. Swap a[j] with a[j+1]
//         ii. Decrement j
// 3. End for
// 4. The array is now sorted in ascending order