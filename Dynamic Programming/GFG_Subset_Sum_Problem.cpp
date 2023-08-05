
// Pattern : Knapsack - Dp on subsequences

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    vector<vector<int>> dp;

public:
    int solve(vector<int> &arr, int sum, int i)
    {
        if (sum == 0)
            return 1;
        if (i == arr.size() or sum < 0)
            return 0;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        return dp[i][sum] = solve(arr, sum - arr[i], i + 1) || solve(arr, sum, i + 1);
    }

    bool isSubsetSum(vector<int> arr, int sum)
    {
        dp.resize(arr.size() + 1, vector<int>(sum + 1, -1));
        return solve(arr, sum, 0);
    }
};

int main()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    Solution S;
    cout << S.isSubsetSum(arr, sum) << endl;

    return 0;
}