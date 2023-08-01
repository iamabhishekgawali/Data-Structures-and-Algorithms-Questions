
/*
    Pattern  : Similar to House Robber type
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution
{
    vector<vector<long long int>> dp;

public:
    int change(int sum, vector<int> &coins)
    {
        int N = coins.size();
        dp.resize(N + 1, vector<long long int>(sum + 1, -1));
        return solve(coins, N, sum, 0);
    }

    long long int solve(vector<int> &coins, int N, int sum, int i)
    {

        if (sum == 0)
            return 1;
        if (i == N or sum < 0)
            return 0;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        long long int ways = 0;
        ways += solve(coins, N, sum - coins[i], i);
        ways += solve(coins, N, sum, i + 1);
        return dp[i][sum] = ways;
    }
};

int main()
{
    return 0;
}