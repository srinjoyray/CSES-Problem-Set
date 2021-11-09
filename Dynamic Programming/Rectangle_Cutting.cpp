#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10,inf=1e9;
int dp[600][600];

int solve(int a,int b){
    if(a<b){
        swap(a,b);
    }
    if(b==0 || a==b){
        return 0;
    }
    if(dp[a][b]!=inf){
        return dp[a][b];
    }
    for(int i=1;i<a;i++){
        dp[a][b]=min(dp[a][b],solve(i,b)+solve(a-i,b)+1);
    }
    for(int i=1;i<b;i++){
        dp[a][b]=min(dp[a][b],solve(a,i)+solve(a,b-i)+1);
    }
    return dp[a][b];
}
void solve(){
    int i,j;
    int a,b,ans=0,rem;
    cin>>a>>b;
    for(i=0;i<600;i++){
        for(j=0;j<600;j++){
            dp[i][j]=inf;
        }
    }
    ans=solve(a,b);
    cout<<ans;
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}