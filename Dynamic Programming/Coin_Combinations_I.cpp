#include<bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
const int N=1e7+10;
int dp[N];

void solve(){
    int i,j;    
    int n,x;
    cin>>n>>x;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }   
    memset(dp,0,sizeof dp);
    for(j=0;j<n;j++){
        dp[a[j]]=1;
    }
    for(i=0;i<=x;i++){
        for(j=0;j<n;j++){
            dp[i+a[j]]=(dp[i+a[j]]+dp[i])%mod;
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