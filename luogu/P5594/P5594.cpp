#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> p(n, vector<int>(m, 0));
    vector<set<int>> r(k, set<int>());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            r[t - 1].insert(j);
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << r[i].size() << " ";
    }
    cout << endl;

    return 0;
}