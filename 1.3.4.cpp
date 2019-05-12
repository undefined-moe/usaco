#include<iostream>
#include<vector>
using namespace std;
int n,t,ans;
vector<int> a;
bool p[10];
bool check(int n,int len){
    int cnt=0;
    while(n){
        if (!p[n%10]) return false;
        n/=10;
        cnt++;
    }
    return cnt==len;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        a.push_back(t);
        p[t]=true;
    }
    for(int l1c1:a)
        for(int l1c2:a)
            for(int l1c3:a)
                for(int l2c1:a)
                    for(int l2c2:a)
                        if (check((l1c1*100+l1c2*10+l1c3)*l2c1,3))
                            if (check((l1c1*100+l1c2*10+l1c3)*l2c2,3))
                                if ((check((l1c1*100+l1c2*10+l1c3)*(l2c1*10+l2c2),4)))
                                    ans++;
    cout<<ans<<endl;
}