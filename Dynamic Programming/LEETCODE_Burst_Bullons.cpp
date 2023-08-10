

/*

    Pattern : Interval DP (Matrix Chain multiplication)
    Good explanation:  https://leetcode.com/problems/burst-balloons/solutions/892552/for-those-who-are-not-able-to-understand-any-solution-with-diagram/

*/

#include<iostream>
#include<vector>
using namespace std;


class Solution {

    vector<vector<int>> dp;

public:
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return BurstBullons(nums,0,n-1);
    }

    int BurstBullons(vector<int> &nums,int i,int j){

        // Base Case
        if(i>j) return 0;
        if(i==j) return (i-1>=0?nums[i-1]:1)*(nums[i])*(j+1<=nums.size()-1?nums[j+1]:1);
        int ans = INT_MIN;
        if(dp[i][j] != -1) return dp[i][j];

        for(int k=i;k<=j;k++){
            int temp = (i-1>=0?nums[i-1]:1)*(nums[k])*(j+1<=nums.size()-1?nums[j+1]:1);
            temp += BurstBullons(nums,i,k-1);
            temp += BurstBullons(nums,k+1,j);
            ans = max(ans,temp);
        }
        return dp[i][j] = ans;
    }


};

int main(){
    return 0;
}