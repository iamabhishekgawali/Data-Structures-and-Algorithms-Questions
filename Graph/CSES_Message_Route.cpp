/*

    Problem Name - Message Route

    Concept - BFS on a Graph

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(100001);
vector<int> visited(100001, false);
vector<int> parent(100001, -1);
int n, m;

void bfs()
{
    queue<int> Queue;
    Queue.push(1);
    visited[1] = true;
    bool found = false;

    while (!Queue.empty())
    {
        int curr = Queue.front();
        Queue.pop();
        if(curr == n){
            found = true;

            break;
        }

        for(auto dest : adj[curr])
            if(!visited[dest])
            {
                parent[dest] = curr;
                visited[dest] = true;
                Queue.push(dest);
            }
    }

    if(found){

        vector<int> temp;
        int i=n;
        temp.push_back(n);
        while(parent[i]!=-1){
            i = parent[i];
            temp.push_back(i);
        }

        cout << temp.size() << endl;
        for(int i=temp.size()-1;i>=0;i--)
        {
            cout << temp[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }

}

int main()
{
    // freopen("input.txt","r",stdin);
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int src, dest;
        cin >> src >> dest;
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    bfs();
}