#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    int sum = 0;
    int level = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            level++;
        else if (s[i] == ')')
            level--;
        else if (level == k)
        {
            int x = 0;
            while (s[i] >= '0' && s[i] <= '9')
            {
                x = x * 10 + s[i] - '0';
                i++;
            }
            i--;
            sum += x;
        }
    }

    cout << sum << endl;

    return 0;
}
