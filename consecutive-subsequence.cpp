// https://codeforces.com/contest/977/problem/F

// Jai Jai Shree Radhey Shyam
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    map<int, int> dp; int ans = 0, curr = -1;
    int n; cin>>n; vector<int> vec(n);
    for(int i = 0; i<n; ++i){
        cin>>vec[i];
        dp[vec[i]] = dp[vec[i]-1]+1;
        if(dp[vec[i]] > ans){
            ans = dp[vec[i]];
            curr = vec[i];
        }
    }
    cout<<ans<<"\n";
    vector<int> res;
    for(int i = n-1; i>=0; --i){
        if(curr == vec[i]){
            res.push_back(i+1);
            curr--;
        }
    }
    reverse(res.begin(), res.end());
    for(auto &it: res)
        cout<<it<<" ";
    cout<<"\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
