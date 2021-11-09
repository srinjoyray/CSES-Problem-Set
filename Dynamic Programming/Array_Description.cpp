#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long 

const int N=1e6+10;
ll dp[100010][110];

void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    ll a[n],ans=0;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,0,sizeof dp);
    if(a[n-1]==0){
        for(j=1;j<=m;j++){
            dp[n-1][j]=1;
        }
    }
    else{
        dp[n-1][a[n-1]]=1;
    }
    
    for(i=n-2;i>=0;i--){
        if(a[i]==0){
            for(j=1;j<=m;j++){
                dp[i][j]+=dp[i+1][j];
                if(j-1>=1){
                    dp[i][j]+=dp[i+1][j-1];
                }
                if(j+1<=m){
                    dp[i][j]+=dp[i+1][j+1];
                }
                dp[i][j]%=mod;
            }
        }
        else{
            dp[i][a[i]]+=dp[i+1][a[i]];
            if(a[i]-1>=1){
                dp[i][a[i]]+=dp[i+1][a[i]-1];
            }
            if(a[i]+1<=m){
                dp[i][a[i]]+=dp[i+1][a[i]+1];
            }
            dp[i][a[i]]%=mod;
        }
    }
 
    for(j=0;j<=m;j++){
        ans+=dp[0][j];
        ans%=mod;
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