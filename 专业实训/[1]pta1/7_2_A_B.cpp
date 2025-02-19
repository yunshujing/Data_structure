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

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int n = s1.size();
    int m = s2.size();
    
    for (int i = 0; i < n; i++){
        bool f = 1;
        for (int j = 0; j < m; j++){
            if (s1[i] == s2[j]){
                f = 0;
                break;
            }
        }
        if(f) cout << s1[i];
    }

    return 0;
}