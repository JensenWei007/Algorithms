#include <iostream>
#include <algorithm>

using namespace std;

int aa[100100];
int ll[100100];
int dd;
int don;
int cnt;
int now;

bool com(int a, int b){
    return a>b;
}

bool comb(int a, int b){
    return a<b;
}

int main(){
    while(cin>>dd){
        aa[cnt++]=dd;
    }

    ll[now++]=aa[0];
    for(int i=1;i<cnt;i++){
        if(aa[i]<=ll[now-1]){
            ll[now++]=aa[i];
        } else {
            int* p = upper_bound(ll, ll+now, aa[i], com);
            *p = aa[i];
        }
    }
    cout<<now<<endl;

    now = 0;
    ll[now++]=aa[0];
    for(int i=1;i<cnt;i++){
        if(aa[i]>ll[now-1]){
            ll[now++]=aa[i];
        } else {
            int* p = lower_bound(ll, ll+now, aa[i], comb);
            *p = aa[i];
        }
    }
    cout<<now<<endl;
    return 0;
}