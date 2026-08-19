#include <iostream>
#include <algorithm>

using namespace std;

long long need[41];
long long ans;
long long mon;
long long cnta, cntb;
long long may1[1<<21];
long long may2[1<<21];
int n;

void dfs(int d, long long sum){
    if(sum>mon)
        return;
    if(d==n/2+1){
        may1[cnta++]=(mon-sum);
        return;
    }
    dfs(d+1, sum);
    dfs(d+1, sum+need[d]);
}

void dfsa(int d, long long sum){
    if(sum>mon)
        return;
    if(d==n+1){
        may2[cntb++]=(sum);
        return;
    }
    dfsa(d+1, sum);
    dfsa(d+1, sum+need[d]);
}

int main(){
    cin>>n;
    cin>>mon;
    for(int i=0;i<n;i++)
        cin>>need[i];

    dfs(0, 0);
    dfsa(n/2+1, 0);

    sort(may2, may2+cntb);
    //for(int i=0;i<cnta;i++)cout<<may1[i]<<" ";cout<<endl;
    //for(int i=0;i<cntb;i++)cout<<may2[i]<<" ";cout<<endl;
    
    for(int i=0;i<cnta;i++){
        long long may = may1[i];
        long long cnt = upper_bound(may2, may2+cntb, may)-may2;
        ans+=cnt;
        //cout<<ans<<endl;
    }
    cout<<ans/2<<endl;
    return 0;
}