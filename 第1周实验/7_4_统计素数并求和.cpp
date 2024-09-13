#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

typedef long long ll;
typedef unsigned long long ull; // ��Ȼ���
typedef pair<int,int> PII;
const int S = 50; // ������
// ���ٳ�,��ֹ�˷����longlong
ll mult_mod(ll u,ll v,ll p){
    return (u * v - ll((/*long*/ double)u * v / p) * p + p) % p;
}
// ������
ll fast_pow(ll x,ll y,ll mod){
    ll res = 1;
    x %= mod;
    while(y){
        if(y & 1) res = mult_mod(res,x,mod);
        x = mult_mod(x,x,mod);
        y >>= 1;
    }
    return res;
}

bool witness(ll a,ll n){
    ll u = n - 1;
    int t = 0;
    // ����t,u,��n-1һֱ��2,ֱ��������,ʣ�µ�������u,��2������t
    while(u & 1 == 0){u = u >> 1,t++;} 
    ll x1,x2;
    x1 = fast_pow(a,u,n); // ����a^u
    // ��t��ƽ��
    for(int i = 1;i <= t;i++){
        x2 = fast_pow(x1,2,n); // ƽ����Ľ��
        // ����̽�ⶨ��
        if(x2 == 1 && x1 != 1 && x1 != n - 1) return true; // ��Ȼ�Ǻ���
        x1 = x2;
    }
    // ���x1=a^n-1,����С����
    if(x1 != 1) return true; // ��Ȼ�Ǻ���
    return false;
}

int miller_rabin(ll n){
    if(n < 2) return 0; // С��2�Ǻ���
    if(n == 2) return 1; // 2������
    if(n % 2 == 0) return 0; // ż���Ǻ���
    // ʣ��������
    for(int i = 0;i < S;i++){
        ll a = rand() % (n - 1) + 1; // ���һ��a
        if(witness(a,n)) return 0; // ����
    }
    return 1;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    int m, n;
    cin >> m >> n;
    int sum = 0, cnt = 0;
    for (int i = m; i <= n;i++){
        if(miller_rabin(i)){
            cnt++;
            sum += i;
        }
    }
    cout << cnt << " " << sum << endl;
    return 0;
}