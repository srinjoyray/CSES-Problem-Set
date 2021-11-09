#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
const int N=1e3+10;
string s[N];
int a[N][N];
 
void solve(){
    int i,j;
    int n;
    cin>>n;
    
    for(i=0;i<n;i++){
        cin>>s[i];
    }
    if(s[0][0]=='*' || s[n-1][n-1]=='*'){
        cout<<"0\n";
        return;
    }
   
    memset(a,0,sizeof 0);
    a[0][0]=1;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(s[i][j]=='*'){
                continue;
            }
            if(i>0){
                a[i][j]=(a[i][j]+a[i-1][j])%mod;
            }
            if(j>0){
                a[i][j]=(a[i][j]+a[i][j-1])%mod;
            }
        }
    }
    cout<<a[n-1][n-1];
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}