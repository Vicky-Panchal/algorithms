#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> computeB(const vector<int> &A)
{
    int n = A.size();
    vector<int> B(n, -1); // Initialize B with -1
    stack<int> st;        // Stack to store indices of elements in A

    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && A[st.top()] <= A[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            B[i] = st.top();
        }
        st.push(i); // Push current index into the stack
    }

    return B;
}

int main()
{
    // Example usage
    vector<int> A = {5, 4, 7, 9, 3, 1, 2};
    vector<int> B = computeB(A);

    cout << "Array A: ";
    for (int num : A)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Array B: ";
    for (int num : B)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
