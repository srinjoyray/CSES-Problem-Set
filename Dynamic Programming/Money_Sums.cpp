#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int dp[200][200000];

void solve(){
    int i,j;
    int n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,0,sizeof dp);
    for(i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(i=1;i<=n;i++){
        for(j=0;j<200000;j++){
            if(j<a[i-1]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i-1]]);
            }
        }
    }
    vector<int> v;
    for(j=1;j<200000;j++){
        if(dp[n][j]==1){
            v.push_back(j);
        }
    }
 
    cout<<v.size()<<'\n';
    for(i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<'\n';
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}