#include <bits/stdc++.h>
using namespace std;

void countPipes(vector<vector<int>> &pipes, int n, int m, int x, int y, map<pair<int, int>, bool> &visited, int &numPipes, int len)
{
    if (x < 0 || x >= n || y < 0 || y >= m || pipes[x][y] == 0 || len == 0)
    {
        return;
    }
    visited[{x, y}] = true;
    len--;

    if (pipes[x][y] == 1)
    {
        if (y + 1 < m)
        {
            int checkNext = pipes[x][y + 1];
            if (checkNext == 1 || checkNext == 3 || checkNext == 6 || checkNext == 7)
            {
                countPipes(pipes, n, m, x, y + 1, visited, numPipes, len);
            }
        }

        if (y - 1 >= 0)
        {
            int checkNext = pipes[x][y - 1];
            if (checkNext == 1 || checkNext == 3 || checkNext == 4 || checkNext == 5)
            {
                countPipes(pipes, n, m, x, y - 1, visited, numPipes, len);
            }
        }

        if (x + 1 < n)
        {
            int checkNext = pipes[x + 1][y];
            if (checkNext == 1 || checkNext == 2 || checkNext == 4 || checkNext == 7)
            {
                countPipes(pipes, n, m, x + 1, y, visited, numPipes, len);
            }
        }

        if (x - 1 >= 0)
        {
            int checkNext = pipes[x - 1][y];
            if ((checkNext == 1 || checkNext == 2 || checkNext == 5 || checkNext == 6))
            {
                countPipes(pipes, n, m, x - 1, y, visited, numPipes, len);
            }
        }
    }
    else if (pipes[x][y] == 2)
    {
        if (x + 1 < n)
        {
            int checkNext = pipes[x + 1][y];
            if (checkNext == 1 || checkNext == 2 || checkNext == 4 || checkNext == 7)
            {
                countPipes(pipes, n, m, x + 1, y, visited, numPipes, len);
            }
        }
        if (x - 1 >= 0)
        {
            int checkNext = pipes[x - 1][y];
            if ((checkNext == 1 || checkNext == 2 || checkNext == 5 || checkNext == 6))
            {
                countPipes(pipes, n, m, x - 1, y, visited, numPipes, len);
            }
        }
    }
    else if (pipes[x][y] == 3)
    {
        if (y + 1 < m)
        {
            int checkNext = pipes[x][y + 1];
            if (checkNext == 1 || checkNext == 3 || checkNext == 6 || checkNext == 7)
            {
                countPipes(pipes, n, m, x, y + 1, visited, numPipes, len);
            }
        }

        if (y - 1 >= 0)
        {
            int checkNext = pipes[x][y - 1];
            if (checkNext == 1 || checkNext == 3 || checkNext == 4 || checkNext == 5)
            {
                countPipes(pipes, n, m, x, y - 1, visited, numPipes, len);
            }
        }
    }
    else if (pipes[x][y] == 4)
    {
        if (y + 1 < m)
        {
            int checkNext = pipes[x][y + 1];
            if (checkNext == 1 || checkNext == 3 || checkNext == 6 || checkNext == 7)
            {
                countPipes(pipes, n, m, x, y + 1, visited, numPipes, len);
            }
        }
        if (x - 1 >= 0)
        {
            int checkNext = pipes[x - 1][y];
            if ((checkNext == 1 || checkNext == 2 || checkNext == 5 || checkNext == 6))
            {
                countPipes(pipes, n, m, x - 1, y, visited, numPipes, len);
            }
        }
    }
    else if (pipes[x][y] == 5)
    {
        if (y + 1 < m)
        {
            int checkNext = pipes[x][y + 1];
            if (checkNext == 1 || checkNext == 3 || checkNext == 6 || checkNext == 7)
            {
                countPipes(pipes, n, m, x, y + 1, visited, numPipes, len);
            }
        }
        if (x + 1 < n)
        {
            int checkNext = pipes[x + 1][y];
            if (checkNext == 1 || checkNext == 2 || checkNext == 4 || checkNext == 7)
            {
                countPipes(pipes, n, m, x + 1, y, visited, numPipes, len);
            }
        }
    }
    else if (pipes[x][y] == 6)
    {
        if (y - 1 >= 0)
        {
            int checkNext = pipes[x][y - 1];
            if (checkNext == 1 || checkNext == 3 || checkNext == 4 || checkNext == 5)
            {
                countPipes(pipes, n, m, x, y - 1, visited, numPipes, len);
            }
        }
        if (x + 1 < n)
        {
            int checkNext = pipes[x + 1][y];
            if (checkNext == 1 || checkNext == 2 || checkNext == 4 || checkNext == 7)
            {
                countPipes(pipes, n, m, x + 1, y, visited, numPipes, len);
            }
        }
    }
    else if (pipes[x][y] == 7)
    {
        if (y - 1 >= 0)
        {
            int checkNext = pipes[x][y - 1];
            if (checkNext == 1 || checkNext == 3 || checkNext == 4 || checkNext == 5)
            {
                countPipes(pipes, n, m, x, y - 1, visited, numPipes, len);
            }
        }
        if (x - 1 >= 0)
        {
            int checkNext = pipes[x - 1][y];
            if ((checkNext == 1 || checkNext == 2 || checkNext == 5 || checkNext == 6))
            {
                countPipes(pipes, n, m, x - 1, y, visited, numPipes, len);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y, l;
        cin >> n >> m >> x >> y >> l;
        vector<vector<int>> pipes(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> pipes[i][j];
        }

        map<pair<int, int>, bool> visited;
        int numPipes = 0;
        countPipes(pipes, n, m, x, y, visited, numPipes, l);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[{i, j}])
                    numPipes++;
            }
        }
        cout << numPipes << endl;
    }
}
