#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int dp[1020][100020];

void solve(){
    int i,j;
    int n,x;
    cin>>n>>x;
    int h[n],s[n],mx=0;
    for(i=0;i<n;i++){
        cin>>h[i];
    }
    for(i=0;i<n;i++){
        cin>>s[i];
    }
    memset(dp,-1,sizeof dp);
    for(i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(i=1;i<=n;i++){
        for(j=0;j<x+10;j++){
            if(j<h[i-1]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-h[i-1]]+s[i-1]);
            }
        }
    }
  
    for(j=0;j<=x;j++){
        mx=max(mx,dp[n][j]);
    }
    cout<<mx;
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}