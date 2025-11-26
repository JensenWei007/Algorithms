#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> f(k, 0);
    f[0] = 1;
    for (int i = 1; i < k; i++)
    {
        f[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            f[i] += f[j];
            f[i] %= 100003;
        }
    }
    if (n <= k)
    {
        cout << f[n - 1] << endl;
        return 0;
    }
    for (int i = k; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < k; j++)
        {
            temp += f[j];
            temp %= 100003;
        }
        f.erase(f.begin());
        f.push_back(temp);
    }
    cout << f[k - 1] << endl;

    return 0;
}