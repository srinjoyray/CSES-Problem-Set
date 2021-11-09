#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

const int N=1e6+10;
 
void solve(){
    int i,j;
    int n;
    cin>>n;
    ll dp[n],half,full;
    
    dp[1]=2;
    half=1,full=1;
 
    for(i=2;i<=n;i++){
        ll new_half=0,new_full=0;
 
        dp[i]=(full*3+half*5)%mod;
 
        new_full=2*full+half;
        new_half=full+4*half;
        
        half=new_half%mod;
        full=new_full%mod;
    }
    cout<<dp[n]<<'\n';
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
}