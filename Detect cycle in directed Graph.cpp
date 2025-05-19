#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void checkCycle(int node, map<int, vector<int>> &adj, map<int, bool> &isVisited, map<int, bool> &isInPath, vector<int> &path, vector<int> &minCycle, int &minSum)
{

    isVisited[node] = true;
    isInPath[node] = true;
    path.push_back(node);

    for (auto next : adj[node])
    {
        if (!isVisited[next])
        {
            checkCycle(next, adj, isVisited, isInPath, path, minCycle, minSum);
        }
        else if (isInPath[next])
        {
            vector<int> temp;
            int sum = 0;
            for (int i = path.size() - 1; i >= 0; i--)
            {
                temp.push_back(path[i]);
                sum += path[i];
                if (path[i] == next)
                    break;
            }
            if (sum < minSum)
            {
                minCycle = temp;
                minSum = sum;
            }
        }
    }

    path.pop_back();
    isInPath[node] = false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<int> minCycle;
    int minSum = INT_MAX;

    for (int i = 1; i <= n; i++)
    {
        map<int, bool> isVisited;
        map<int, bool> isInPath;
        vector<int> path;
        checkCycle(i, adj, isVisited, isInPath, path, minCycle, minSum);
    }

    sort(minCycle.begin(), minCycle.end());
    for (int node : minCycle)
        cout << node << " ";

    return 0;
}
