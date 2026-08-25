#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#include <string>

using namespace std;

int tm[10][5][5];
int mx[8] = {-2,-1,-2,-1,2,1,1,2};
int my[8] = {1,2,-1,-2,1,2,-2,-1};

struct nd{
    int m[5][5];
    int step;
    int x,y;
    nd(const int a[5][5] = nullptr, int s = 0, int xx = 0, int yy = 0) : step(s) {
        memcpy(m, a, sizeof(m));
        x=xx;
        y=yy;
    }
    bool operator<(const nd& b) const {
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++) {
                if(m[i][j] != b.m[i][j])
                    return m[i][j] < b.m[i][j];
            }
        return false;
    }
};

int eee[5][5] = {{1,1,1,1,1},{0,1,1,1,1},{0,0,2,1,1},{0,0,0,0,1},{0,0,0,0,0}};

nd myend(eee, 0, 2, 2);

map<nd, int> mp;
map<nd, int> nmp;

bool isEnd(const nd& u) {
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(u.m[i][j] != eee[i][j])
                return false;
    return true;
}

void bbfs(){
    queue<nd> q;
    q.push(myend);
    nmp[q.front()] = 0;
    
    while(!q.empty()){
        nd u = q.front();
        q.pop();
        
        if(u.step > 7) continue;
        
        for(int i=0;i<8;i++){
            int xx = u.x + mx[i];
            int yy = u.y + my[i];
            if(xx < 0 || xx > 4 || yy < 0 || yy > 4)
                continue;
            
            nd uu = u;
            swap(uu.m[u.x][u.y], uu.m[xx][yy]);
            uu.step++;
            uu.x = xx;
            uu.y = yy;
            
            if(nmp.find(uu) == nmp.end()) {
                nmp[uu] = uu.step;
                q.push(uu);
            }
        }
    }
}

int bfs(int index){
    queue<nd> q;
    int startX = -1, startY = -1;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(tm[index][i][j]==2){
                startX = i;
                startY = j;
                break;
            }
    
    q.push(nd(tm[index], 0, startX, startY));
    mp.clear();
    mp[q.front()] = 1;
    
    while(!q.empty()){
        nd u = q.front();
        q.pop();
        
        if(u.step > 7) continue;
        
        if(nmp.find(u) != nmp.end()) {
            return u.step+nmp[u];
        }
        
        for(int i=0;i<8;i++){
            int xx = u.x + mx[i];
            int yy = u.y + my[i];
            if(xx < 0 || xx > 4 || yy < 0 || yy > 4)
                continue;
            
            nd uu = u;
            swap(uu.m[u.x][u.y], uu.m[xx][yy]);
            uu.step++;
            uu.x = xx;
            uu.y = yy;
            
            if(mp.find(uu) == mp.end()) {
                mp[uu] = 1;
                q.push(uu);
            }
        }
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        for(int i = 0; i < 5; i++){
            string s;
            cin >> s;
            for(int j = 0; j < 5; j++)
                if(s[j] == '*')
                    tm[k][i][j] = 2;
                else
                    tm[k][i][j] = s[j] - '0';
        }
    }
    bbfs();
    for(int i = 0; i < t; i++) {
        int result = bfs(i);
        cout << result << endl;
    }
    return 0;
}