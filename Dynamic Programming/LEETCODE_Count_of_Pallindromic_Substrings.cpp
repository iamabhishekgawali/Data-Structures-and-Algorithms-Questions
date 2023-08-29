
/*
    Pattern : Interval DP (Matrix Chain Multiplication)
*/

#include<iostream>
#include<vector>
using namespace std;

void CountAllPallindromes(string s)
    {
        vector<vector<bool>> IsPallindrome(s.size(),vector<bool>(s.size()+1,-1));

        for(int gap = 0,limit = s.size(); gap < s.size();gap++,limit--){
            for(int j=0;j<limit;j++){
                
                int c = j;
                int k = gap + j;
                if(c == k) IsPallindrome[c][k] = true;
                else{
                    IsPallindrome[c][k] = IsPallindrome[c+1][k-1] && s[c] == s[k];
                }
                
            }
        }

        // Count here by looping
    }

int main(){
    return 0;
}