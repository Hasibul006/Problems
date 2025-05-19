#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void findMinCost(vector<pair<int, int>> &startWorm, vector<pair<int, int>> &endWorm, int endX, int endY,
                 int currX, int currY, int n, vector<bool> &visited, int wormIndex, vector<int> &costWorm,
                 int cost, int &minCost)
{
    if (cost > minCost)
        return;

    int directCost = abs(currX - endX) + abs(currY - endY);
    minCost = min(minCost, cost + directCost);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            int startCost = abs(currX - startWorm[i].first) + abs(currY - startWorm[i].second);
            findMinCost(startWorm, endWorm, endX, endY, endWorm[i].first, endWorm[i].second, n, visited, i, costWorm, cost + startCost + costWorm[i], minCost);
            int endCost = abs(currX - endWorm[i].first) + abs(currY - endWorm[i].second);
            findMinCost(startWorm, endWorm, endX, endY, startWorm[i].first, startWorm[i].second, n, visited, i, costWorm, cost + endCost + costWorm[i], minCost);
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
        int n, startX, startY, endX, endY;
        cin >> n >> startX >> startY >> endX >> endY;
        vector<pair<int, int>> strartWormX(n);
        vector<pair<int, int>> strartWormY(n);
        vector<int> costWorm(n);
        for (int i = 0; i < n; i++)
        {
            int sX, sY, eX, eY, cost;
            cin >> sX >> sY >> eX >> eY >> cost;
            strartWormX[i] = make_pair(sX, sY);
            strartWormY[i] = make_pair(eX, eY);
            costWorm[i] = cost;
        }

        int minCost = INT_MAX;
        vector<bool> visited(n, false);
        findMinCost(strartWormX, strartWormY, endX, endY, startX, startY, n, visited, -1, costWorm, 0, minCost);
        cout << minCost << endl;
    }
    return 0;
}
