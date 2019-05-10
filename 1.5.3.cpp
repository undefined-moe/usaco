#include<iostream>
#include<cmath>
using namespace std;
int n,num[10];
int prs[7]={0,1,2,3,5,7,9};
bool prime(int n){
    if (n<2) return false;
    if (n==2) return true;
    for(int i=2;i<=floor(sqrt(n));i++)
        if (n%i==0) return false;
    return true;
}
int make(int pos){
    int t=0;
    for(int i=1;i<=pos;i++)
        t=t*10+num[i];
    return t;
}
void search(int pos){
    if (pos>n){
        cout<<make(pos-1)<<endl;
        return;
    }
    for(int i=1;i<=6;i++){
        num[pos]=prs[i];
        if (prime(make(pos)))
            search(pos+1);
    }
}
int main(){
    cin>>n;
    search(1);
}