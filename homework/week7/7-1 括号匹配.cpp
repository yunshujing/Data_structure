#include<bits/stdc++.h>
using namespace std;
#define int long long

stack <char> num;
signed main() {
    string a; int cnt = 0; bool flag = 1;
    getline(cin, a);
    for (char x: a) {
            if (x == '('||x == '{'||x == '[')num.push(x);   //��ջǰ����
            else if (x == ')') {    //���ݲ�ͬ���Ž���ƥ��
                if (!num.empty()&&num.top()== '(')num.pop();	       
                else { flag = 0; break;  }
            }
            else if (x == '}') {
                if (!num.empty()&&num.top()== '{')num.pop();	       
                else { flag = 0; break;  }
            }
            else if (x == ']') {
                if (!num.empty()&&num.top()== '[')num.pop();	       
                else { flag = 0; break;  }
            }
    }
    if (num.empty()&&flag) cout << "yes" << endl;
    else cout << "no";
}