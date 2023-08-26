#include <iostream>
#include <vector>
#include <stack>

std::vector<int> computeB(const std::vector<int> &A)
{
    int n = A.size();
    std::vector<int> B(n, -1); // Initialize B with -1
    std::stack<int> st;        // Stack to store indices of elements in A

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
    std::vector<int> A = {5, 4, 7, 9, 3, 1, 2};
    std::vector<int> B = computeB(A);

    std::cout << "Array A: ";
    for (int num : A)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Array B: ";
    for (int num : B)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
