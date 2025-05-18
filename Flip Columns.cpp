#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n);
    vector<int> zeros(n);
    map<vector<int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            v[i].push_back(temp);
            if (v[i][j] == 0)
                x++;
        }
        mp[v[i]]++;
        zeros[i] = x;
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (mp[v[i]] == -1)
            continue;

        int numZ = zeros[i];
        if (((k - numZ) % 2 == 0) && k >= numZ)
            ans = max(ans, mp[v[i]]);
        else
            mp[v[i]] = -1;
    }
    cout << ans;
    return 0;
}
