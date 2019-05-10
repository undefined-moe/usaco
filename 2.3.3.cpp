#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int n;
int op[10];
bool iszero(){
    int a,b;
    queue<int> ops;
    stack<int> q,qr;
    q.push(1);
    /*
    for(int i=2;i<=n;i++)
        cout<<op[i-1]<<' ';
    cout<<endl;
    */
    for(int i=2;i<=n;i++){
        if (op[i-1]==3){
            a=q.top();
            q.pop();
            q.push(a*10+i);
        }else{
            q.push(i);
            ops.push(op[i-1]);
        }
    }
    while(!q.empty()){
        a=q.top();
        q.pop();
        qr.push(a);
    }
    a=qr.top();
    qr.pop();
    while(!qr.empty()){
        b=ops.front();
        if (b==1){
            a+=qr.top();
            qr.pop();
        }else{
            a-=qr.top();
            qr.pop();
        }
        ops.pop();
    }
    return a==0;
}
void print(){
    cout<<1;
    for(int i=2;i<=n;i++){
        if (op[i-1]==1) cout<<'+';
        if (op[i-1]==2) cout<<'-';
        if (op[i-1]==3) cout<<' ';
        cout<<i;
    }
    cout<<endl;
}
void search(int pos){
    if (pos>n){
        if (iszero()) print();
        return;
    }
    op[pos-1]=3;
    search(pos+1);
    op[pos-1]=1;
    search(pos+1);
    op[pos-1]=2;
    search(pos+1);
}
int main(){
    cin>>n;
    op[1]=1;
    search(2);
}