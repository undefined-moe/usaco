#include<iostream>
using namespace std;
int n;
struct d{
    char a[11][11];
}map,target,temp;
bool cmp(d a,d b){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if (a.a[i][j]!=b.a[i][j]) return false;
    return true;
}
void print(d a){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<a.a[i][j];
        cout<<endl;
    }
}
d rotate90(d from){
    d temp;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            temp.a[j][n-i+1]=from.a[i][j];
    return temp;
}
d mirror(d from){
    d temp;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            temp.a[i][j]=from.a[i][n-j+1];
    return temp;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>map.a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>target.a[i][j];
    if (cmp(target,temp)){
        cout<<6<<endl;
        return 0;
    }
    temp=rotate90(map);
    if (cmp(target,temp)){
        cout<<1<<endl;
        return 0;
    }
    temp=rotate90(temp);
    if (cmp(target,temp)){
        cout<<2<<endl;
        return 0;
    }
    temp=rotate90(temp);
    if (cmp(target,temp)){
        cout<<3<<endl;
        return 0;
    }
    temp=mirror(map);
    if (cmp(target,temp)){
        cout<<4<<endl;
        return 0;
    }
    temp=rotate90(temp);
    if (cmp(target,temp)){
        cout<<5<<endl;
        return 0;
    }
    temp=rotate90(temp);
    if (cmp(target,temp)){
        cout<<5<<endl;
        return 0;
    }
    temp=rotate90(temp);
    if (cmp(target,temp)){
        cout<<5<<endl;
        return 0;
    }
    cout<<7<<endl;
    return 0;
}