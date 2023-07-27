
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> answer;

void calculate(int i, int j, int n, int m, vector<int> temp, vector<vector<int>> &grid)
{
    if (i < 0 or j < 0 or i >= n or j >= m)
        return;

    if (i == n - 1 and j == m - 1)
    {
        temp.push_back(grid[i][j]);
        answer.push_back(temp);
        return;
    }

    // Move Down
    temp.push_back(grid[i][j]);
    calculate(i + 1, j, n, m, temp, grid);
    temp.pop_back();

    // Move Right
    temp.push_back(grid[i][j]);
    calculate(i, j + 1, n, m, temp, grid);
    temp.pop_back();
}

int main()
{
    return 0;
}