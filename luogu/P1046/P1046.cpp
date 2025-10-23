#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> p(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> p[i];
    }
    int s;
    cin >> s;
    s += 30;
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        if (p[i] <= s)
            sum++;
    }
    cout << sum << endl;

    return 0;
}