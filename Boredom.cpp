// https://codeforces.com/contest/455/problem/A

// Jai Jai Shree Radhey Shyam
#include <bits/stdc++.h>
using namespace std;
#define int long long

int const N = 1e5+1;
void solve() {
    int n; cin>>n; vector<int> vec(n); map<int, int> mp;
    for(int i = 0; i<n; ++i){
        cin>>vec[i];
        mp[vec[i]]++;
    } 
    vector<int> ans(N, 0);
    ans[1] = mp[1];
    for(int i = 2; i<N; ++i)
        ans[i] = max(ans[i-2]+mp[i]*i, ans[i-1]);
    cout<<ans[N-1];
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
