#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define nl '\n'

struct SegTree {
	vector<ll> tree;
	vector<ll> arr; 
	int n;
	SegTree(int a_len, vector<ll> &a) 
    { 
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
		tree[index]=max(tree[2 * index] , tree[2 * index + 1]);
	}
	void update(int start, int end, int index, int query_index, ll val)  
	{
		if (start == end) {
			tree[index] -= val;
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, val);
		else
			update(mid + 1, end, 2 * index + 1, query_index, val);
		tree[index]=max(tree[2 * index] , tree[2 * index + 1]);
	}
	ll query(int start, int end, int index, int left, int right) { 
		if (start > right || end < left)
			return 0;
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		ll l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans=max(l,r);
		return ans;
	}
};
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    vector<ll> h(n);
    for(i=0;i<n;i++){
        cin>>h[i];
    }
    SegTree sgt(n,h);
    while(m--){
        ll req,l,r,ans=n+1,mid;
        cin>>req;
        l=1,r=n;
        while(l<=r){
            mid=(l+r)/2;
            if(sgt.query(0,n-1,1,0,mid-1)>=req){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(ans>n){
            ans=0;
        }
        else{
            sgt.update(0,n-1,1,ans-1,req);
        }
        cout<<ans<<" ";
    }
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}
 