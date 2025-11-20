#include <iostream>
#include <vector>

using namespace std;
long r[1011];

long check(int s)
{
    if (r[s] != 0)
        return r[s];
    r[s] = 1;
    for (int i = s / 2; i >= 1; i--)
    {
        r[s] += check(i);
    }
    return r[s];
}

int main()
{
    int x;
    cin >> x;
    r[1] = 1;
    cout << check(x) << endl;
    return 0;
}