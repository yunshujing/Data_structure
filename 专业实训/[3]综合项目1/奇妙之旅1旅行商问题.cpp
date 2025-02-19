#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

const int INF = 1e9;
int dp[1 << 16][16];
int dist[16][16];
int tsp(int n) {
    // 初始化dp数组
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            dp[mask][i] = INF;
        }
    }
    dp[1][0] = 0;

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (mask & (1 << u)) { 
                for (int v = 0; v < n; ++v) {
                    if (!(mask & (1 << v)) && dist[u][v] != INF) { 
                        dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + dist[u][v]);
                    }
                }
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < n; ++i) {
        ans = min(ans, dp[(1 << n) - 1][i] + dist[i][0]);
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << setw(3);
    cout << fixed << setprecision(6);
    
    int t, n, m, u, v, w;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = (i == j) ? 0 : INF;
            }
        }

        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            --u; --v;
            dist[u][v] = dist[v][u] = w;
        }

        int result = tsp(n);
        if (result == INF) {
            cout << 10000000 << endl;
        } else {
            cout << result << endl;
        }
    }
    return 0;
}