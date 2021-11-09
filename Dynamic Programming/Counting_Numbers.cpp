#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll power(ll a,ll n){
    ll res=1;
    while(n){
        if(n%2){
            res=(res*a);
        }
        a=(a*a);
        n/=2;
    }
    return res;
}

ll find(ll n){
    if(n<0){
        return 0;
    }
    string s;
    s=to_string(n);
    ll i,ans=0,temp,options,rem;
    for(i=1;i<=s.size()-1;i++){
        temp=power(9,i);
        ans+=temp;
    }
    if(s.size()>1){
        ans++;
    }
   
    for(i=0;i<s.size();i++){
        options=s[i]-'0';
        if(i>0 && s[i]>s[i-1]){
            options--;
        }
        if(i==0){
            options--;
        }
        options=max(options,(ll)0);
        rem=s.size()-i-1;
        temp=options*power(9,rem);
       
        ans+=temp;
        if(i>0 && s[i]==s[i-1]){
            break;
        }
    }
    for(i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            break;
        }
    }
    if(i==s.size()-1){
        ans++;
    }

    return ans;
}
void solve(){
    int i,j;
    ll a,b,ans;
    cin>>a>>b;
    ans=find(b)-find(a-1);
    cout<<ans;
}
 
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    
}