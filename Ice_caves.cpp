// https://codeforces.com/contest/540/problem/C

// Jai Jai Shree Radhey Shyam
#include <bits/stdc++.h>
using namespace std;
#define int long long
int const N = 520;
int n, m, r1, c1, r2, c2;
vector<vector<char>> s(N, vector<char>(N));
vector<vector<int>> vis(N, vector<int>(N, 0));
int delx[] = {1, 0, -1, 0}, dely[] = {0, -1, 0, 1};
bool check(int x, int y){
    return (x>=1 && x<=n && y>=1 && y<=m);
}
bool dfs(int r, int c){
    if(r == r2 && c == c2){
        return true;
    }
    if(vis[r][c] == 1) return false;
    vis[r][c] = 1; bool ans = false;
    for(int i = 0; i<4; ++i){
        int nx = delx[i]+r, ny = dely[i]+c;
        if(check(nx, ny) && (s[nx][ny] == '.' || (nx == r2 && ny == c2)))
            ans |= dfs(nx, ny);
    }
    return ans;
}
void solve() {
    cin>>n>>m;
    for(int i = 1; i<=n; ++i)
        for(int j = 1; j<=m; ++j)
            cin>>s[i][j];
    cin>>r1>>c1>>r2>>c2;
    int count = 0;
    for(int i = 0; i<4; ++i){
        int nx = delx[i]+r2, ny = dely[i]+c2;
        if(check(nx, ny) && s[nx][ny] == '.')
            count++;
    }
    if(r1 == r2 && c1 == c2){
        cout<<((count)?("YES"):("NO"));
        return;
    }
    for(int i = 0; i<4; ++i){
        int nx = delx[i]+r2, ny = dely[i]+c2;
        if(nx == r1 && ny == c1){
            if(s[r2][c2] == 'X')
                cout<<"YES";
            else
                cout<<((count)?("YES"):("NO"));
            return;
        }
    }
    if((s[r2][c2] == 'X' && count<1) || (s[r2][c2] == '.' && count<2)){
        cout<<"NO";
        return;
    }
    bool ans = dfs(r1, c1);
    cout<<((ans)?("YES"):("NO"));
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
