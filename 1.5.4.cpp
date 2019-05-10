#include<iostream>
using namespace std;
bool map[20][20],pd[20];
int pos[20],n,anscnt;
bool check(int x,int y){
    for(int i=1;i<x;i++){
        if (pos[i]+i==x+y) return false;
        if (i-pos[i]==x-y) return false;
    }
    return true;
}
void search(int t){
    if (t>n){
        anscnt++;
        if (anscnt<=3){
            for(int i=1;i<=n;i++)
                cout<<pos[i]<<' ';
            cout<<endl;
        }
    }
    for(int i=1;i<=n;i++)
        if (!pd[i]) if (check(t,i)){
            pos[t]=i;
            pd[i]=true;
            search(t+1);
            pd[i]=false;
        }
}
int main(){
    cin>>n;
    search(1);
    cout<<anscnt<<endl;
}