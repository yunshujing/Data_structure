#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

signed main() {
    int n, m;
    cin >> n >> m;
    getchar();
    while(n--){
        stack <char> st;
        string a;bool f = 1;
        getline(cin, a);
        for (char x: a) {
            if (x == 'S')st.push(x);
            if(st.size()>m){ f = 0; break;}
            if (x == 'X') {
                if (!st.empty())st.pop();	       
                else { f = 0; break;  }
            }
        }
        if (st.empty()&&f) cout << "YES";
        else
            cout << "NO";
        if(n>0)
            cout << endl;
    }
}