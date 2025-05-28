#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getMaxScore(vector<int> &v, int left, int right, int total)
{
    int mScore = 0;
    for (int i = left + 1; i < right; i++)
    {
        int cs = getMaxScore(v, left, i, total) + getMaxScore(v, i, right, total);
        if (left == 0 && right == total)
            cs += v[i];
        else
            cs += (v[left] * v[right]);

        mScore = max(mScore, cs);
    }
    return mScore;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    v[0] = 1;
    v[n + 1] = 1;

    int maxScore = getMaxScore(v, 0, n + 1, n + 1);
    cout << maxScore << endl;
    return 0;
}
