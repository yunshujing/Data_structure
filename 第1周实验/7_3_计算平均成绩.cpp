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
    double cj;
};

student stu[12];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    int n;
    cin >> n;
    double sum = 0;
    for (int i = 0; i < n;i++){
        cin >> stu[i].xh >> stu[i].name >> stu[i].cj;
        sum += stu[i].cj;
    }
    double pj = sum*1.00 / n*1.00;
    cout << fixed << setprecision(2)<< pj << endl;
    for (int i = 0; i < n; i++)
    {
        if(stu[i].cj<pj){
            cout << stu[i].name <<" "<< stu[i].xh <<endl;
        }
    }
    

    return 0;
}