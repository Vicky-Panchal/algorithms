/*
8. Design a linear time algorithm to decide if a given sequence of numbers is a stack
sequence.
*/

#include <iostream>
using namespace std;

bool compareSequences(int n, int A[], int S[])
{
    int i = 1;
    int j = 0;
    int top = 0;

    while (i <= n)
    {
        S[top++] = i++;
        while (top > 0 && S[top - 1] == A[j])
        {
            top--;
            j++;
        }
    }

    if (top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // Example usage of the compareSequences function
    const int n = 5;
    int A[] = {2, 1, 5, 3, 4};
    int S[n]; // The S array will be filled by the function

    bool result = compareSequences(n, A, S);

    if (result)
    {
        cout << "The sequences are the same." << endl;
    }
    else
    {
        cout << "The sequences are different." << endl;
    }

    return 0;
}
