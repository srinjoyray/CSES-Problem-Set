#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define nl '\n'

const ll inf=1e18;
struct SegTree {
	vector<ll> tree;
	vector<ll> arr; 
	int n;
	SegTree(int a_len, vector<ll> &a) { 
		arr = a;
		n = a_len;
		tree.resize(4 * n); 
        fill(all(tree), 0);
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index) 
	{
		if (start == end)	{
			tree[index] = arr[start];
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index]=min(tree[2 * index] , tree[2 * index + 1]);
	}
	void update(int start, int end, int index, int query_index, ll val)  
	{
		if (start == end) {
			tree[index] = val;
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, val);
		else
			update(mid + 1, end, 2 * index + 1, query_index, val);
		tree[index]=min(tree[2 * index] , tree[2 * index + 1]);
	}
	ll query(int start, int end, int index, int left, int right) { 
		if (start > right || end < left)
			return inf;
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		ll l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans=min(l,r);
		return ans;
	}
};
void solve(){
    int i,j;
    int n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    SegTree sgt(n,a);
 
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            ll pos,val;
            cin>>pos>>val;
            pos--;
            sgt.update(0,n-1,1,pos,val);
        }
        else{
            ll l,r;
            cin>>l>>r;
            l--,r--;
            cout<<sgt.query(0,n-1,1,l,r)<<nl;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();    
}