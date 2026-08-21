#include <iostream>
#include <bitset>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
#define ll long long

int a[21];
int n;
int ans;
int bb[21];
map<string, ll> mm;

bitset<11> b1;
bitset<11> b2;
map<ll, ll> aa1;
vector<vector<ll>> av1;
ll cnav1;

ll anss[2000001];

string tol()
{
    string ret = "";
    for (int i = 0; i < 21; i++)
    {
        if (bb[i] == 1)
            ret += "1";
        if (bb[i] == -1)
            ret += "-";
        if (bb[i] == 0)
            ret += "0";
    }
    return ret;
}

void dfs(int d, int e, ll sum1, ll sum2)
{
    if (d == e)
    {
        if (mm[tol()] == 0)
        {
            mm[tol()] = 1;
            if (aa1[sum1 - sum2] == 0)
            {
                aa1[sum1 - sum2] = ++cnav1;
                av1.push_back(vector<ll>(1, b1.to_ulong()));
            }
            else
            {
                av1[aa1[sum1 - sum2]].push_back(b1.to_ulong());
            }
        }
        return;
    }
    b1[d] = 1;
    bb[d] = 1;
    dfs(d + 1, e, sum1 + a[d], sum2);
    bb[d] = -1;
    dfs(d + 1, e, sum1, sum2 + a[d]);
    bb[d] = 0;
    b1[d] = 0;
    dfs(d + 1, e, sum1, sum2);
}

void dfsa(int s, int d, int e, ll sum1, ll sum2)
{
    if (d == e)
    {
        if (mm[tol()] == 0)
        {
            mm[tol()] = 1;
            if (aa1[sum2 - sum1] != 0)
            {
                vector<ll> &temp = av1[aa1[sum2 - sum1]];
                int siz = temp.size();

                for (int i = 0; i < siz; i++)
                {
                    ll bb1 = temp[i];
                    ll bb2 = b2.to_ulong() << s;
                    anss[bb1 + bb2] = 1;
                }
            }
        }
        return;
    }
    b2[d - s] = 1;
    bb[d] = 1;
    dfsa(s, d + 1, e, sum1 + a[d], sum2);
    bb[d] = -1;
    dfsa(s, d + 1, e, sum1, sum2 + a[d]);
    bb[d] = 0;
    b2[d - s] = 0;
    dfsa(s, d + 1, e, sum1, sum2);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    av1.push_back(vector<ll>(1, 0));

    dfs(0, n / 2, 0, 0);
    mm.clear();
    for (int i = 0; i < 21; i++)
        bb[i] = 0;
    dfsa(n / 2, n / 2, n, 0, 0);

    for (int i = 1; i < 2000001; i++)
        if (anss[i])
            ans++;
    cout << ans << endl;

    return 0;
}