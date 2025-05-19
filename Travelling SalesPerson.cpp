#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void optimalPath(vector<vector<int>> &distances, int n, int parentNode, int currNode, vector<bool> &visited, int numVisited, int dist, int &minDist)
{
    if (numVisited == n)
    {
        dist += distances[currNode][0];
        minDist = min(minDist, dist);
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            optimalPath(distances, n, currNode, i, visited, numVisited + 1, dist + distances[currNode][i], minDist);
            visited[i] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> distances(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp;
                cin >> temp;
                distances[i].push_back(temp);
            }
        }

        int minDistance = INT_MAX;
        vector<bool> visited(n, false);
        visited[0] = true;
        for (int i = 1; i < n; i++)
        {
            visited[i] = true;
            optimalPath(distances, n, 0, i, visited, 2, distances[0][i], minDistance);
            visited[i] = false;
        }
        cout << minDistance << endl;
    }
    return 0;
}
