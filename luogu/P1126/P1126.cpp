#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

// trun left --, right ++
// N, E, S, W
pair<int, int> dd[4] = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1)};

int res;
int endf;

int n;
int m;

int turn_l(int d)
{
    if (d == 0)
        return 3;
    return d - 1;
}

int turn_r(int d)
{
    if (d == 3)
        return 0;
    return d + 1;
}

bool valid(int px, int py, vector<vector<int>> &ma)
{
    // cout << "valid:" << px << " " << py << " " << res << endl;
    if (px == 0 || py == 0)
        return false;
    if (px >= n || py >= m)
        return false;
    if (ma[px - 1][py - 1] || ma[px][py - 1] || ma[px - 1][py] || ma[px][py])
        return false;
    return true;
}

bool dof(int px, int py, int d, vector<vector<int>> &ma, vector<vector<int>> &vis, int w)
{
    // cout << "dof:" << px << " " << py << " " << d << " "<<w<<endl;
    pair<int, int> dir = dd[d];
    int x = px;
    int y = py;
    for (int i = 0; i < w; i++)
    {
        x += dir.first;
        y += dir.second;
        if (!valid(x, y, ma))
            return false;
    }
    // if (vis[x][y])
    //     return false;
    return true;
}

void bfs(int px, int py, int ex, int ey, int d, int turn, vector<vector<int>> &ma, vector<vector<int>> &vis, vector<vector<vector<int>>> &dr)
{
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(px, py), d));

    while (!q.empty())
    {
        pair<pair<int, int>, int> now = q.front();
        q.pop();
        px = now.first.first;
        py = now.first.second;
        int res = vis[px][py];
        d = now.second;
        // cout << "now" << px << " " << py << " " <<d<<" "<< vis[px][py] << endl;
        //  if (px == ex && py == ey)
        //{
        //      cout << res << endl;
        //      return;
        //  }
        if (dof(px, py, d, ma, vis, 1))
        {
            int x = px + dd[d].first;
            int y = py + dd[d].second;
            if (vis[x][y] == 0 || res + 1 < vis[x][y])
            {
                vis[x][y] = res + 1;
                q.push(make_pair(make_pair(x, y), d));
            }
        }
        if (dof(px, py, d, ma, vis, 2))
        {
            int x = px + dd[d].first * 2;
            int y = py + dd[d].second * 2;
            if (vis[x][y] == 0 || res + 1 < vis[x][y])
            {
                vis[x][y] = res + 1;
                q.push(make_pair(make_pair(x, y), d));
            }
        }
        if (dof(px, py, d, ma, vis, 3))
        {
            int x = px + dd[d].first * 3;
            int y = py + dd[d].second * 3;
            if (vis[x][y] == 0 || res + 1 < vis[x][y])
            {
                vis[x][y] = res + 1;
                q.push(make_pair(make_pair(x, y), d));
            }
        }
        d = turn_l(d);
        if (dof(px, py, d, ma, vis, 1))
        {
            int x = px + dd[d].first;
            int y = py + dd[d].second;
            if (vis[x][y] == 0 || res + 2 < vis[x][y])
            {
                vis[x][y] = res + 2;
                q.push(make_pair(make_pair(x, y), d));
            }
        }
        if (dof(px, py, d, ma, vis, 2))
        {
            int x = px + dd[d].first * 2;
            int y = py + dd[d].second * 2;
            if (vis[x][y] == 0 || res + 2 < vis[x][y])
            {
                vis[x][y] = res + 2;
                q.push(make_pair(make_pair(x, y), d));
            }
        }
        if (dof(px, py, d, ma, vis, 3))
        {
            int x = px + dd[d].first * 3;
            int y = py + dd[d].second * 3;
            if (vis[x][y] == 0 || res + 2 < vis[x][y])
            {
                vis[x][y] = res + 2;
                q.push(make_pair(make_pair(x, y), d));
            }
        }
        d = turn_l(d);
        if (dof(px, py, d, ma, vis, 1))
        {
            int x = px + dd[d].first;
            int y = py + dd[d].second;
            if (vis[x][y] == 0 || res + 3 < vis[x][y])
            {
                vis[x][y] = res + 3;
                q.push(make_pair(make_pair(x, y), d));
            }
        }
        if (dof(px, py, d, ma, vis, 2))
        {
            int x = px + dd[d].first * 2;
            int y = py + dd[d].second * 2;
            if (vis[x][y] == 0 || res + 3 < vis[x][y])
            {
                vis[x][y] = res + 3;
                q.push(make_pair(make_pair(x, y), d));
            }
        }
        if (dof(px, py, d, ma, vis, 3))
        {
            int x = px + dd[d].first * 3;
            int y = py + dd[d].second * 3;
            if (vis[x][y] == 0 || res + 3 < vis[x][y])
            {
                vis[x][y] = res + 3;
                q.push(make_pair(make_pair(x, y), d));
            }
        }
        d = turn_l(d);
        if (dof(px, py, d, ma, vis, 1))
        {
            int x = px + dd[d].first;
            int y = py + dd[d].second;
            if (vis[x][y] == 0 || res + 2 < vis[x][y])
            {
                vis[x][y] = res + 2;
                q.push(make_pair(make_pair(x, y), d));
            }
        }
        if (dof(px, py, d, ma, vis, 2))
        {
            int x = px + dd[d].first * 2;
            int y = py + dd[d].second * 2;
            if (vis[x][y] == 0 || res + 2 < vis[x][y])
            {
                vis[x][y] = res + 2;
                q.push(make_pair(make_pair(x, y), d));
            }
        }
        if (dof(px, py, d, ma, vis, 3))
        {
            int x = px + dd[d].first * 3;
            int y = py + dd[d].second * 3;
            if (vis[x][y] == 0 || res + 2 < vis[x][y])
            {
                vis[x][y] = res + 2;
                q.push(make_pair(make_pair(x, y), d));
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    vector<vector<int>> ma(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<vector<int>>> dr(n, vector<vector<int>>(m, vector<int>(4, 0)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> ma[i][j];
    }
    int px, py, ex, ey;
    cin >> px >> py >> ex >> ey;
    char d;
    cin >> d;
    if (px == ex && py == ey){
        cout << 0 << endl;
        return 0;
    }
    int di;
    if (d == 'N')
        di = 0;
    else if (d == 'E')
        di = 1;
    else if (d == 'S')
        di = 2;
    else if (d == 'W')
        di = 3;
    bfs(px, py, ex, ey, di, 1, ma, vis, dr);
    cout << ((vis[ex][ey] != 0) ? vis[ex][ey] : -1) << endl;
    return 0;
}