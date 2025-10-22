#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int r = 0;

    for (int i = 1; i <= n; i++)
    {
        string ss = to_string(i);
        int len = ss.length();
        char xx = '0' + x;
        for (int j = 0; j < len; j++)
            if (ss[j] == xx)
                r++;
    }
    cout << r << endl;

    return 0;
}