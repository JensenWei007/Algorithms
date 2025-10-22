#include <iostream>

using namespace std;

int main()
{
    int k;
    cin >> k;

    double n = 0;
    double sum = 0;

    while (sum - k <= 0)
    {
        sum += (1 / (++n));
    }
    cout << n << endl;

    return 0;
}
