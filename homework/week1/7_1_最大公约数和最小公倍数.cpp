#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

int gcd(int a, int b) {  
    if (b == 0)  
        return a;  
    return gcd(b, a % b);  
}

int lcm(int a, int b) {  
    return (a / gcd(a, b)) * b; 
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << " " << lcm(a, b) << endl;

    return 0;
}