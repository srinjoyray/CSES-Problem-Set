#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define nl '\n'

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
const int N=1e6+10;
 
void solve(){
    int i,j;
    int n;
    cin>>n;
    int a[n];
    pbds A;
    for(i=0;i<n;i++){
        cin>>a[i];
        A.insert(i);
    }
    
    for(i=0;i<n;i++){
        int pos,temp;
        cin>>pos;
        pos--;
        
        temp=*A.find_by_order(pos);
        A.erase(temp);
        
        cout<<a[temp]<<" ";
    }
    cout<<nl;
}
 
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    solve();    
}