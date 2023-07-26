

/*

    Problem Name - Counting Towers 

    Concept Used - Connected Components in a Grid

*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> matrix(1001,vector<char>(1001));
vector<vector<bool>> visited(1001,vector<bool>(1001,false));


// Check whether given cell is valid to perform DFS
bool isValid(int i,int j,int n,int m)
{
    if(i<0 or j<0 or i>=n or j>=m or visited[i][j] == true or matrix[i][j] == '#')  return false;
    return true;
}

// DFS function to traverse matrix in Up Down Right Left 
void DoDFS(int i,int j,int n,int m)
{
    visited[i][j] = true;

    if(isValid(i+1,j,n,m))
        DoDFS(i+1,j,n,m);

    if(isValid(i-1,j,n,m))    
        DoDFS(i-1,j,n,m);

    if(isValid(i,j+1,n,m))
        DoDFS(i,j+1,n,m);

    if(isValid(i,j-1,n,m))
        DoDFS(i,j-1,n,m);
}

// Parent DFS function to call DFS function
int DFS(int n,int m)
{
    int count = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j] == false and matrix[i][j] == '.')
            {
                count = count + 1;
                DoDFS(i,j,n,m);
            }
        }
    }

    return count;
}

int main()
{
    // freopen("input", "r", stdin);

    int n,m;
    cin >> n >> m;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin  >> matrix[i][j];
        }

    cout << DFS(n,m) << endl;

    return 0;
}