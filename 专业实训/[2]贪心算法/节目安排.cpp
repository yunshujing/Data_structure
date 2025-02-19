#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

struct Program {
    int start;
    int end;
};
bool cmp(Program a, Program b) {
    return a.end < b.end;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);
    int n;
    while (cin >> n && n != 0) {
        vector<Program> act(n);
        for (int i = 0; i < n; i++) {
            cin >> act[i].start >> act[i].end;
        }
        sort(act.begin(), act.end(), cmp);

        int count = 0;
        int last_end = 0;
        for (int i = 0; i < n; i++) {
            if (act[i].start >= last_end) {
                count++;
                last_end = act[i].end;
            }
        }
        cout << count << endl;
    }

    return 0;
}
