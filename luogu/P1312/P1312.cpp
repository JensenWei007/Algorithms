#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> mma(7, vector<int>(5, 0));
vector<vector<int>> vis(7, vector<int>(5, 0));

struct ansf
{
    int x;
    int y;
    int a;
};

vector<ansf> ans;

struct ansf mak(int x, int y, int a)
{
    ansf s1;
    s1.x = x;
    s1.y = y;
    s1.a = a;
    return s1;
}

int zuo(int x, int y, vector<vector<int>> &ma)
{
    return !(x == 0) && (ma[y][x - 1] == 0);
}

int you(int x, int y)
{
    return !(x == 4);
}

int isdone(vector<vector<int>> &ma)
{
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 5; j++)
            if (ma[i][j] != 0)
                return 0;
    return 1;
}

int miss(vector<vector<int>> &ma)
{
    vector<pair<int, pair<int, int>>> ned;
    vector<pair<int, pair<int, int>>> nedd;

    for (int i = 0; i < 7; i++)
    {
        int h = 1;
        int last = ma[i][0];
        int last_num = 1;
        while (h < 5)
        {
            if (ma[i][h] == last)
            {
                last_num++;
            }
            else
            {
                last = ma[i][h];
                last_num = 1;
            }
            h++;
            if (last_num == 3)
            {
                ned.push_back(make_pair(i, make_pair(h - 3, h - 1)));
            }
            if (last_num > 3)
            {
                ned[ned.size() - 1].second.second++;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        int h = 1;
        int last = ma[0][i];
        int last_num = 1;
        while (h < 7)
        {
            if (ma[h][i] == last)
            {
                last_num++;
            }
            else
            {
                last = ma[h][i];
                last_num = 1;
            }
            h++;
            if (last_num == 3)
            {
                nedd.push_back(make_pair(i, make_pair(h - 3, h - 1)));
            }
            if (last_num > 3)
            {
                nedd[nedd.size() - 1].second.second++;
            }
        }
    }

    for (int i = 0; i < ned.size(); i++)
    {
        int a = ned[i].first;
        int start = ned[i].second.first;
        int end = ned[i].second.second;
        for (int j = start; j <= end; j++)
            ma[a][j] = 0;
    }

    for (int i = 0; i < nedd.size(); i++)
    {
        int a = nedd[i].first;
        int start = nedd[i].second.first;
        int end = nedd[i].second.second;
        for (int j = start; j <= end; j++)
            ma[j][a] = 0;
    }

    return 1;
}

int fall(vector<vector<int>> &ma)
{
    int ret = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (ma[j][i] == 0)
            {
                int firsz = j;
                for (int k = j + 1; k < 7; k++)
                {
                    if (ma[k][i] != 0)
                    {
                        ma[firsz++][i] = ma[k][i];
                        ma[k][i] = 0;
                        ret = 1;
                    }
                }
            }
        }
    }
    return ret;
}

void swap(vector<vector<int>> &ma, int x1, int y1, int x2, int y2)
{
    int temp = ma[y1][x1];
    ma[y1][x1] = ma[y2][x2];
    ma[y2][x2] = temp;
}

void dfs(vector<vector<int>> ma, int lx, int ly, int a)
{
    if (ans.size() == n)
    {
        if (isdone(ma))
        {
            for (int i = 0; i < n; i++)
            {
                cout << ans[i].x << " " << ans[i].y << " " << ans[i].a << endl;
            }
            exit(0);
        }
        return;
    }

    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < 7; y++)
        {
            if (ma[y][x] == 0)
                continue;

            if (you(x, y))
            {
                ans.push_back(mak(x, y, 1));

                vector<vector<int>> next(ma);
                swap(next, x, y, x + 1, y);
                do
                {
                    miss(next);
                } while (fall(next));
                dfs(next, x, y, 1);

                ans.pop_back();
            }
            if (zuo(x, y, ma))
            {
                ans.push_back(mak(x, y, -1));

                vector<vector<int>> next(ma);
                swap(next, x, y, x - 1, y);
                do
                {
                    miss(next);
                } while (fall(next));
                dfs(next, x, y, -1);

                ans.pop_back();
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < 5; i++)
    {
        int cnt = 0;
        for (int j = 0; j < 8; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 0)
                break;
            mma[cnt++][i] = temp;
        }
    }
    vector<vector<int>> fin(mma);
    dfs(fin, -1, -1, 0);
    cout << -1 << endl;
    return 0;
}