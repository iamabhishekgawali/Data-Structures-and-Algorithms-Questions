
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> dp;

public:
        int coinChange(vector<int> &coins, int sum)
        {
            int N = coins.size();
            dp.resize(N + 1, vector<int>(sum + 1, -1));
            int answer = solve(coins, N, sum, 0);
            return answer != INT_MAX ? answer : -1;
        }

    int solve(vector<int> &coins, int N, int sum, int i)
    {
        if (sum == 0)
            return 0;
        if (i == N or sum < 0)
            return INT_MAX;
        if (dp[i][sum] != -1)
            return dp[i][sum];

        int answer = solve(coins, N, sum - coins[i], i);
        if (answer != INT_MAX)
            answer = answer + 1;

        return dp[i][sum] = min(solve(coins, N, sum, i + 1), answer);
    }
};

int main()
{
    return 0;
}