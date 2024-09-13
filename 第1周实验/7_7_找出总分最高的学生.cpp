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
    string xh;
    string name;
    int cj1, cj2, cj3,sum;
};

student stu[12];

bool cmp(student a, student b){
    return a.sum > b.sum;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> stu[i].xh >> stu[i].name >> stu[i].cj1 >> stu[i].cj2 >> stu[i].cj3;
        stu[i].sum=stu[i].cj1 + stu[i].cj2 + stu[i].cj3;
    }

    sort(stu, stu + n, cmp);

    cout << stu[0].name << " " << stu[0].xh << " " << stu[0].sum << endl;

    return 0;
}