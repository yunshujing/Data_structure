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
    vector<int> a(3);  
    for (int i = 0; i < 3; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << a[0] << "->" << a[1] << "->" << a[2];

    return 0;
}