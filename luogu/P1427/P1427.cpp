#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> p;

    int c;
    cin >> c;

    while (c != 0)
    {
        p.push_back(c);
        cin >> c;
    }
    for (int i = p.size() - 1; i > 0; i--)
        cout << p[i] << " ";
    cout << p[0] << endl;

    return 0;
}