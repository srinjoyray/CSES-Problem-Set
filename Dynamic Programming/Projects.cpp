#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<ll, ll>	pl;
#define F first
#define S second
const int N=1e6+10;
 
void solve(){
    int i,j;
    int n;
    cin>>n;
    ll a[n],b[n],p[n],last,pos,ans=0;
    set<pair<pl,ll>> se;
    for(i=0;i<n;i++){
        cin>>a[i]>>b[i]>>p[i];
    }
    map<ll,ll> dp;
    multiset<ll> s1;
    for(i=0;i<n;i++){
        se.insert({{b[i],a[i]},p[i]});
    }

    last=0;
    s1.insert(0);
    for(auto it : se){
        dp[it.F.F]=dp[last];
        pos=*(--s1.lower_bound(it.F.S));
        dp[it.F.F]=max(dp[it.F.F],dp[pos]+it.S);
 
        s1.insert(it.F.F);
 
        last=it.F.F;
    }
 
    for(auto it : s1){
        ans=max(ans,dp[it]);
    }
    cout<<ans;
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}