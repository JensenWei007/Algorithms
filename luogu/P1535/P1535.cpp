#include <iostream>
#include <vector>

using namespace std;

int n, m, t;
int r1, c1, r2, c2;
int res = 0;

pair<int, int> valid(int x, int y)
{
    int r = x;
    int c = y;
    if (x < 0)
        r = 0;
    if (x >= n)
        r = n - 1;
    if (y < 0)
        c = 0;
    if (y >= m)
        c = m - 1;
    return make_pair(r, c);
}

int same(int x1, int y1, int x2, int y2)
{
    return (x1 == x2) && (y1 == y2);
}

int dfs(vector<vector<vector<int>>> &an, vector<vector<char>> &ma, int x, int y, int b)
{
    if (b == t)
    {
        if (x == r2 && y == c2)
        {
            return 1;
        }
        return 0;
    }
    if (ma[x][y] == '*')
        return 0;
    if (an[x][y][b] != 0)
        return an[x][y][b];
    pair<int, int> shang = valid(x - 1, y);
    if (!same(shang.first, shang.second, x, y))
    {
        an[x][y][b] += dfs(an, ma, shang.first, shang.second, b + 1);
    }
    pair<int, int> xia = valid(x + 1, y);
    if (!same(xia.first, xia.second, x, y))
    {
        an[x][y][b] += dfs(an, ma, xia.first, xia.second, b + 1);
    }
    pair<int, int> zuo = valid(x, y - 1);
    if (!same(zuo.first, zuo.second, x, y))
    {
        an[x][y][b] += dfs(an, ma, zuo.first, zuo.second, b + 1);
    }
    pair<int, int> you = valid(x, y + 1);
    if (!same(you.first, you.second, x, y))
    {
        an[x][y][b] += dfs(an, ma, you.first, you.second, b + 1);
    }
    return an[x][y][b];
}

int main()
{
    cin >> n >> m >> t;
    vector<vector<char>> ma(n, vector<char>(m));
    vector<vector<vector<int>>> an(n, vector<vector<int>>(m, vector<int>(t, 0)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> ma[i][j];
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    c1--;
    r2--;
    c2--;

    if (same(r1, c1, r2, c2))
    {
        cout << 0 << endl;
        return 0;
    }

    cout << dfs(an, ma, r1, c1, 0) << endl;

    return 0;
}