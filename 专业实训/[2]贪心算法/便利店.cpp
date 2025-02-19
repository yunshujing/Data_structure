#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int q,h,s,d,n;
	cin>>q>>h>>s>>d>>n;
	int minv=min(min(q*4,h*2),s);
	if(minv*2<=d){
		cout<<minv*n;
	}
	else{
		cout<<(n%2)*minv+n/2*d;
	}
	return 0;
}