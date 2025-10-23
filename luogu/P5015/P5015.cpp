#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    char s[6];
    memset(s, ' ', 6);
    int sum = 0;
    cin.getline(s, 6, '\0');
    for (int i = 0; i < 6; i++)
        if (s[i] != ' ' && s[i] != '\n' && s[i] != '\0')
            sum++;
    cout << sum << endl;
    return 0;
}