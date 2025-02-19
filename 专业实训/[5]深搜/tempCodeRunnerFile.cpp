#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

int vis[10010],n,m;
void dfs(vector<int> g,int cnt,int mx){
    if(cnt == m){
        for(int i = 0 ;i < m; i++){
            printf("%3d", g[i]);
        }
        cout  <<  endl;
        return;
    }
    for(int i = 1 ; i <= n; i++){
        if(vis[i]||i<mx) continue;//已经标记就跳过
        g.push_back(i);
        vis[i] = 1;//标记
        dfs(g, cnt + 1,i);
        g.pop_back();
        vis[i] = 0;//取消标记
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    cin >> n>>m;
    dfs({},0,0);
    
    return 0;
}