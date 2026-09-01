#include <iostream>
#include <cstring>

using namespace std;

int n;
int aa[101];
int dp1[110];
int dp2[110];

int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>aa[i];

    for(int i=0;i<n;i++)dp1[i]=1;
    for(int i=0;i<n;i++)dp2[i]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            dp1[i]=max(dp1[i], (dp1[j]+1)*(aa[i]>aa[j]));
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            dp2[i]=max(dp2[i], (dp2[j]+1)*(aa[i]>aa[j]));
        }
    }
    int maxf = 0;
    for(int i=0;i<n;i++)
        maxf = max(maxf, dp1[i]+dp2[i]-1);

    cout<<n-maxf<<endl;
    return 0;
}