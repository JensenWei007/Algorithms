#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    long long a1 = a;
    long long d = b - a;
    long long n = c;
    long long an = a1 + (n - 1) * d;
    long long res = n * (a1 + an) / 2;

    cout << res << endl;

    return 0;
}