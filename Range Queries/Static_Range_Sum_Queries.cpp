#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int i,j;
    int n,q;
    cin>>n>>q;
    ll a[n],pref[n+1]={0};
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=1;i<=n;i++){
        pref[i]=pref[i-1]+a[i-1];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<pref[r]-pref[l-1]<<'\n';
    }
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}