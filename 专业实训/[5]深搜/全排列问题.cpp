#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

int vis[10010],n=0;
void dfs(vector<int> g,int cnt){
    if(cnt == n){
        for(int i = 0 ;i < n; i++){
            cout << "    "<< g[i] ;
        }
        cout  <<  endl;
        return;
    }
    for(int i = 1 ; i <= n; i++){
        if(vis[i]) continue;//已经标记就跳过
        g.push_back(i);
        vis[i] = 1;//标记
        dfs(g, cnt + 1);
        g.pop_back();
        vis[i] = 0;//取消标记
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    cin >> n;
    dfs({},0);

    return 0;
}