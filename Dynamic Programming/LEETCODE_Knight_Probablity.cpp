
/*

    Problem : Knight Probability in Chessboard
    Method : DP on grid type
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {

    int dir[8][8] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    unordered_map<string,double> mp;

public:
    double knightProbability(int n, int k, int row, int column) {
        return solve(n,k,row,column);
    }

    double solve(int n,int k,int row,int column){
        if(row >= n or column >= n or row < 0 or column < 0) return 0;
        if(k==0) return 1;

        string key = to_string(row)+"sher"+to_string(column)+"lock"+to_string(k);
        if(mp.find(key) != mp.end()) return mp[key];

        double prb = 0;

        for(int i=0;i<8;i++)
            prb += solve(n,k-1,row+dir[i][0],column+dir[i][1])/8.0;

        mp[key] = prb;
        return prb;
    }
};

int main()
{
    return 0;
}