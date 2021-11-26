#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define nl '\n'

typedef pair<ll, ll>	pl;
typedef tree<pl, null_type, less<pl>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
const int N=1e6+10;
 
void solve(){
    int i,j;
    int n,q;
    cin>>n>>q;
    ll a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    pbds A;
    for(i=0;i<n;i++){
        A.insert({a[i],i});
    }
    while(q--){
        char ch;
        cin>>ch;
        if(ch=='?'){
            ll l,r,x=n,y=n;
            cin>>l>>r;
            if(A.upper_bound({l,n})!=A.end()){
                x=A.order_of_key(*A.upper_bound({l-1,n}));
            }
 
            if(A.upper_bound({r,n})!=A.end()){
                y=A.order_of_key(*A.upper_bound({r,n}));
            }
            
            cout<<y-x<<nl;
        }
        else{
            ll pos,val;
            cin>>pos>>val;
            pos--;
            A.erase({a[pos],pos});
            a[pos]=val;
            A.insert({a[pos],pos});
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    solve();
}