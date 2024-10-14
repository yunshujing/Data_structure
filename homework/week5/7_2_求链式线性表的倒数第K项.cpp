#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

vector<int> s;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    int t, k;
    cin >> k;
    while (cin >> t && t > -1){
        s.push_back(t);
    }
    if(k <= s.size()){
        cout << s[s.size()-k] << endl;
    }
    else{
        cout << "NULL" << endl;
    }

    return 0;
}