#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long 

const ll N=1e6+10,inf=1e18;
ll a[N],dp[5050][5050];

ll solve(int i,int j){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=inf){
        return dp[i][j];
    }
    return dp[i][j]=max((a[i]+min(solve(i+1,j-1),solve(i+2,j))),(a[j]+min(solve(i+1,j-1),solve(i,j-2))));
}
void solve(){
    int i,j;
    int n;
    cin>>n;
  
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<5050;i++){
        for(j=0;j<5050;j++){
            dp[i][j]=inf;
        }
    }
    solve(0,n-1);
    
    cout<<dp[0][n-1]<<'\n';
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}