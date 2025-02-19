#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

struct act{
    int begin, end;
};
typedef struct act act;
vector<act> a;

bool cmp(act a,act b){
    return a.end<b.end;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    int n;
    cin >> n;
    for (int i=0; i < n;i++){
        act tmp;
        cin >> tmp.begin >> tmp.end;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end(), cmp);
    int num=1,end=a[0].end;
    for(int i=1;i<n;i++){
        if(a[i].begin>=end){
            num++;
            end=a[i].end;
        }
    }
    cout << num << endl;

    return 0;
}