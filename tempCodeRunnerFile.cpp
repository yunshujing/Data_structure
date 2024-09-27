#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    int c=0;
    int a[N];
    int n, m;
    cin >> n;
    for (int i = 0; i <n;i++){
        cin >> a[c++];
    }
    cin >> m;
    for (int i = 0; i < m;i++){
        cin >> a[c++];
    }
    sort(a, a + m + n);
    for (int i = 0; i < m + n;i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}