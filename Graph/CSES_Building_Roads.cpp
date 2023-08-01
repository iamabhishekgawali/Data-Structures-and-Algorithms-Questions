
/*

    Problem Name - Building Roads

    Concept - Connected Components in a Graph

*/

#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int n,m;
vector<vector<int>> adj(MAX);
vector<bool> visited(MAX,false);

void dfs(int src){
    visited[src] = true;
    for(auto dest : adj[src]){
        if(visited[dest]==false) dfs(dest);
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        int src,dest;
        cin >> src >> dest;
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    int count = 0;

    vector<int> answer;

    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            count++;
            answer.push_back(i);
            dfs(i);
        }
    }

    cout << count-1 << endl;
    for(int i=1;i<answer.size();i++)
    {
        cout << answer[i-1] << " " << answer[i] << endl;
    }

    return 0;
}