#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;
int a[N];
int n, m;
bool f(double x){
    int cnt = 0;
    for (int i = 0; i < n;i++){
        cnt += (int)(a[i] / x);
    }
    return cnt >= m;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    cin >> n >> m;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    double l=1, r=1e9;
    while(r-l>eps){
        double x = l + (r - l) / 2;
        if(f(x)){
            l = x;
        }else{
            r = x;
        }
    }
    cout << fixed << setprecision(2) << r;
    return 0;
}