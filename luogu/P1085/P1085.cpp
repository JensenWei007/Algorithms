#include <iostream>

using namespace std;

int main() {
    int a[7][2];
    for(int i=0;i<7;i++)
        for(int j=0;j<2;j++)
            cin>>a[i][j];
    int max = 0;
    int maxi=-1;
    for(int i=0;i<7;i++)
    {
        int temp = a[i][0]+a[i][1];
        if (temp>8&&temp>max){
            max=temp;
            maxi = i;
        }
    }
    cout<<maxi+1<<endl;;

    return 0;
}