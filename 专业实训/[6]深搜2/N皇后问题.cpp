#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

int c[100],n;
void dfs(int s){
	if(s==n+1){
		for(int i=1;i<=n;i++){
			cout.width(5);
			cout<<c[i];
		}
        cout << endl;
        return;
	}
	for(int i=1;i<=n;i++){
		bool ok=true;
		c[s]=i;
		for(int j=1;j<s;j++){
			if(c[s]==c[j]||abs(s-j)==abs(c[s]-c[j])){
				ok=false;
				break;
			}
		}
		if(ok){
			dfs(s+1);
		}
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

	cin>>n;
	dfs(1);
	if(n<=3){
		cout<<"no solute!"<<endl;
	}
	return 0;
} 
