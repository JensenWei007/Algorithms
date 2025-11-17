#include <iostream>
#include <vector>

using namespace std;

int com(string a, string b) {
    if (a.length()<b.length()) {
        for(int i=a.length();i<b.length();i++)
            a.push_back(a[a.length()-1]);
    } else if (a.length()>b.length()){
        for(int i=b.length();i<a.length();i++)
            b.push_back(b[b.length()-1]);
    }
    int len = a.length();
    for(int i=0;i<len;i++){
        if(a[i]>b[i]){
            return 1;
        } else if(a[i]<b[i]){
            return 2;
        }
    }
    return 3;
}

int main(){
    int n;
    cin>>n;

    vector<string> d(n);
    for(int i=0;i<n;i++)
        cin>>d[i];

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if (com(d[i], d[j])==2){
                string temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }

    for(int i=0;i<n;i++) {
        cout<<d[i];
    }

    return 0;
}
