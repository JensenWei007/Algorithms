#include <iostream>

using namespace std;

int nn[360];
int mm[5];

int t;
int dp[41][41][41][41];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>nn[i];
    for(int i=0;i<m;i++){
        cin>>t;
        mm[t]++;
    }

    dp[0][0][0][0]=nn[0];
    for(int i=0;i<=mm[1];i++){
        for(int j=0;j<=mm[2];j++){
            for(int k=0;k<=mm[3];k++){
                for(int v=0;v<=mm[4];v++){
                    int s = i+2*j+3*k+4*v;
                    if(i>0)
                        dp[i][j][k][v] = max(dp[i][j][k][v], dp[i-1][j][k][v]+nn[s]);
                    if(j>0)
                        dp[i][j][k][v] = max(dp[i][j][k][v], dp[i][j-1][k][v]+nn[s]);
                    if(k>0)
                        dp[i][j][k][v] = max(dp[i][j][k][v], dp[i][j][k-1][v]+nn[s]);
                    if(v>0)
                        dp[i][j][k][v] = max(dp[i][j][k][v], dp[i][j][k][v-1]+nn[s]);
                }
            }
        }
    }
    cout<<dp[mm[1]][mm[2]][mm[3]][mm[4]]<<endl;

    return 0;
}