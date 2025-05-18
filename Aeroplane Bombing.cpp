#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void op(int a[][5], int row, int col, int &count, int coins, int bombed, int safeRow)
{

    if (col > 4 || col < 0 || row < 0)
    {
        count = max(count, coins);
        return;
    }

    if (a[row][col] == 1 || a[row][col] == 0)
    {
        if (a[row][col] == 1)
        {
            coins++;
        }
        if (bombed == 1)
            safeRow--;

        op(a, row - 1, col - 1, count, coins, bombed, safeRow);
        op(a, row - 1, col, count, coins, bombed, safeRow);
        op(a, row - 1, col + 1, count, coins, bombed, safeRow);
    }
    else if (a[row][col] == 2)
    {
        if (bombed)
        {
            if (safeRow > 0)
            {
                safeRow--;
                op(a, row - 1, col - 1, count, coins, bombed, safeRow);
                op(a, row - 1, col, count, coins, bombed, safeRow);
                op(a, row - 1, col + 1, count, coins, bombed, safeRow);
            }
            else
            {
                count = max(count, coins);
                return;
            }
        }
        else
        {
            bombed = 1;
            safeRow = 4;
            op(a, row - 1, col - 1, count, coins, bombed, safeRow);
            op(a, row - 1, col, count, coins, bombed, safeRow);
            op(a, row - 1, col + 1, count, coins, bombed, safeRow);
        }
    }
}

int main()
{
    int t, num = 1;
    cin >> t;
    while (t--)
    {
        int row;
        cin >> row;
        int a[row][5];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> a[i][j];
            }
        }
        int count = 0;
        int safeRow = 0;

        op(a, row - 1, 1, count, 0, 0, 0);
        op(a, row - 1, 2, count, 0, 0, 0);
        op(a, row - 1, 3, count, 0, 0, 0);

        cout << "#" << num << " " << count << endl;
        num++;
    }

    return 0;
}
