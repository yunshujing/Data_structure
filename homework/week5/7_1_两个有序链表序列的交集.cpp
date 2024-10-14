#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

int main() {
	vector<int> a;
    int x,p=0,f=0,l=0;
	while(cin>>x){
        if(x==-1) break;
        a.push_back(x);
        l++;
    }
    while(cin>>x){
        if(x==-1) break;
        while(p<l-1&&a[p]<x) p++;
        if(p<l&&a[p]==x){
            if(f==0){
                f=1;
                cout<<x;
            }
            else{
                cout<<' '<<x;
            }
            p++;
        }
    }
    if(f==0) cout<<"NULL";
	return 0;
}