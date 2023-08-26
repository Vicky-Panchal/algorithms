/*
2. Given a binary string of length n, design a linear time algorithm to compute the
length of the largest dense sub-string of the given string.
*/

#include <iostream>
#include <vector>
using namespace std;

int findLongestDenseSubstring(const vector<int>& A) {
    int n = A.size();
    int c = n;
    int max = 0;
    vector<int> T(2*n+1, -1);

    for (int i = 0; i < n; i++) {
        if (A[i])
            c++;
        else
            c--;

        if (T[c] < 0)
            T[c] = i;

        if (c > n)
            max = i + 1;

        if (T[c - 1] >= 0 && i - T[c - 1] > max)
            max = i - T[c - 1];
    }

    return max;
}

int main() {
    vector<int> A = {1,0,1,0};
    int result = findLongestDenseSubstring(A);

    cout << "Length of the longest dense substring: " << result << endl;

    return 0;
}
