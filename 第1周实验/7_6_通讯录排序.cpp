#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

struct student
{
    string name;
    int sr;
    string phone;
};

student stu[13];

bool cmp(student a, student b){
    return a.sr < b.sr;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> stu[i].name >> stu[i].sr >> stu[i].phone;
    }

    sort(stu, stu + n,cmp);

    for (int i = 0; i < n;i++){
        cout << stu[i].name <<" "<< stu[i].sr <<" "<< stu[i].phone<<endl;
    }

    return 0;
}