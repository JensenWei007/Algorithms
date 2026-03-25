#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

int isok(vector<int> &vi)
{
    for (int i = 0; i < vi.size(); i++)
        if (vi[i] == 0)
            return 0;
    return 1;
}

pair<int, int> mvalid(pair<int, int> p, int n, int m)
{
    int x = p.first;
    int y = p.second;
    if (x < 0)
        x = 0;
    if (x >= n)
        x = n - 1;
    if (y < 0)
        y = 0;
    if (y >= m)
        y = m - 1;
    return make_pair(x, y);
}

void bfs(vector<vector<int>> &ma, vector<vector<int>> &an, int pos)
{
    int n = ma.size();
    int m = ma[0].size();
    vector<vector<int>> vi(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    q.push(make_pair(0, pos));
    while (!q.empty())
    {
        pair<int, int> f = q.front();
        q.pop();
        int x = f.first;
        int y = f.second;
        pair<int, int> shang = mvalid(make_pair(x - 1, y), n, m);
        pair<int, int> xia = mvalid(make_pair(x + 1, y), n, m);
        pair<int, int> zuo = mvalid(make_pair(x, y - 1), n, m);
        pair<int, int> you = mvalid(make_pair(x, y + 1), n, m);
        if (!(shang.first == x && shang.second == y) && vi[shang.first][shang.second] == 0 && (ma[shang.first][shang.second] < ma[x][y]))
        {
            vi[shang.first][shang.second] = 1;
            q.push(shang);
        }
        if (!(xia.first == x && xia.second == y) && vi[xia.first][xia.second] == 0 && (ma[xia.first][xia.second] < ma[x][y]))
        {
            vi[xia.first][xia.second] = 1;
            q.push(xia);
        }
        if (!(zuo.first == x && zuo.second == y) && vi[zuo.first][zuo.second] == 0 && (ma[zuo.first][zuo.second] < ma[x][y]))
        {
            vi[zuo.first][zuo.second] = 1;
            q.push(zuo);
        }
        if (!(you.first == x && you.second == y) && vi[you.first][you.second] == 0 && (ma[you.first][you.second] < ma[x][y]))
        {
            vi[you.first][you.second] = 1;
            q.push(you);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (vi[n - 1][i] == 1)
            an[pos].push_back(i);
    }
}

int fi(vector<vector<int>> &an, vector<int> &vi, int pp)
{
    int ans = 0;
    int anspos = -1;
    for (int i = 0; i < an.size(); i++)
    {
        if (an[i].size() == 0)
            continue;
        auto it = find(an[i].begin(), an[i].end(), pp);
        if (an[i].end() != it)
        {
            int pos = std::distance(an[i].begin(), it);
            int r = 1;
            for (int j = pos + 1; j < an[i].size(); j++)
            {
                if (an[i][j] - an[i][j - 1] == 1)
                {
                    r++;
                    vi[an[i][j]] = 1;
                }
                else
                {
                    break;
                }
            }
            if (r > ans)
            {
                ans = r;
                anspos = i;
            }
        }
    }
    return anspos;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> ma(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> ma[i][j];
    }
    vector<vector<int>> an(m);

    for (int i = 0; i < m; i++)
    {
        bfs(ma, an, i);
    }

    // 如果是一行, 那么他们本身也可以灌溉到他们本身
    if (n == 1)
    {
        for (int i = 0; i < m; i++)
        {
            an[i].push_back(i);
            sort(an[i].begin(), an[i].end());
        }
    }

    int r = 0;
    vector<int> vi(m, 0);
    for (int i = 0; i < m; i++)
    {
        if (vi[i] == 1)
            continue;
        int p = fi(an, vi, i);
        if (p != -1)
        {
            vi[i] = 1;
            r++;
        }
    }

    if (!isok(vi))
    {
        cout << 0 << endl;
        r = 0;
        for (int i = 0; i < m; i++)
            if (vi[i] == 0)
                r++;
        cout << r << endl;
    }
    else
    {
        cout << 1 << endl;
        cout << r << endl;
    }

    return 0;
}