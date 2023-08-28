/*
1. Given a number n and k. Remove k digits from n , such that you are left with the maximum possible number.

0<n<10^18

Example : 503016 and 3, the answer is 536.

503016 and 5 the answer is 6

503016 and 6 answer is 0.
*/

#include <bits/stdc++.h>
using namespace std;

long removek(long n, int k)
{
    if (n % 10 == 0 && k == 1)
        return 0;
    stack<int> temp1;
    while (n)
    {
        temp1.push(n % 10);
        n = n / 10;
    }
    stack<int> temp2;
    temp2.push(temp1.top());
    temp1.pop();
    while (!temp1.empty())
    {
        int temp = temp1.top();
        temp1.pop();
        while (k && temp > temp2.top())
        {
            temp2.pop();
            k--;
            if (temp2.empty())
                break;
        }
        temp2.push(temp);
    }
    while (k)
    {
        temp2.pop();
        k--;
    }
    long result = 0;
    int count = 0;
    while (!temp2.empty())
    {
        result = temp2.top() * pow(10, count) + result;
        temp2.pop();
        count++;
    }
    return result;
}

int main()
{
    long n;
    cin >> n;
    int k;
    cin >> k;
    cout << removek(n, k);
}