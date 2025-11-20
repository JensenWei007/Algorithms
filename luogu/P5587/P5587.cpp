#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    vector<string> f1;
    vector<string> f2;

    while (s != "EOF")
    {
        f1.push_back(s);
        getline(cin, s);
    }
    getline(cin, s);
    while (s != "EOF")
    {
        f2.push_back(s);
        getline(cin, s);
    }
    int time;
    cin >> time;

    for (int i = 0; i < f2.size(); i++)
    {
        string f = f2[i];
        stack<char> s;
        for (int j = 0; j < f.length(); j++)
        {
            if (f[j] == '<')
            {
                if (!s.empty())
                {
                    s.pop();
                }
                continue;
            }
            s.push(f[j]);
        }
        string ff;
        while (!s.empty())
        {
            ff.push_back(s.top());
            s.pop();
        }
        string fff;
        for (int ij = ff.length() - 1; ij >= 0; ij--)
            fff.push_back(ff[ij]);
        f2.erase(f2.begin() + i);
        f2.insert(f2.begin() + i, fff);
    }
    for (int i = 0; i < f1.size(); i++)
    {
        string f = f1[i];
        stack<char> s;
        for (int j = 0; j < f.length(); j++)
        {
            if (f[j] == '<')
            {
                if (!s.empty())
                {
                    s.pop();
                }
                continue;
            }
            s.push(f[j]);
        }
        string ff;
        while (!s.empty())
        {
            ff.push_back(s.top());
            s.pop();
        }
        string fff;
        for (int ij = ff.length() - 1; ij >= 0; ij--)
            fff.push_back(ff[ij]);
        f1.erase(f1.begin() + i);
        f1.insert(f1.begin() + i, fff);
    }

    int right = 0;
    for (int i = 0; i < min(f1.size(), f2.size()); i++)
    {
        string s1 = f1[i];
        string s2 = f2[i];
        int len = min(s1.length(), s2.length());
        for (int j = 0; j < len; j++)
        {
            if (s1[j] == s2[j])
            {
                right++;
            }
        }
    }
    double rr = (double)right / (double)time * 60;

    cout << std::round(rr) << endl;

    return 0;
}