//* 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e4 + 10;
const double eps =1e-4;

char mp[N][N];
int n, m, cnt;
void bfs(int l,int r){
    if(l<1||l>m||r<1||r>n)
        return;
    if(mp[l][r]=='#')
        return;
    cnt++;
    mp[l][r] = '#';
    bfs(l - 1, r);
    bfs(l, r - 1);
    bfs(l + 1, r);
    bfs(l, r + 1);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // cout << setw(3);
    // cout << fixed << setprecision(6);

    cin >> n >> m;
    int sl, sr;
    for (int i = 1; i <= m;i++){
        for (int j = 1; j <= n;j++){
            cin >> mp[i][j];
            if(mp[i][j]=='@'){
                sl = i;
                sr = j;
            }
        }
    }
    bfs(sl, sr);
    cout << cnt << endl;
    return 0;
}
 //*/
/* #include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

int n, m, cnt;
int mp[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
bool vis[N];

void bfs(int x,int y){

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // cout << setw(3);
    cout << fixed << setprecision(6);

    for (int i = 0; i < m;i++){
        for (int i = 0; i < n;i++){
            cin >> mp[i][j];
            if(mp[i][j]=='@'){
                bfs(i, j);
            }
        }
    }
    cout << cnt << endl;

    return 0;
} */