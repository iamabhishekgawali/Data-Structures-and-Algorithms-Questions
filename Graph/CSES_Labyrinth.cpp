
/*

    Problem Name - Labyrinth

    Concept - BFS on a Grid with some extra tweaks to find the directions
    Hint - Use BFS given to find shortest path in the matrix

*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> matrix(1001, vector<char>(1001));
vector<vector<bool>> visited(1001, vector<bool>(1001, false));
vector<vector<char>> direction(1001, vector<char>(1001));

bool isValid(int x, int y)
{
    if (x < 0 or y < 0 or x >= n or y >= m or visited[x][y] == true or matrix[x][y] == '#')
        return false;

    return true;
}

// Standard BFS algorithm
void BFS(int i, int j)
{

    vector<int> answer;
    queue<pair<int, int>> Queue;
    Queue.push(make_pair(i, j));
    visited[i][j] = true;
    vector<char> ans;
    while (!Queue.empty())
    {
        int x = Queue.front().first;
        int y = Queue.front().second;
        Queue.pop();
        if (matrix[x][y] == 'B')
        {
            int c = x;
            int b = y;
            int times = 0;
            while (matrix[c][b] != 'A')
            {
                answer.push_back(direction[c][b]);
                if (direction[c][b] == 'D')
                    c--;
                else if (direction[c][b] == 'U')
                    c++;
                else if (direction[c][b] == 'L')
                    b++;
                else if (direction[c][b] == 'R')
                    b--;
            }

            break;
        }

        if (isValid(x, y - 1))
            direction[x][y - 1] = 'L', Queue.push({x, y - 1}), visited[x][y - 1] = true;

        if (isValid(x, y + 1))
            direction[x][y + 1] = 'R', Queue.push({x, y + 1}), visited[x][y + 1] = true;

        if (isValid(x - 1, y))
            direction[x - 1][y] = 'U', Queue.push({x - 1, y}), visited[x - 1][y] = true;

        if (isValid(x + 1, y))
            direction[x + 1][y] = 'D', Queue.push({x + 1, y}), visited[x + 1][y] = true;
    }

    if (answer.size() != 0)
    {
        cout << "YES" << endl;
        cout << answer.size() << endl;
        for (int i = answer.size() - 1; i >= 0; i--)
            cout << (char)answer[i];
        cout << endl;
    }
    else
        cout << "NO" << endl;
}

int main()
{
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;
    int start = -1, end = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'A')
            {
                start = i;
                end = j;
            }
        }

    BFS(start, end);
    return 0;
}