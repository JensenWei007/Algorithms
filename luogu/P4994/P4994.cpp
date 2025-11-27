#include <iostream>

using namespace std;

int main()
{
    int m;
    cin >> m;

    int f1, f2, f3;
    f1 = 0;
    f2 = 1;
    f3 = 1;

    int n = 1;

    while (1)
    {
        f1 = f2 % m;
        f2 = f3 % m;
        f3 = (f1 + f2) % m;
        if (f1 == 0 && f2 == 1)
        {
            cout << n << endl;
            return 0;
        }
        n++;
    }

    return 0;
}