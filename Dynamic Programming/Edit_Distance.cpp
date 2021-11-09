#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10,inf=1e9;
int dp[5050][5050];
   
void solve(){
    int i,j;
    string a,b;
    cin>>a>>b;
   
    for(i=0;i<5050;i++){
        for(j=0;j<5050;j++){
            dp[i][j]=inf;
        }
    }
    dp[0][0]=0;
    for(i=0;i<=a.size();i++){
        for(j=0;j<=b.size();j++){
            if(i>0){
                dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            }
            if(j>0){
                dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            }
            if(i>0 && j>0){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                }
                else{
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }
    }
   
    int ans,val;
    ans=dp[a.size()][b.size()];
    cout<<ans;

}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}