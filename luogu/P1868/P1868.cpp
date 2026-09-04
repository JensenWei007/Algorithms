#include <iostream>
#include <algorithm>

using namespace std;
int n;

struct nd{
    int x;
    int y;
};

nd nn[200000];

int maxy;

bool cmp(nd xf, nd yf){
    return xf.x==yf.x?xf.y<yf.y:xf.x<yf.x;
}

long long dp[4000000];

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nn[i].x>>nn[i].y;
        maxy = max(maxy, nn[i].y);
    }
    sort(nn, nn+n, cmp);

    int j = 0;
    for(int i=0;i<=maxy;i++){
        dp[i] = max(dp[i], dp[i-1]);
        while(nn[j].x==i && j<n){
            dp[nn[j].y] = max(dp[nn[j].y], dp[nn[j].x-1]+nn[j].y-nn[j].x+1);
            j++;
        }
    }
    
    long long ans = 0;
    for(int i=0;i<=maxy;i++)
        if(dp[i]>ans)
            ans = dp[i];
    cout<<ans<<endl;
    return 0;
}