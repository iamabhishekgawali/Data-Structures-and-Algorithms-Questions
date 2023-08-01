
/*

    Problem Name : Building Teams
    Concept : Bipartite Graph Test

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

queue<int> Queue;
vector<vector<int>> adj(100001);
vector<bool> visited(100001,false);
vector<int> color(100001);

bool dfs(int src, int c)
{

    color[src] = c;
    visited[src] = true;

    for (auto dest : adj[src])
    {
        if (visited[dest] == false)
        {
            if (dfs(dest, c ^ 1) == false)
                return false;
        }
        else if (color[dest] == color[src])
            return false;
    }

    return true;
}

int main()
{

    // freopen("input.txt","r",stdin);

    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int src,dest;
        cin >> src >> dest;

        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    bool Bipartite = true;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false){
            if(dfs(i,1)==false){
                Bipartite = false;
                break;
            }
        }
    }

    if(Bipartite == false)
        cout << "IMPOSSIBLE" << endl;
    else{
        for(int i=1;i<=n;i++)
            {
                int ans = color[i] == 0 ? 2 : 1;
                cout << ans << " ";
            }
    }

    return 0;
}