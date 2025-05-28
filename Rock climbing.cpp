#include <bits/stdc++.h>
using namespace std;

void findingGoal(vector<vector<int>> &mountain, vector<vector<int>> &visited, int i, int j, int n, int m, bool &f, int &level)
{
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] == 1)
        return;
    visited[i][j] = 1;
    if (mountain[i][j] == 3)
    {
        cout << i << " " << j << " " << level << endl;
        f = true;
        return;
    }
    if (j + 1 < m && (mountain[i][j + 1] == 1 || mountain[i][j + 1] == 3) && visited[i][j + 1] == 0)
    {
        findingGoal(mountain, visited, i, j + 1, n, m, f, level);
    }
    if (j - 1 >= 0 && (mountain[i][j - 1] == 1 || mountain[i][j - 1] == 3) && visited[i][j - 1] == 0)
    {
        findingGoal(mountain, visited, i, j - 1, n, m, f, level);
    }

    for (int x = 1; x <= level; x++)
    {
        if (x <= level && i - x >= 0 && (mountain[i - x][j] == 1 || mountain[i - x][j] == 3) && visited[i - x][j] == 0)
        {
            findingGoal(mountain, visited, i - x, j, n, m, f, level);
        }
    }

    for (int x = 1; x <= level; x++)
    {
        if (x <= level && i + x < n && (mountain[i + x][j] == 1 || mountain[i + x][j] == 3) && visited[i + x][j] == 0)
        {
            findingGoal(mountain, visited, i + x, j, n, m, f, level);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mountain(n, vector<int>(m));
    vector<vector<int>> visited(n, vector<int>(m));
    vector<vector<int>> temp(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mountain[i][j];
            temp[i][j] = 0;
        }
    }

    for (int level = 0; level < n; level++)
    {
        visited = temp;
        bool reached = false;
        findingGoal(mountain, visited, n - 1, 0, n, m, reached, level);
        if (reached)
        {
            cout << level << endl;
            return 0;
        }
    }
}