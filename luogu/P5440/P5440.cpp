#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 100000000;
bool su[MAX_N];
bool vis[MAX_N];
int s[MAX_N];
bool su_vis[MAX_N];

void e()
{
    int k = 0;

    su[0] = su[1] = false;

    for (int i = 2; i < MAX_N; i++)
    {
        if (!vis[i])
        {
            su[i] = true;
            s[k++] = i;
        }

        for (int j = 0; j < k; j++)
        {
            long long num = 1LL * i * s[j];
            if (num >= MAX_N)
                break;

            vis[num] = true;

            if (i % s[j] == 0)
                break;
        }
    }
}

int res;

bool valid(string s)
{
    int m = stoi(s.substr(4, 2));
    int d = stoi(s.substr(6, 2));
    int y = stoi(s.substr(0, 4));

    if (y < 1 || y > 9999)
        return false;

    if (m == 2)
    {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0 && y % 3200 != 0))
        {
            if (d <= 0 || d > 29)
            {
                return false;
            }
        }
        else
        {
            if (d <= 0 || d > 28)
            {
                return false;
            }
        }
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        if (d <= 0 || d >= 31)
        {
            return false;
        }
    }
    else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        if (d <= 0 || d >= 32)
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    return true;
}

void ser(string s, int p)
{
    // cout<<"ser:"<<s<<" "<<p<<endl;
    if (p == 5)
    {
        string d = s.substr(6, 2);
        int dd = stoi(d);
        if (!su[dd])
            return;
        if (dd > 31)
            return;
    }
    if (p == 3)
    {
        string md = s.substr(4, 4);
        int mdd = stoi(md);
        if (!su[mdd])
            return;
        if (mdd > 1300)
            return;
    }
    if (p == -1)
    {
        int ss = stoi(s);
        int d = stoi(s.substr(6, 2));
        int md = stoi(s.substr(4, 4));
        if (su[ss] && su[d] && su[md] && !su_vis[ss] && valid(s))
        {
            su_vis[ss] = true;
            res++;
        }
        return;
    }
    if (s[p] == '-')
    {
        for (int i = 0; i < 10; i++)
        {
            s[p] = '0' + i;
            ser(s, p - 1);
        }
    }
    else
    {
        ser(s, p - 1);
    }
}

int main()
{
    int t;
    cin >> t;
    vector<string> r;
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        r.push_back(s);
    }

    e();

    for (int i = 0; i < t; i++)
    {
        string s = r[i];
        res = 0;
        memset(su_vis, false, MAX_N);
        ser(s, 7);
        cout << res << endl;
    }

    return 0;
}