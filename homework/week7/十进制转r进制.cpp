#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const double eps =1e-4;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, x; 
    while(cin >> n >> x){
        stack<char> s;
        while (n > 0) {
            int tmp = n % x;    //ȡģ
            if (tmp >= 10) {    //����ʮ�����ASCII��ת��Ϊ��ĸ
                s.push('A' + tmp - 10);
            }
            else {
                s.push('0' + tmp - 0);
            }
            n /= x;
        }
        while (!s.empty()) {
            cout << s.top();
            s.pop();
        }
        cout << endl;
    }
    return 0;
}