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

    int n;
    cin >> n;
    int a[128];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int c = 3;
    while(c <= n+1){
        sort(a+1,a+c);
        for(int j = 1; j<n; j++){
            cout << a[j] << " ";
        }
        cout << a[n] <<'\n';
        c+=1;
    }
}
