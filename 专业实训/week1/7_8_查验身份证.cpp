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
    vector<string> s(n);
    int x[18] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char y[12] = {'1','0','X','9','8','7','6','5','4','3','2'};
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    bool f = 1;
    for (int i = 0; i < n; i++){
        int t = 0;
        for (int j = 0; j < 17; j++){
            t += (s[i][j]-'0')*x[j];
        }
        t %= 11;
        if (y[t] != s[i][17]){
            f = 0;
            cout<<s[i]<<endl;
        }
    }
    if(f) cout << "All passed";

    return 0;
}