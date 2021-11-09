#include<bits/stdc++.h>
using namespace std;
 
const int N=1e7+10,inf=1e8;
int dp[N];

void solve(){
    int i,j;
    int n,x;
    cin>>n>>x;
    for(i=0;i<x+10;i++){
        dp[i]=inf;
    }
    dp[0]=0;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<=x;i++){
        if(dp[i]==inf){
            continue;
        }
        for(j=0;j<n;j++){
            dp[i+a[j]]=min(dp[i+a[j]],dp[i]+1);
        }
    }
 
    if(dp[x]==inf){
        cout<<"-1\n";
    }
    else{
        cout<<dp[x];
    }
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    
}