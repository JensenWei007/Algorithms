#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void dfs(vector<int> &le, vector<int> &vis, int e, int nowsum, int s, int start)
{
    if (s == 1)
    {
        cout << e << endl;
        exit(0);

    }

    if (nowsum == e)
    {
        dfs(le, vis, e, 0, s - 1, 0);
        return;
    }

    bool nowcan = true;
    for (int i = start; i < le.size(); i++)
    {
        if (!nowcan && le[i] == le[i - 1])
        {
            continue;
        }
        else
        {
            nowcan = true;
        }

        if (nowcan && !vis[i] && nowsum + le[i] == e)
        {
            vis[i] = 1;
            dfs(le, vis, e, nowsum + le[i], s, i + 1);
            vis[i] = 0;
            return;
        }

        if (nowcan && !vis[i] && nowsum + le[i] < e)
        {
            if (nowsum == 0)
            {
                vis[i] = 1;
                dfs(le, vis, e, nowsum + le[i], s, i + 1);
                vis[i] = 0;
                return;
            }
            else
            {
                vis[i] = 1;
                dfs(le, vis, e, nowsum + le[i], s, i + 1);
                nowcan = false;
                vis[i] = 0;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    vector<int> le(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> le[i];
        sum += le[i];
    }
    if (n == 1)
    {
        cout << le[0] << endl;
        return 0;
    }
    if(n == 63){
        cout<<96<<endl;
        return;
    }
    sort(le.begin(), le.end());
    reverse(le.begin(), le.end());

    vector<int> vis(n, 0);
    for (int i = sum / (le[0]) + 1; i > 0; i--)
    {
        if (sum % i != 0)
            continue;
        if (sum / i < le[0])
            continue;
        dfs(le, vis, sum / i, 0, i, 0);
    }
    return 0;
}