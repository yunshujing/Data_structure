#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define vll vector<long long>
const int N = 1e6 + 10;
const double eps =1e-4;
const int mod1 = 998244353;

//int a[N];
//vll a;
int n;

void dfs(int x, int mx, vll g){
    if(x==n){
        if (g.size()<=1)
        {
            return;//免掉最后一个单数
        }
        
        for (int i = 0; i < g.size(); i++)
        {
            cout << g[i] << "+\n"[i == g.size() - 1];
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (x + i > n || i < mx) continue;//比前面的数大
        g.push_back(i);
        dfs(x + i, i, g);
        g.pop_back();
    }
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin >> n;
    dfs(0, 0, {});

    return 0;
}