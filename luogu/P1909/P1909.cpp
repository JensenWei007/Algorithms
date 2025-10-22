#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double n;
    cin >> n;
    double a[3][2];
    for (int i = 0; i < 3; ++i)
    {
        cin >> a[i][0] >> a[i][1];
    }
    int a1 = ceil(n / a[0][0]) * a[0][1];
    int a2 = ceil(n / a[1][0]) * a[1][1];
    int a3 = ceil(n / a[2][0]) * a[2][1];
    int ans = min(a1, min(a2, a3));
    cout << ans << endl;
    return 0;
}