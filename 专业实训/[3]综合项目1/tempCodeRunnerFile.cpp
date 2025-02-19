#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define vll vector<long long>
#define fi first
#define se second
#define pub push_back
#define pob pop_back
const int N = 1e6 + 10;
const double eps = 1e-4;
const int mod1 = 998244353;

const int maxlen = 11;
int n; // N <= maxlen
vector<int> tm; // 存储皇后的列坐标

// 输出每种可能下的每个皇后的列坐标
int vis[maxlen][maxlen] = { 0 };

int cnt = 0;
int CNT = 0;
bool flag = 0;
int ccc = 0;

void doAdd(int r, int c, int n, int val) { // 标记（坐标，边界，标记数）
    if (r < 0 || r >= n) {
        return;
    }
    if (c < 0 || c >= n) {
        return;
    }
    vis[r][c] += val;
}

void add(int r, int c, int n, int val) { // 这种二维打标记的方法真的很nice
    int i;
    for (int i = 0; i < n; i++) {
        doAdd(r, i, n, val); // 行全标记
        doAdd(i, c, n, val); // 列全标记
    }
    for (int i = 0; i < n; i++) { // 对角线标记
        doAdd(r + i, c + i, n, val); // 右下
        doAdd(r - i, c - i, n, val); // 左上
        doAdd(r + i, c - i, n, val); // 左上
        doAdd(r - i, c + i, n, val); // 右下
    }
}

void dfs(int dep, int maxdep) {
    int i;
    if (dep == maxdep) { // 到底了
        cnt++;
        if (!::tm.empty()) { // 使用全局变量 tm
            flag = 1; // 存在
        }
        return;
    }
    for (i = 0; i < maxdep; i++) {
        if (vis[dep][i] == 0) {
            ::tm.push_back(i + 1); // 使用全局变量 tm
            add(dep, i, maxdep, 1); // 标记
            dfs(dep + 1, maxdep);
            ::tm.pop_back(); // 使用全局变量 tm
            add(dep, i, maxdep, -1);
        }
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        dfs(0, n);
        if (!flag) {
            cout << "no solute!" << endl;
        }
        cout << cnt << endl;
        cnt = 0;
    }
}