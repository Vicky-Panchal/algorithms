/*
2. You are given an array of integers.

In one operation, you can decrease the value of any one element by 2.

Compute the minimum number of operations required to make all the elements in the array distinct.

Example 1 : 1, 3, 2, 1 . Ans is 1.

Example 2: 1, 1, 2 ,2 ,2 . Ans is 4

1->-1, 2->0, 2->0->-2.

Input format: First line the number n. Second line n integers.

n<=100000
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    unordered_set<int> ans;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (ans.size() != 0 && ans.count(nums[i]) == 1)
        {
            while (ans.count(nums[i]) == 1)
            {
                count++;
                nums[i] = nums[i] - 2;
            }
        }
        ans.insert(nums[i]);
    }

    cout << count << endl;
}
