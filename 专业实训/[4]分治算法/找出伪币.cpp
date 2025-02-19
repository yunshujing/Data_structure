#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps = 1e-4;
void maxmin(int a[], int& mx, int& mn, int lt, int rt) {
    if (rt - lt <= 2) {
        mx = a[lt] > a[rt - 1]? a[lt] : a[rt - 1];
        mn = a[lt] < a[rt - 1]? a[lt] : a[rt - 1];
        return;
    }
    int mid = (lt + rt) / 2;
    int lmx, lmn, rmx, rmn;
    maxmin(a, lmx, lmn, lt, mid);
    maxmin(a, rmx, rmn, mid, rt);
    mx = lmx > rmx? lmx : rmx;
    mn = lmn < rmn? lmn : rmn;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(6);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx, mn;
    maxmin(a, mx, mn, 0, n);
    int minIndex;
    for (int i = 0; i < n; i++) {
        if (a[i] == mn) {
            minIndex = i;
            break;
        }
    }
    cout << minIndex + 1 << " " << mn << endl;
    return 0;
}