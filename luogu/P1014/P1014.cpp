#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int s = 1;
    long long sum = 0;

    while (sum + s < n)
    {
        sum += s;
        s++;
    }

    if (s % 2 == 0)
    {
        int l = n - sum;
        int r = s + 1 - l;
        cout << l << "/" << r << endl;
    }
    else
    {
        int l = n - sum;
        int r = s + 1 - l;
        cout << r << "/" << l << endl;
    }

    return 0;
}