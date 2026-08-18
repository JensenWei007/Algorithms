#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> map(9, vector<int>(9, 0));

int id[9][9] = {
    {0, 0, 0, 1, 1, 1, 2, 2, 2},
    {0, 0, 0, 1, 1, 1, 2, 2, 2},
    {0, 0, 0, 1, 1, 1, 2, 2, 2},
    {3, 3, 3, 4, 4, 4, 5, 5, 5},
    {3, 3, 3, 4, 4, 4, 5, 5, 5},
    {3, 3, 3, 4, 4, 4, 5, 5, 5},
    {6, 6, 6, 7, 7, 7, 8, 8, 8},
    {6, 6, 6, 7, 7, 7, 8, 8, 8},
    {6, 6, 6, 7, 7, 7, 8, 8, 8}};

int score[9][9] = {
    {6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 7, 7, 7, 7, 7, 7, 7, 6},
    {6, 7, 8, 8, 8, 8, 8, 7, 6},
    {6, 7, 8, 9, 9, 9, 8, 7, 6},
    {6, 7, 8, 9, 10, 9, 8, 7, 6},
    {6, 7, 8, 9, 9, 9, 8, 7, 6},
    {6, 7, 8, 8, 8, 8, 8, 7, 6},
    {6, 7, 7, 7, 7, 7, 7, 7, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6}};

int h[10][10];
int l[10][10];
int g[10][10];

long long sum = 0;
long long ans = 0;
int zero = 0;
vector<pair<int, int>> hz;
vector<vector<pair<int, int>>> knx(9, vector<pair<int, int>>());

int sear[100][4];

void print(int index = 0)
{
    cout << "======" << index << "======" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << "======" << index << "======" << endl;
}

bool commy(pair<int, int> a, pair<int, int> b)
{
    return a.second <= b.second;
}

void dfs(int now, int sc)
{
    if (now == zero)
    {
        if (sc + sum > ans)
            ans = sc + sum;
        return;
    }
    int ha = sear[now][0];
    int li = sear[now][1];
    for (int i = 9; i > 0; i--)
    {
        if (h[ha][i] == 0 && l[li][i] == 0 && g[id[ha][li]][i] == 0)
        {
            map[ha][li] = i;
            h[ha][i] = 1;
            l[li][i] = 1;
            g[id[ha][li]][i] = 1;
            dfs(now + 1, sc + score[ha][li] * i);
            map[ha][li] = 0;
            h[ha][i] = 0;
            l[li][i] = 0;
            g[id[ha][li]][i] = 0;
        }
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        hz.push_back(make_pair(i, 0));
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            knx[i].push_back(make_pair(j, 0));
        }
    }
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0)
            {
                zero++;
                hz[i].second++;
            }
            else
            {
                h[i][map[i][j]] = 1;
                l[j][map[i][j]] = 1;
                g[id[i][j]][map[i][j]] = 1;
                sum += map[i][j] * score[i][j];
            }
        }
    sort(hz.begin(), hz.end(), commy);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            if (map[i][j] != 0)
            {
                knx[i][j].second = 100;
                continue;
            }
            for (int s = 1; s < 10; s++)
            {
                if (h[i][s] == 0 && l[j][s] == 0 && g[id[i][j]][s] == 0)
                    knx[i][j].second++;
            }
        }
    for (int i = 0; i < 9; i++)
        sort(knx[i].begin(), knx[i].end(), commy);
    /*
for (int i = 0; i < 9; i++)
{
    for (int j = 0; j < 9; j++)
        cout << knx[i][j].second << " ";
    cout << endl;
}
    for (int i = 0; i < 9; i++)
{
    for (int j = 0; j < 9; j++)
        cout << knx[i][j].first << " ";
    cout << endl;
}
    */
    int ind = 0;
    for (int i = 0; i < 9; i++)
    {
        int hang = hz[i].first;
        for (int j = 0; j < 9; j++)
        {
            if (knx[hang][j].second == 100)
                break;
            sear[ind][0] = hang;
            sear[ind++][1] = knx[hang][j].first;
            // sear[u][2]
        }
    }
    // for (int i = 0; i < ind; i++)cout << i << " " << sear[i][0] << " " << sear[i][1] << endl;
    dfs(0, 0);
    if (ans == 0)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}