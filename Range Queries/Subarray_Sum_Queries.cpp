#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

struct node{
    ll left,right,total,ans;
};

struct SegTree {
	vector<node> tree;
	vector<ll> arr; 
	int n;
	SegTree(int a_len, vector<ll> &a) { 
		arr = a;
		n = a_len;
		tree.resize(4 * n); 
        int i;
        for(i=0;i<tree.size();i++){
            tree[i].total=0,tree[i].right=0,tree[i].left=0,tree[i].ans=0;
        }
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index) 
	{
		if (start == end)	{
			tree[index].total = arr[start];
            tree[index].left = max(arr[start],(ll)0);
            tree[index].right = max(arr[start],(ll)0);
            tree[index].ans = max(arr[start],(ll)0);
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
        
        tree[index].total = tree[2*index].total + tree[2*index+1].total;
        tree[index].left = max(tree[2*index].left , tree[2*index].total + tree[2*index+1].left);
        tree[index].right = max(tree[2*index+1].right , tree[2*index+1].total + tree[2*index].right);
        tree[index].ans = max({tree[2*index].ans , tree[2*index+1].ans , tree[2*index].right+tree[2*index+1].left });
 
 	}
	void update(int start, int end, int index, int query_index, ll val)  
	{
		if (start == end) {
			tree[index].total = val;
            tree[index].left = max(val,(ll)0);
            tree[index].right = max(val,(ll)0);
            tree[index].ans = max(val,(ll)0);
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, val);
		else
			update(mid + 1, end, 2 * index + 1, query_index, val);
		
        tree[index].total = tree[2*index].total + tree[2*index+1].total;
        tree[index].left = max(tree[2*index].left , tree[2*index].total + tree[2*index+1].left);
        tree[index].right = max(tree[2*index+1].right , tree[2*index+1].total + tree[2*index].right);
        tree[index].ans = max({tree[2*index].ans , tree[2*index+1].ans , tree[2*index].right+tree[2*index+1].left });

	}
	node query(int start, int end, int index, int left, int right) { 
        node p;
        p.total=0, p.left=0, p.right=0, p.ans=0;
		if (start > right || end < left)
			return p;
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		node l, r, res;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
 
        res.total = l.total + r.total;
        res.left = max(l.left , l.total + r.left);
        res.right = max(r.right , r.total + l.right);
        res.ans = max({ l.ans , r.ans , l.total+r.left , l.right+r.total , l.total+r.total});
		
		return res;
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
    
    SegTree sgt(n,v);
    while(q--){
        int pos,val;
        cin>>pos>>val;
        pos--;
        sgt.update(0,n-1,1,pos,val);
        cout<<sgt.query(0,n-1,1,0,n-1).ans<<nl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    solve();
}