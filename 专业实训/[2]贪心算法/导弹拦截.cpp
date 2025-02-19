#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

int n,ma,d[100001],a[100001],k,x[100001],xl=1,t,len=1;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

	x[1]=0x7fffffff;
	while(cin>>a[++n]);
	d[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]<=d[len]) d[++len]=a[i];
		else d[upper_bound(d+1,d+len+1,a[i],greater<int>())-d]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		t=0;
		if(x[xl]<a[i])
		{
			xl++;
			x[xl]=a[i];
		}
		else
		{
			int k=lower_bound(x+1,x+xl+1,a[i])-x;
			x[k]=a[i];
		}
	}
	cout<<xl;
	return 0;
}