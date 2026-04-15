#include <iostream>
#include <vector>

using namespace std;

int r, c;

pair<int, int> valid(int x, int y)
{
    int xx = x;
    int yy = y;
    if (x < 0)
        xx = 0;
    if (x >= r)
        xx = r - 1;
    if (y < 0)
        yy = 0;
    if (y >= c)
        yy = c - 1;
    return make_pair(xx, yy);
}

int issame(int x1, int y1, int x2, int y2)
{
    return (x1 == x2) && (y1 == y2);
}

int dfs(vector<vector<int>> &ma, vector<vector<int>> &re, int x, int y)
{
    if (re[x][y] != -1)
        return re[x][y];
    pair<int, int> shang = valid(x - 1, y);
    pair<int, int> xia = valid(x + 1, y);
    pair<int, int> zuo = valid(x, y - 1);
    pair<int, int> you = valid(x, y + 1);

    bool back = true;
    if (!issame(shang.first, shang.second, x, y) && (ma[x][y] > ma[shang.first][shang.second]))
    {
        back = false;
        re[x][y] = max(re[x][y], dfs(ma, re, shang.first, shang.second) + 1);
    }
    if (!issame(xia.first, xia.second, x, y) && (ma[x][y] > ma[xia.first][xia.second]))
    {
        back = false;
        re[x][y] = max(re[x][y], dfs(ma, re, xia.first, xia.second) + 1);
    }
    if (!issame(zuo.first, zuo.second, x, y) && (ma[x][y] > ma[zuo.first][zuo.second]))
    {
        back = false;
        re[x][y] = max(re[x][y], dfs(ma, re, zuo.first, zuo.second) + 1);
    }
    if (!issame(you.first, you.second, x, y) && (ma[x][y] > ma[you.first][you.second]))
    {
        back = false;
        re[x][y] = max(re[x][y], dfs(ma, re, you.first, you.second) + 1);
    }
    if (back)
    {
        re[x][y] = 1;
    }
    return re[x][y];
}

int main()
{
    cin >> r >> c;
    vector<vector<int>> ma(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> ma[i][j];

    vector<vector<int>> re(r, vector<int>(c, -1));

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (re[i][j] == -1)
                dfs(ma, re, i, j);
        }

    int res = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (re[i][j] > res)
                res = re[i][j];

    cout << res << endl;
    return 0;
}
