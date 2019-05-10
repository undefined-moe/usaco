#include<iostream>
using namespace std;
int r,map[2000][2000];
int main(){
    cin>>r;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=i;j++)
            cin>>map[i][j];
    for(int i=r-1;i>0;i--)
        for(int j=1;j<=i;j++)
            map[i][j]=map[i][j]+max(map[i+1][j],map[i+1][j+1]);
    cout<<map[1][1]<<endl;
    return 0;
}