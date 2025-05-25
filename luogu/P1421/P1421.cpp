#include <iostream>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    double r = a * 1.0 + b*0.1;
    cout<< (int)(r/1.9) << endl;
    return 0;
}