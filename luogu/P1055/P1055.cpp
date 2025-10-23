#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int sum = 0;
    sum += (s[0] - '0');
    sum += (s[2] - '0') * 2;
    sum += (s[3] - '0') * 3;
    sum += (s[4] - '0') * 4;
    sum += (s[6] - '0') * 5;
    sum += (s[7] - '0') * 6;
    sum += (s[8] - '0') * 7;
    sum += (s[9] - '0') * 8;
    sum += (s[10] - '0') * 9;
    sum = sum % 11;
    if (sum != 10)
    {
        if (s[12] == '0' + sum)
            cout << "Right" << endl;
        else
        {
            s[12] = '0' + sum;
            cout << s << endl;
        }
    }
    else
    {
        if (s[12] == 'X')
            cout << "Right" << endl;
        else
        {
            s[12] = 'X';
            cout << s << endl;
        }
    }

    return 0;
}