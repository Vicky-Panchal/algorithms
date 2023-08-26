/*

   10. Given a array A of numbers , write a linear time algorithm to compute array B, such
that B[i] = j, j is the smallest j > i such that A[j] < A[i].B[i] = n if all the numbers
to the right of A[i] are greater than or equal to A[i].

*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> computeArrayB(const vector<int> &A)
{
    int n = A.size();
    vector<int> B(n, n); // Initialize B with n (as described in the problem)

    stack<int> st; // Stack to hold the indices of potential elements j

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && A[st.top()] >= A[i])
        {
            // Pop elements from the stack if they are greater than or equal to A[i]
            st.pop();
        }

        if (!st.empty())
        {
            // The top of the stack contains the smallest j > i such that A[j] < A[i]
            B[i] = st.top();
        }

        // Push the current index into the stack for potential future comparisons
        st.push(i);
    }

    return B;
}

int main()
{
    int n;
    cout << "Enter the size of the array (n): ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    vector<int> result = computeArrayB(A);

    cout << "Resulting array (B): ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
