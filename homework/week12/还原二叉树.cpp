#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

int dfs(char a[],char b[],int n){
    int i;
    if(n==0) return 0;
    for(i=0;i<n;i++){
        if(b[i]==a[0]){
            break;
        }
    }
    int x=dfs(a+1,b,i)+1;//求左子树的深度
    int y=dfs(a+i+1,b+i+1,n-i-1)+1;//求右子树的深度
    return x>y?x:y;
}

int n;
char a[100],b[100];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);
    
    cin>>n;
    cin>>a>>b;
    int cnt=dfs(a,b,n);
    cout<<cnt<<endl;
    
    return 0;
}
