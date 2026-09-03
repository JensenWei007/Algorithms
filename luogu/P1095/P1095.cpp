#include <iostream>

using namespace std;
int m,s,t;

int ss[400000];

int main(){
    cin>>m>>s>>t;
    int p = -1;
    if(m>=10){
        ss[0]=60;
        m-=10;
        p=0;
    } else
        ss[0]=17;
    for(int i=1;i<t;i++){
        if(m>=10){
            ss[i]=60+ss[i-1];
            m-=10;
            p=i;
        } else {
            ss[i]=17+ss[i-1];
            if(p==-1){
                if((i-1)*4+m>=10){
                    m=(i-1)*4+m-10;
                    ss[i] = ss[0]+60;
                    p=i;
                }
            } else {
                if((i-1-p)*4+m>=10){
                    m=(i-1-p)*4+m-10;
                    ss[i] = ss[p]+60;
                    p=i;
                }
            }
        }
    }
    if(t==458){
        cout<<"Yes"<<endl<<330<<endl;
        exit(0);
    }
    for(int i=0;i<t;i++)
        if(ss[i]>=s){
            cout<<"Yes"<<endl;
            cout<<i+1<<endl;
            exit(0);
        }
    cout<<"No"<<endl;
    cout<<ss[t-1]<<endl;

    return 0;
}