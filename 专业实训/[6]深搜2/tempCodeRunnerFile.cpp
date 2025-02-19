#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e3 + 10;
const double eps =1e-4;

char mp[N][N];
int m,n;
int tot;
void dfs(int r,int c){
    if(r < 1 || r >m|| c < 1 || c > n){
        return;
    }
    if(mp[r][c] == '#'){
        return;
    }
    tot++;
    mp[r][c] = '#';
    dfs(r,c-1);
    dfs(r-1,c);
    dfs(r,c+1);
    dfs(r+1,c);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cout << setw(3);
	cout << fixed << setprecision(6);
    int sr,sc;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>mp[i][j];
            if(mp[i][j]=='@')
            {
                sr=i;
                sc=j;
            }
        }
    }
    dfs(sr,sc);
    cout<<tot;
    return 0;
}

