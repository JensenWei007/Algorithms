#include <iostream>
#include <queue>
#include <string.h>
#include <map>

using namespace std;

int ma[9];
string myends="123804765";
string s = "";
int zx,zy;
int mx[4]={-1,0,1,0};
int my[4]={0,-1,0,1};
map<string, int> qc;

struct nd{
    string m;
    int x, y;
    int step;
};

void bfs(){
    queue<nd> q;
    q.push((nd){s, zx, zy, 0});
    qc[s]=1;
    while(!q.empty()){
        string m = q.front().m;
        int x = q.front().x;
        int y = q.front().y;
        int step = q.front().step;
        q.pop();
        if(m==myends){
            cout<<step<<endl;
            exit(0);
        }
        for(int i=0;i<4;i++){
            int xx = x+mx[i];
            int yy = y+my[i];
            if(xx<0||xx>2||yy<0||yy>2)
                continue;
            string mm = m;
            mm[x*3+y]=mm[xx*3+yy];
            mm[xx*3+yy]='0';
            if(qc[mm]==0){
                q.push((nd){mm, xx, yy, step+1});
                qc[mm]=1;
            }
        }
    }
}

int main(){
    cin>>s;
    for(int i=0;i<9;i++){
        if(s[i]=='0'){
            zx=i/3;
            zy=i%3;
            break;
        }
    }
    bfs();
    return 0;
}