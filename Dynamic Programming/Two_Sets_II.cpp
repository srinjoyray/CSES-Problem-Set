#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

const int N=1e6+10;
ll a[600],dp[510][300000];
ll power(ll a,ll n){
    ll res=1;
    while(n){
        if(n%2){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}
void solve(){
    int i,j;
    int n,target;
    cin>>n;
    for(i=0;i<n;i++){
        a[i]=i+1;
    }
    if(n*(n+1)/2 %2 ==1){
        cout<<"0\n";
        return;
    }
    target=n*(n+1)/4;
 
    for(i=0;i<=n;i++){
        for(j=0;j<=target;j++){
            dp[i][j]=0;
        }
    }
 
    for(i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=target;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=a[i-1] ){
                dp[i][j]+=dp[i-1][j-a[i-1]];
                if(j-a[i-1]==0){
                    dp[i][j]++;
                }                
            }
            dp[i][j]%=mod;
        }
    }
    
    ll ans=dp[n][target],num;
    num=power(2,mod-2);
    ans=(ans*num)%mod;
    cout<<ans;
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}
 