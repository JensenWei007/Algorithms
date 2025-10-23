#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s = to_string(n);
    if (s[0] == '-')
    {
        cout << "-";
        s.erase(0, 1);
    }
    reverse(s.begin(), s.end());
    int r = stoi(s);
    cout << r << endl;

    return 0;
}