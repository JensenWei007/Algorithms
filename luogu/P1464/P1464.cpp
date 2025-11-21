#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<long long>>> map;

void print(long long a, long long b, long long c, long long r)
{
    cout << "w(" << a << ", " << b << ", " << c << ") = " << r << endl;
}

long long w(long long a, long long b, long long c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    }
    if (map[a][b][c] != 0)
        return map[a][b][c];
    if (a < b && b < c)
    {
        map[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return map[a][b][c];
    }
    map[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return map[a][b][c];
}

int main()
{
    long long a, b, c;
    map = vector<vector<vector<long long>>>(21, vector<vector<long long>>(21, vector<long long>(21, 0)));
    while (1)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
        {
            return 0;
        }
        print(a, b, c, w(a, b, c));
    }

    return 0;
}