#include<bits/stdc++.h>
using namespace std;
 

#define mod 1000000007
const int N=1e6+10,inf=1e8;
int dp[N];

void solve(){
    int i,j;
    dp[0]=0;
    int n,val,dig,mn;
    cin>>n;
    for(i=1;i<=n;i++){
        val=i;
        mn=inf;
        dp[i]=inf;
        while(val){
            dig=val%10;
            val/=10;
            mn=min(mn,dp[i-dig]);
        }
        dp[i]=mn+1;
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