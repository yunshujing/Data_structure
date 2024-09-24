#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

char s[105][19];
int sw[105];

string x = "10X98765432";
int ss[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    int n;
    cin >> n;
    bool flag = 1;

    for (int i = 0; i < n;i++){
        sw[i] = 0;
    }

    for (int i = 0; i < n;i++){
        for (int j = 0; j < 18;j++){
            cin >> s[i][j];
            if(j<17&&!(s[i][j]>='0'&&s[i][j]<='9')){
                sw[i]++;
                flag = 0;
            }
        }

        if(sw[i]==0){
            int sum = 0;
            for (int j = 0; j < 18;j++){
                sum += (int(s[i][j]-'0') * ss[j]);
            }
            if(x[sum%11]!=s[i][17]){
                sw[i]++;
                flag = 0;
            }
        }
    }

    if(flag){
        cout << "All passed" << endl;
    }
    else{
        for(int i=0;i<n;i++){
            if(sw[i]!=0){
                cout << s[i] << endl;
            }
        }
    }
        return 0;
}
