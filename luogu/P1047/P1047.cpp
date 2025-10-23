#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int l, m;
    cin >> l >> m;
    int sum = l + 1;
    vector<bool> f(l, 1);
    vector<vector<int>> d(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        for (int j = l; j <= r; j++)
            if (f[j] == true)
            {
                f[j] = false;
                sum--;
            }
    }
    cout << sum << endl;

    return 0;
}