#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void tou(string &s)
{
    for (int i = 0; i < s.length(); i++)
        if (s[i] != ' ')
            s[i] = toupper(s[i]);
}

int main()
{
    string s;
    string p;
    getline(cin, s);
    getline(cin, p);
    p[p.length() + 1] = ' ';
    tou(s);
    tou(p);
    int sum = 0;
    int pos = -1;

    int start = 0;
    int end = p.find(s);

    if (end == -1)
    {
        cout << -1 << endl;
        return 0;
    }

    if (end == 0)
    {
        if (p[end + s.length()] == ' ')
        {
            pos = end;
            sum++;
            end = p.find(s, end + s.length());
        }
    }

    while (end >= 0)
    {
        if ((p[end - 1] == ' ') && (p[end + s.length()] == ' '))
        {
            if (pos == -1)
                pos = end;
            sum++;
        }
        end = p.find(s, end + s.length());
    }
    if (pos == -1)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << sum << " " << pos << endl;

    return 0;
}