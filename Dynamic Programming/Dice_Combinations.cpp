#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

const int N=1e6+10;
long long dp[N];
void solve(){
    int i,j;
    int n;
    cin>>n;
    memset(dp,0,sizeof dp);
    for(i=1;i<=6;i++){
        dp[i]=1;
    }
    for(i=2;i<=n;i++){
        for(j=1;j<=6 && i-j>0;j++){
            dp[i]+=dp[i-j];
            dp[i]%=mod;
        }
    }
    cout<<dp[n];
 
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;

    while(t--){
        solve();
    }
    
}