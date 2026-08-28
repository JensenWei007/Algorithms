#include <iostream>

using namespace std;

int r;
int rr[1001][1001];

int dp[1001][1001];

int main(){
    cin>>r;
    for(int i=0;i<r;i++)
        for(int j=0;j<i+1;j++)
            cin>>rr[i][j];
    
    dp[0][0]=rr[0][0];
    for(int i=1;i<r;i++)
        dp[i][0]=rr[i][0]+dp[i-1][0];
    for(int i=1;i<r;i++){
        for(int j=1;j<i+1;j++){
            dp[i][j]=max(dp[i-1][j], dp[i-1][j-1])+rr[i][j];
        }
    }

    int ans = 0;
    for(int i=0;i<r;i++)
        if(ans<dp[r-1][i])
            ans = dp[r-1][i];
    cout<<ans<<endl;
    
    return 0;
}