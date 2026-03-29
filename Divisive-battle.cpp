#include <bits/stdc++.h>
using namespace std;
#define int long long

set<int> prime_factors(int n){
    set<int> ans;
    if(n == 1){
        ans.insert(1);
        return ans;
    }
    for(int i = 2; i*i<=n; ++i){
        while(n%i == 0){
            ans.insert(i);
            n/=i;
        }
    }
    if(n>1)
        ans.insert(n);
    return ans;
}

void solve(){
    int n; cin>>n;
    vector<int> vec(n), a(n);
    for(int i = 0; i<n; ++i)
        cin>>vec[i];
    a = vec;
    sort(a.begin(), a.end());
    if(a == vec){
        cout<<"Bob\n";
        return;
    }
    vector<vector<int>> b(n);
    for(int i = n-1; i>=0; --i){
        set<int> a = prime_factors(vec[i]);
        if((int)a.size()>1){
            cout<<"Alice\n";
            return;
        }
        for(auto &it: a)
            b[i].push_back(it);
    }
    vector<int> ans, verify;
    
    for(int i = 0; i<n; ++i){
        for(auto &it: b[i])
            ans.push_back(it), verify.push_back(it);
    }
    sort(verify.begin(), verify.end());
    cout<<(ans == verify ? "Bob\n" : "Alice\n");
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1; 
    cin>>t;
    while(t--){
        solve();
    }
}
