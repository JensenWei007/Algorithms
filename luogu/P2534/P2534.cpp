#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <climits>

using namespace std;

int n;
int mm[17];
int sm[17];
int ans = 0;
int val = 0;

int isen(){
    for(int i=0;i<n-1;i++)
        if(mm[i]>mm[i+1])
            return 0;
    return 1;
}

int eva(){
    int ret=0;
    for(int i=0;i<n-1;i++)
        if(abs(mm[i]-mm[i+1])!=1)
            ret++;
    return ret;
}

void dfs(int step){
    if(step+val>ans)
        return;
    if(isen()){
        ans=step;
        return;
    }
    for(int i=1;i<n;i++){
        if(i!=n-1)
            val=val-(abs(mm[i]-mm[i+1])!=1)+(abs(mm[0]-mm[i+1])!=1);
        reverse(mm, mm+i+1);
        dfs(step+1);
        reverse(mm, mm+i+1);
        if(i!=n-1)
            val=val+(abs(mm[i]-mm[i+1])!=1)-(abs(mm[0]-mm[i+1])!=1);
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        mm[i]=m;
        sm[i]=m;
    }
    sort(sm, sm+n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mm[i]==sm[j]){
                mm[i]=j+1;
                sm[j]=0;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
        sm[i]=i+1;
    ans=2*n;
    val = eva();
    dfs(0);
    cout<<ans<<endl;
    return 0;
}