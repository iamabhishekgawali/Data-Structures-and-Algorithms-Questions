

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {

    int max_capacity = *max_element(A.begin(),A.end());

    const vector<int> &cost = C;
    const vector<int> &weights = B;

    int dp[weights.size()+1][max_capacity+1];

    for(int i=0;i<=weights.size();i++)
    {
        for(int j=0;j <= max_capacity ;j++){

                if(i == 0) dp[i][j] = INT_MAX;
                if(j == 0 ) dp[i][j] =  0;

                if(i!=0 and j !=0){
                    dp[i][j] = INT_MAX;
                    if(weights[i-1] <= j)
                        dp[i][j] = min(dp[i][j], dp[i][j-weights[i-1]] != INT_MAX ? dp[i][j-weights[i-1]]+cost[i-1] : INT_MAX);
                    dp[i][j] = min(dp[i][j],dp[i-1][j]);
                }
        }
    }

    int sum = 0;

    for(int i = 0 ; i < A.size();i++)
            sum += dp[weights.size()][A[i]];

    return sum;

    // return dp[weights.size()][max_capacity];
}


int main(){

    const vector<int> &A = { 2, 3, 1, 5, 4 };
    const vector<int> &B = { 3, 2, 4, 1 };
    const vector<int> &C = { 1, 2, 5, 10 };

    cout << solve(A,B,C) << endl;

    return 0;
}