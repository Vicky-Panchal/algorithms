/*
4. Given a binary string S of length n, design a linear time algorithm to compute k,
such that the number of 0’s in S[0..k] is equal to number of 1’s in S[k+1..n-1].
*/


#include <iostream>
#include <string>
using namespace std;

int findK(string S) {
    int n = S.length();
    int zeros = 0, ones = 0;

    // Count the number of 1's in the whole string
    for (int i = 0; i < n; ++i) {
        if (S[i] == '0')
            zeros++;
    }

    // Traverse the string from left to right and find the k value
    for (int i = n - 1; i >= 0; i--) {
        if (S[i] == '0')
            zeros--;
        else
            ones++;

        if (zeros == ones)
            return i-1;
    }

    // If no k found, return -1 (indicating no such k exists)
    return -1;
}

int main() {
    string binaryString = "1100101";

    int k = findK(binaryString);

    if (k != -1)
        cout << "The value of k is: " << k << endl;
    else
        cout << "No such k exists." << endl;

    return 0;
}
