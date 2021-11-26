#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
 
void solve(){
    int i,j;
    int n,q,curr;
    cin>>n>>q;
    string s[n];
    for(i=0;i<n;i++){
        cin>>s[i];
    }
    int a[n][n+1],ans,count;
    
    for(i=0;i<n;i++){
        curr=0;
        a[i][0]=curr;
        for(j=0;j<n;j++){
            if(s[i][j]=='*'){
                curr++;
            }
            a[i][j+1]=curr;
        }
    }
 
    while(q--){
        ans=0;
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        
        y1--,y2--;
        for(i=y1;i<=y2;i++){
            count=a[i][x2]-a[i][x1-1];
            ans+=count;
        }
 
        cout<<ans<<nl;
    }
   
 
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();    
}