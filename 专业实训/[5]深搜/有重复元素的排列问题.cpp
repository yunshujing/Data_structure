#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps = 1e-4;

void dfs(string& str, vector<bool>& used, string& current, set<string>& result) {
    if (current.size() == str.size()) {
        result.insert(current);
        return;
    }
    for (int i = 0; i < str.size(); i++) {
        if (used[i]) continue;
        if (i > 0 && str[i] == str[i - 1] && !used[i - 1]) continue;
        used[i] = true;
        current.push_back(str[i]);
        dfs(str, used, current, result);
        current.pop_back();
        used[i] = false;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);

    int n;
    cin >> n;
    string str;
    cin >> str;

    sort(str.begin(), str.end());
    vector<bool> used(n, false);
    string current;
    set<string> result;

    dfs(str, used, current, result);

    for (const auto& s : result) {
        cout << s << endl;
    }
    cout << result.size() << endl;

    return 0;
}