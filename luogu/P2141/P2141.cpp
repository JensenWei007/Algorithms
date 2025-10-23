#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    vector<bool> pf(n, true);
    vector<vector<int>> sum(n, vector<int>(n, 0));
    int r = 0;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    // sum[i][j]代表第i个元素, 他如果是第j个元素和另一个元素的和，那么另一个元素应该是多少
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
            {
                continue;
            }
            sum[i][j] = p[i] - p[j];
        }
    }

    for (int ii = 0; ii < n; ii++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                {
                    continue;
                }
                if (p[ii] == sum[i][j] && ii != j && ii != i && pf[i])
                {
                    r++;
                    pf[i] = false;
                }
            }
        }
    }

    cout << r << endl;

    return 0;
}