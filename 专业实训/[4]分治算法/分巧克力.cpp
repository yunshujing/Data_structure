#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e5 + 10;
const double eps =1e-4;
int n,k;
int h[N], w[N];
bool check(int d){
    int num=0;
    for(int i=0;i<n;i++){
        num += (h[i] / d) * (w[i] / d);
    }
        if(num>=k)
            return true;
        else
            return false;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> h[i] >> w[i];
    }
    int L = 1, R = N;
    while(L<R){
        int mid = (L+R+1)>>1;
        if(check(mid)){
            L = mid;
        }else{
            R = mid-1;
        }
    }
    cout << L << endl;

    return 0;
}