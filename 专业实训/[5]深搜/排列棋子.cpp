#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps = 1e-4;

int n, m;
vector<int> g;
vector<int> vis;
void dfs(int pos, int zeroCount, int oneCount) {
    if (pos == n + m) {
        for (int i = 0; i < n + m; i++) {
            cout << g[i];
        }
        cout << endl;
        return;
    }
    if (zeroCount < n) {
        g.push_back(0);
        dfs(pos + 1, zeroCount + 1, oneCount);
        g.pop_back();
    }
    if (oneCount < m) {
        g.push_back(1);
        dfs(pos + 1, zeroCount, oneCount + 1);
        g.pop_back();
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(6);

    cin >> n >> m;
    vis.resize(n + m + 1, 0);
    dfs(0, 0, 0);

    return 0;
}