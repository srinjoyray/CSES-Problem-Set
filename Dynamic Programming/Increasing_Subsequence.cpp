#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

void solve(){
    int i,j;
    int n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> v;
    for(i=0;i<n;i++){
        if(lower_bound(all(v),a[i])==v.end()){
            v.push_back(a[i]);
        }
        else{
            *lower_bound(all(v),a[i])=a[i];
        }
    }    
    cout<<v.size();
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}
 