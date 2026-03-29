// Problem Link - https://codeforces.com/contest/2200/problem/F
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, m; cin>>n>>m;
    int global_ans = 0;
    vector<int> dp(n+1, 0);
    vector<vector<int>> bucket(n+1);
    for(int i = 0; i<n; ++i){
        int a, b; cin>>a>>b;
        bucket[b].push_back(a);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0;
    for(int i = n; i>=0; --i){
        int size = i;
        vector<int> &vec = bucket[size];
        for(auto &it: vec){
            pq.push(it), sum+=it;
        }
        while((int)pq.size()>size+1){
            int a = pq.top();
            sum-=a;
            pq.pop();
        }
        global_ans = max(global_ans, sum);
        (int)pq.size() == size+1 ? dp[size] = sum-pq.top() : dp[size] = sum;
    }
    for(int i = 1; i<=n; ++i)
        dp[i] = max(dp[i], dp[i-1]);
    for(int i = 0; i<m; ++i){
        int x, y; cin>>x>>y;
        int ans = max(global_ans, x+dp[y]);
        cout<<ans<<" ";
    }
    cout<<"\n";
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
