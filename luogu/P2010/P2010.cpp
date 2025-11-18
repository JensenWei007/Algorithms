#include <iostream>

using namespace std;

void add_year(string &s)
{
    if (s[3] == '9')
    {
        s[3] = '0';
        if (s[2] == '9')
        {
            s[2] = '0';
            if (s[1] == '9')
            {
                s[1] = '0';
                s[0] = s[0] + 1;
            }
            else
            {
                s[1] = s[1] + 1;
            }
        }
        else
        {
            s[2] = s[2] + 1;
        }
    }
    else
    {
        s[3] = s[3] + 1;
    }
}

bool is_done(string s1, string s2)
{
    int d1 = stoi(s1.substr(0, 4));
    int d2 = stoi(s2.substr(0, 4));
    if (d1 == 9999)
        return true;
    if (d1 > d2)
        return true;
    else if (d1 < d2)
    {
        return false;
    }
    else
    {
        int dd1 = stoi(s1.substr(4, 2));
        int dd2 = stoi(s2.substr(4, 2));
        if (dd1 > dd2)
            return true;
        else if (dd1 < dd2)
        {
            return false;
        }
        else
        {
            int fd1 = stoi(s1.substr(6, 2));
            int fd2 = stoi(s2.substr(6, 2));
            if (fd1 > fd2)
                return true;
            else
            {
                return false;
            }
        }
    }
    return false;
}

bool check(string s, string f)
{
    s[4] = s[3];
    s[5] = s[2];
    s[6] = s[1];
    s[7] = s[0];

    int y = stoi(s.substr(0, 4));
    // cout << s << endl;

    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
    {
        if (s[4] == '0' && s[5] == '2')
        {
            int d = (s[6] - '0') * 10 + s[7] - '0';
            if (d > 0 && d <= 29)
            {
                if (is_done(s, f))
                    return false;
                return true;
            }
        }
        if (s[4] == '0' && (s[5] == '1' || s[5] == '3' || s[5] == '5' || s[5] == '7' || s[5] == '8'))
        {
            int d = (s[6] - '0') * 10 + s[7] - '0';
            if (d > 0 && d <= 31)
            {
                if (is_done(s, f))
                    return false;
                return true;
            }
        }
        if (s[4] == '0' && (s[5] == '4' || s[5] == '6' || s[5] == '9'))
        {
            int d = (s[6] - '0') * 10 + s[7] - '0';
            if (d > 0 && d <= 30)
            {
                if (is_done(s, f))
                    return false;
                return true;
            }
        }
        if (s[4] == '1' && (s[5] == '0' || s[5] == '2'))
        {
            int d = (s[6] - '0') * 10 + s[7] - '0';
            if (d > 0 && d <= 31)
            {
                if (is_done(s, f))
                    return false;
                return true;
            }
        }
        if (s[4] == '1' && s[5] == '1')
        {
            int d = (s[6] - '0') * 10 + s[7] - '0';
            if (d > 0 && d <= 30)
            {
                if (is_done(s, f))
                    return false;
                return true;
            }
        }
    }
    else
    {
        if (s[4] == '0' && s[5] == '2')
        {
            int d = (s[6] - '0') * 10 + s[7] - '0';
            if (d > 0 && d <= 28)
            {
                if (is_done(s, f))
                    return false;
                return true;
            }
        }
        if (s[4] == '0' && (s[5] == '1' || s[5] == '3' || s[5] == '5' || s[5] == '7' || s[5] == '8'))
        {
            int d = (s[6] - '0') * 10 + s[7] - '0';
            if (d > 0 && d <= 31)
            {
                if (is_done(s, f))
                    return false;
                return true;
            }
        }
        if (s[4] == '0' && (s[5] == '4' || s[5] == '6' || s[5] == '9'))
        {
            int d = (s[6] - '0') * 10 + s[7] - '0';
            if (d > 0 && d <= 30)
            {
                if (is_done(s, f))
                    return false;
                return true;
            }
        }
        if (s[4] == '1' && (s[5] == '0' || s[5] == '2'))
        {
            int d = (s[6] - '0') * 10 + s[7] - '0';
            if (d > 0 && d <= 31)
            {
                if (is_done(s, f))
                    return false;
                return true;
            }
        }
        if (s[4] == '1' && s[5] == '1')
        {
            int d = (s[6] - '0') * 10 + s[7] - '0';
            if (d > 0 && d <= 30)
            {
                if (is_done(s, f))
                    return false;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    string d1, d2;
    cin >> d1 >> d2;

    int r = 0;
    while (!is_done(d1, d2))
    {
        if (check(d1, d2))
        {
            r++;
            // cout << "rrrrrrrrrrrrrr" << d1 << endl;
        }
        add_year(d1);
        // cout << "addyead " << d1 << " ff " << d2 << endl;
    }
    cout << r << endl;

    return 0;
}