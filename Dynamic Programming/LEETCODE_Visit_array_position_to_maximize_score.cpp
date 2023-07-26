
/*
    Pattern  : Similar to House Robber type
*/

#include <iostream>
#include <vector>
using namespace std;

long long maxScore(vector<int> &nums, int x)
{
    long long even = nums[0] % 2 == 0 ? nums[0] : INT_MIN;
    long long odd = nums[0] % 2 == 1 ? nums[0] : INT_MIN;

    long long answer = even + odd;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 1)
        {
            odd = max(odd, max(even + nums[i] - x, odd + nums[i]));
        }
        else
        {
            even = max(even, max(even + nums[i], odd + nums[i] - x));
        }
        answer = max(even, odd);
    }

    return answer;
}

int main()
{
    return 0;
}