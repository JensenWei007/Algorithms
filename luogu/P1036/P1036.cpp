#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long res = 0;

bool iss(int x)
{
    int s = sqrt(x);
    for (int i = 2; i <= s; i++)
        if (x % i == 0)
            return false;
    return true;
}

void dfs(vector<int> &s, int k, int n, int p, long long sum)
{
    for (; p < s.size(); p++)
    {
        n++;
        sum += s[p];
        if (n == k)
        {
            if (iss(sum))
                res++;
        }
        else
        {
            dfs(s, k, n, p+1, sum);
        }
        n--;
        sum -= s[p];
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    sort(s.begin(), s.end());

    dfs(s, k, 0, 0, 0);

    cout << res << endl;

    return 0;
}