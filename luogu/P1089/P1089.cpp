#include <iostream>

using namespace std;

int main()
{
    int n[12];
    for (int i = 0; i < 12; i++)
    {
        cin >> n[i];
    }
    int left = 0;
    double cun = 0;
    for (int i = 0; i < 12; i++)
    {
        left += 300;
        left -= n[i];
        if (left < 0)
        {
            cout << -1 * (i + 1) << endl;
            return 0;
        }
        cun += 100 * (int)(left / 100);
        left %= 100;
    }
    cout << cun * 1.2 + left << endl;
    return 0;
}