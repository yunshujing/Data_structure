/* #include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

// 求最大公因数
int gcd(int a, int b) {
    return b == 0? a : gcd(b, a % b);
}
// 化简分数
void simp(int &num, int &den) {
    int cd = gcd(abs(num), den);
    num /= cd;
    den /= cd;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);
    
    int n;
    cin >> n;
    int sum_num = 0, den_prod = 1;
    for (int i = 0; i < n; ++i) {
        int num, den;
        char slash;
        cin >> num >> slash >> den;
        // 求最小公倍数来通分
        int lcm = den_prod * den / gcd(den_prod, den);
        sum_num = sum_num * (lcm / den_prod) + num * (lcm / den);
        den_prod = lcm;
    }
    simp(sum_num, den_prod);
    int int_part = sum_num / den_prod;
    int frac_num = sum_num % den_prod;
    if (int_part!= 0) {
        if (frac_num!= 0) {
            cout << int_part << " " << frac_num << "/" << den_prod << endl;
        } else {
            cout << int_part << endl;
        }
    } else {
        if (frac_num!= 0) {
            cout << frac_num << "/" << den_prod << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
} */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[105],b[105],z=0,d=1,sum=0,x,y;
char c;
ll gcd(ll a,ll b)	//寻找最大公约数
{
	return b?gcd(b,a%b):a;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c>>b[i];
        d*=b[i];
    }
    for(int i=1;i<=n;i++){
        sum+=a[i]*(d/b[i]);
    }
    ll A=sum/d;
    ll B=sum%d;
    ll x=gcd(B,d);
    B=B/x;
    d=d/x;
    if (A==0 && B==0)
        printf("0");
    else if(A==0)
        cout<<B<<"/"<<d;
    else if(B==0)
        cout<<A;
    else
        cout<<A<<' '<<B<<"/"<<d;
}