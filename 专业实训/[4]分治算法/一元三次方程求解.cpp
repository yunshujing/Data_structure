#include <bits/stdc++.h>
using namespace std;
int main(){
    double a, b, c, d;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    double l, r, m, x1, x2;
    int s = 0;
    for (int i = -100; i < 100; i++){
        l = i;
        r = i + 1;
        x1 = a * l * l * l + b * l * l + c * l + d;
        x2 = a * r * r * r + b * r * r + c * r + d;
        if (!x1){
            printf("%.2lf ", l);
            s++;
        }
        if (x1 * x2 < 0){
            while (r - l >= 0.001){
                m = (l + r) / 2;
                if ((a * m * m * m + b * m * m + c * m + d) * (a * r * r * r + b * r * r + c * r + d) <= 0)
                    l = m;
                else
                    r = m;
            }
            printf("%.2lf ", r);
            s++;
        }
    }
}