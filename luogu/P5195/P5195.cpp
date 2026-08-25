#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
int w, h;
int ma[1001][1001];
int vis[1001][1001][4];
int mx[4] = {-1, 0, 1, 0};
int my[4] = {0, -1, 0, 1};

int startx, starty;
int endx, endy;

struct nd
{
    int x, y, step, have;
};

int main()
{
    cin >> w >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> ma[i][j];
            if (ma[i][j] == 2)
            {
                startx = i;
                starty = j;
            }
            if (ma[i][j] == 3)
            {
                endx = i;
                endy = j;
            }
        }
    }

    queue<nd> q1;
    queue<nd> q2;
    q1.push((nd){startx, starty, 0, 0});
    q2.push((nd){endx, endy, 0, 0});
    vis[startx][starty][0] = 1;
    vis[endx][endy][3] = 1;
    int s1 = 0;
    int s2 = 0;
    while (!q1.empty() || !q2.empty())
    {
        if (s1 <= s2 && !q1.empty())
        {
            int x = q1.front().x;
            int y = q1.front().y;
            int step = q1.front().step;
            int have = q1.front().have;
            q1.pop();
            if (have && vis[x][y][2])
            {
                cout << step + vis[x][y][2] << endl;
                exit(0);
            }
            if (vis[x][y][3])
            {
                cout << step + vis[x][y][3] << endl;
                exit(0);
            }
            for (int i = 0; i < 4; i++)
            {
                int X = x + mx[i];
                int Y = y + my[i];
                int ha = have;
                if (X < 0 || X > h - 1 || Y < 0 || Y > w - 1)
                    continue;
                if (ma[X][Y] == 1)
                    continue;
                if (!ha && ma[X][Y] == 3)
                    continue;
                if (ma[X][Y] == 4)
                    ha = 1;
                if (vis[X][Y][ha] != 0)
                    continue;
                vis[X][Y][ha] = step + 1;
                q1.push((nd){X, Y, step + 1, ha});
                s1++;
            }
        }
        else if (s2 < s1 && !q2.empty())
        {
            int x = q2.front().x;
            int y = q2.front().y;
            int step = q2.front().step;
            int have = q2.front().have;
            q2.pop();
            if (have && vis[x][y][0])
            {
                cout << step + vis[x][y][0] << endl;
                exit(0);
            }
            if (vis[x][y][1])
            {
                cout << step + vis[x][y][1] << endl;
                exit(0);
            }
            for (int i = 0; i < 4; i++)
            {
                int X = x + mx[i];
                int Y = y + my[i];
                int ha = have;
                if (X < 0 || X > h - 1 || Y < 0 || Y > w - 1)
                    continue;
                if (ma[X][Y] == 1)
                    continue;
                if (ma[X][Y] == 4)
                    ha = 1;
                if (vis[X][Y][2 + ha] != 0)
                    continue;
                vis[X][Y][2 + ha] = step + 1;
                q2.push((nd){X, Y, step + 1, ha});
                s2++;
            }
        }
    }
    return 0;
}