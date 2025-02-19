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

    int n,sum=0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    sum /= n;
    for(int i=0;i<n;i++){
        a[i] -= sum;
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            a[i + 1] += a[i];
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}