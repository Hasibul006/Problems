#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void optimalPath(vector<pair<int, int>> nodes, int startX, int startY, int endX, int endY, vector<bool> &visited, int currDist, int currIndex, int &minDist)
{
    if (currIndex == nodes.size())
    {
        currDist += abs(startX - endX) + abs(startY - endY);
        minDist = min(minDist, currDist);
        return;
    }

    for (int i = 0; i < nodes.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            optimalPath(nodes, nodes[i].first, nodes[i].second, endX, endY, visited, currDist + abs(nodes[i].first - startX) + abs(nodes[i].second - startY), currIndex + 1, minDist);
            visited[i] = false;
        }
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t = 1;
    while (++t)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> nodes(n);
        int startX, startY, endX, endY;
        cin >> endX >> endY >> startX >> startY;
        for (int i = 0; i < n; i++)
            cin >> nodes[i].first >> nodes[i].second;

        int minDist = INT_MAX;
        vector<bool> visited(n, false);

        optimalPath(nodes, startX, startY, endX, endY, visited, 0, 0, minDist);
        cout << "#" << t - 1 << " " << minDist << endl;
        if (t > 10)
            break;
    }

    return 0;
}
