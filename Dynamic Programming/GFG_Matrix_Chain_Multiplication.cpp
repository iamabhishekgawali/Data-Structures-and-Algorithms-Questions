
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    return 0;
}
class Solution
{

    vector<vector<int>> dp;

public:
    int matrixMultiplication(int N, int arr[])
    {
        dp.resize(N + 1, vector<int>(N + 1, -1));
        return solve(arr, 1, N - 1);
    }

    int solve(int arr[], int i, int j)
    {

        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int temp = INT_MAX;

        for (int k = i; k < j; k++)
        {
            temp = min(temp, solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j]);
        }

        return dp[i][j] = temp;
    }
};