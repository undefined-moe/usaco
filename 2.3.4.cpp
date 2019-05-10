#include<iostream>
using namespace std;
int v,n,a[30];
void qsort(int l,int r){
    int i=l,j=r,mid=a[(l+r)/2];
    do{
        while (a[i]>mid) i++;
        while (a[j]<mid) j--;
        if (i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if (i<r) qsort(i,r);
    if (j>l) qsort(l,j);
}
int mem[30][10010];
int search(int pos,int n){
    if (pos==v){
        if (n%a[pos]==0) return 1;
        return 0;
    }
    if (n==0) return 1;
    if (mem[pos][n]) return mem[pos][n];
    int mx=n/a[pos],ans=0;
    for(int i=0;i<=mx;i++)
        ans+=search(pos+1,n-i*a[pos]);
    mem[pos][n]=ans;
    return ans;
}
int main(){
    cin>>v>>n;
    for(int i=1;i<=v;i++)
        cin>>a[i];
    qsort(1,v);
    cout<<search(1,n)<<endl;
    return 0;
}