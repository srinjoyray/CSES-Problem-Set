#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
const int N=1e7+10;
int dp[N];

void solve(){
    int i,j;
    int n,x;
    cin>>n>>x;
    memset(dp,0,sizeof dp);
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        dp[a[i]]=(dp[a[i]]+1)%mod;
        for(j=0;j<=x;j++){
            dp[j+a[i]]=(dp[j+a[i]]+dp[j])%mod;
        }
    }
    cout<<dp[x];
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }    
}