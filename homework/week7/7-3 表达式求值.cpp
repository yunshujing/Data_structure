#include<bits/stdc++.h>
using namespace std;

double bds(const string& ss) {
    stack<double> stack;
    for (char ch : ss) {
        if (isdigit(ch)) {  // 是否为数字
            stack.push(ch - '0');
        } else {    //遇到符号则取值
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();

            switch (ch) {   //计算
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
            }
        }
    }
    return stack.top();
}

int main() {
    string ss;
    while (getline(cin, ss)) {
        cout << fixed << setprecision(2) << bds(ss) << endl;
    }
    return 0;
}