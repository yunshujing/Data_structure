#include<bits/stdc++.h>
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

    int n,m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n;i++){
        vector<int> a;
        for (int j = 0; j < m;j++){
            int t;
            cin >> t;
            a.push_back(t);
        }
        sort(a.begin(), a.end());
        sum += a[a.size()-1];
    }
    cout << sum;
    return 0;
}