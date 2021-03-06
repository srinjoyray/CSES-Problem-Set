#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define nl '\n'

struct Segtree {
	vector<ll> tree;
    vector<ll> lazy;
	vector<ll> arr; 
	int n;
	Segtree(int a_len, vector<ll> &a) 
    { 
		arr = a;
		n = a_len;
		tree.resize(4 * n); 
        fill(all(tree), 0);
		lazy.resize(4 * n); 
        fill(all(lazy), 0);
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
		tree[index]=(tree[2 * index] + tree[2 * index + 1]);
	}
    void push(int index,int start,int end)
    {  
        if (start != end)
        {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }
	void update(int start, int end, int index, int start_range, int end_range, ll val)  
	{
		if (start > end)
            return;
        
        tree[index] += lazy[index]*(end-start+1);
        push(index,start,end);
 
        if (start_range > end || end_range < start) //no overlap
            return;
        if (start_range <= start && end_range >= end) //complete overlap
        {
            tree[index] += val*(end-start+1);
            lazy[index] += val;
            
            push(index,start,end);
 
            return;
        }
        int mid = (start + end) / 2;
        update(start, mid, 2 * index, start_range, end_range, val);
        update(mid + 1, end, 2 * index + 1, start_range, end_range, val);
        tree[index] = (tree[2 * index] + tree[2 * index + 1]);
	}
	ll query(int start, int end, int index, int left, int right) 
    { 
		if (start > end)
            return 0;
        if (lazy[index] != 0)
        {
            tree[index] += lazy[index]*(end-start+1);
            if (start != end)
            {
                lazy[2 * index] += lazy[index];
                lazy[2 * index + 1] += lazy[index];
            }
            lazy[index] = 0;
        }
        if (start > right || end < left)
            return 0;
        if (start >= left && end <= right)
            return tree[index];
		int mid = (start + end) / 2;
		ll l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans=(l+r);
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
            int l,r,val;
            cin>>l>>r>>val;
            l--,r--;
            sgt.update(0,n-1,1,l,r,val);
        }
        else{
            int pos;
            cin>>pos;
            pos--;
            cout<<sgt.query(0,n-1,1,pos,pos)<<nl;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}
