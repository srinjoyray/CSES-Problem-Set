#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

const ll inf=1e18;
struct node{
    ll left,right;
};
struct Segtree {
	vector<node> tree;
	vector<ll> arr; 
	int n;
	Segtree(int a_len, vector<ll> &a) 
    { 
		arr = a;
		n = a_len;
		tree.resize(4 * n); 
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index)  
	{
		if (start == end)	{
			tree[index].left = arr[start];
			tree[index].right = arr[start];
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].left=min(tree[2 * index].left , tree[2 * index + 1].left+(mid+1-start));
		tree[index].right=min(tree[2 * index].right+(end-mid) , tree[2 * index + 1].right);
	}
	void update(int start, int end, int index, int query_index, ll val)  
	{
		if (start == end) {
			tree[index].left = val;
			tree[index].right = val;
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, val);
		else
			update(mid + 1, end, 2 * index + 1, query_index, val);
		
        tree[index].left=min(tree[2 * index].left , tree[2 * index + 1].left+(mid+1-start));
		tree[index].right=min(tree[2 * index].right+(end-mid) , tree[2 * index + 1].right);
	}
	node query(int start, int end, int index, int left, int right) { 
		node p;
        p.left=inf,p.right=inf;
        if (start > right || end < left)
			return p;
		if (start >= left && end <= right){
			return tree[index];
        }
		int mid = (start + end) / 2;
		node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		
        
        ans.left=min(l.left , r.left+(mid+1-max(start,left)));
		ans.right=min(l.right+(min(end,right)- mid) , r.right);
 
        if(l.left>=inf || r.left>=inf){
            ans.left=min(l.left , r.left);
		    ans.right=min(l.right , r.right);
        }
       
		return ans;
	}
};
void solve(){
    int i,j;
    int n,q;
    cin>>n>>q;
    vector<ll> v(n);
    for(i=0;i<n;i++){
        cin>>v[i];
    }
    Segtree sgt(n,v);
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
            int pos;
            cin>>pos;
            pos--;
            cout<<min(sgt.query(0,n-1,1,0,pos).right , sgt.query(0,n-1,1,pos,n-1).left)<<nl;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}