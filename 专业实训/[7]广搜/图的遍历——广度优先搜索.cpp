#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 55;
const double eps =1e-4;

int g[N][N], n;
bool vis[N];
void bfs(int v){
    queue<int> q;
    q.push(v);
    vis[v] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int i = 0; i < n;i++){
            if(!vis[i]&&g[x][i]==1){
                q.push(i);
                vis[i] = 1;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // cout << setw(3);
    cout << fixed << setprecision(6);

    cin >> n;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cin >> g[i][j];
        }
    }
    bfs(0);

    return 0;
}