
/*

    Problem : Number of longest increasing subsequence


    Method : Longest increasing subsequence pattern
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
       
       int dp[nums.size()];
       int cnt[nums.size()];

       // Initialize dp with 1 
       for(int i=0;i<nums.size();i++) { dp[i] = 1;cnt[i]=1;}    

       // LIS two loops
       int max_answer = 1;
       for(int i=0;i<nums.size();i++)
       {
           for(int j=i-1;j>=0;j--)
           {
               if(nums[i] > nums[j])
                {
                    if(dp[j]+1 == dp[i]) cnt[i] += cnt[j];
                    else if(dp[j]+1 > dp[i]) cnt[i] = cnt[j];
                    dp[i] = max(dp[i],dp[j]+1);
                    max_answer = max(max_answer,dp[i]);
                }
           }
       }

       int total_answer = 0;
       for(int i=0;i<nums.size();i++)
       {
           if(dp[i] == max_answer)
            total_answer += cnt[i];
       }

        return total_answer;
    }
};

int main()
{
    return 0;
}