#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;
const int mod1 = 998244353;

//8连走迷宫
//迷宫的入口和出口分别位于左上角和右上角

int a[1000][1000],vis[1000][1000];
int n,ans;

//上下左右四方向移动
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x,int y){
    if (x == 1 && y == n){//出口
        ans ++;
        return;
    }
    for (int i = 0; i < 4; i++){
        int xt = x + dx[i];
        int yt = y + dy[i];
        if (a[xt][yt] == 1 || vis[xt][yt] == 1 || xt < 1 || yt < 1 || xt > n || yt > n) continue;
        vis[xt][yt] = 1;
        dfs(xt, yt);
        vis[xt][yt] = 0;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    vis[1][1] = 1;
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}