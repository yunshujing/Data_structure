#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007

const int N = 1e6 + 10;
const double eps = 1e-11;

double f(double x) {
    return pow(2, x) + pow(3, x) - pow(4, x);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);

    int m;
    cin >> m;
    double l = 1.0, r = 2.0;
    double x;
    while (r - l > eps) {
        x = (l + r) / 2;
        if (f(x) > 0) {
            l = x;
        } else {
            r = x;
        }
    }
    cout << fixed << setprecision(m) << x << endl;

    return 0;
}
