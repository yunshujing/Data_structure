#include<bits/stdc++.h>
using namespace std;
#define int long long
// #define float long float
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout.tie(0);
    cout << fixed << setprecision(6);

    float a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    float s1 = a1 + a2;
    float s2 = b1 + b2;
    if(abs(s1)< 0.1 && abs(s2)< 0.1){
        printf("(%.1f%+.1fi) + (%.1f%+.1fi) = 0.0\n",a1, b1, a2, b2);
    }
    else if(abs(s1)< 0.1){
        printf("(%.1f%+.1fi) + (%.1f%+.1fi) = %.1fi\n", a1, b1, a2, b2, s2);
    }
    else if(abs(s2)< 0.1){
        printf("(%.1f%+.1fi) + (%.1f%+.1fi) = %.1f\n", a1, b1, a2, b2, s1);
    }
    else{
        printf("(%.1f%+.1fi) + (%.1f%+.1fi) = %.1f%+.1fi\n", a1, b1, a2, b2, s1, s2);
    }

    float s3 = a1 - a2;
    float s4 = b1 - b2;
    if(abs(s3)< 0.1&&abs(s4)< 0.1){
        printf("(%.1f%+.1fi) - (%.1f%+.1fi) = 0.0\n",a1, b1, a2, b2);
    }
    else if(abs(s3)< 0.1){
        printf("(%.1f%+.1fi) - (%.1f%+.1fi) = %.1fi\n", a1, b1, a2, b2, s4);
    }
    else if(abs(s4)< 0.1){
        printf("(%.1f%+.1fi) - (%.1f%+.1fi) = %.1f\n", a1, b1, a2, b2, s3);
    }
    else{
        printf("(%.1f%+.1fi) - (%.1f%+.1fi) = %.1f%+.1fi\n", a1, b1, a2, b2, s3, s4);
    } 

    float s5 = a1*a2 - b1*b2;
    float s6 = a2*b1 + a1*b2;
    if(abs(s5)< 0.1&&abs(s6)< 0.1){
        printf("(%.1f%+.1fi) * (%.1f%+.1fi) = 0.0\n",a1, b1, a2, b2);
    }
    else if(abs(s5)< 0.1){
        printf("(%.1f%+.1fi) * (%.1f%+.1fi) = %.1fi\n", a1, b1, a2, b2, s6);
    }
    else if(abs(s6)< 0.1){
        printf("(%.1f%+.1fi) * (%.1f%+.1fi) = %.1f\n", a1, b1, a2, b2, s5);
    }
    else{
        printf("(%.1f%+.1fi) * (%.1f%+.1fi) = %.1f%+.1fi\n", a1, b1, a2, b2, s5, s6);
    }

    float s7 = (a1*a2 + b1*b2)/(a2*a2+b2*b2);
    float s8 = -(a1*b2-b1*a2)/(a2*a2+b2*b2);
    if(abs(s7)< 0.1&&abs(s8)< 0.1){
        printf("(%.1f%+.1fi) / (%.1f%+.1fi) = 0.0\n",a1, b1, a2, b2);
    }
    else if(abs(s7)< 0.1){
        printf("(%.1f%+.1fi) / (%.1f%+.1fi) = %.1fi\n", a1, b1, a2, b2, s8);
    }
    else if(abs(s8)< 0.1){
        printf("(%.1f%+.1fi) / (%.1f%+.1fi) = %.1f\n", a1, b1, a2, b2, s7);
    }
    else{
        printf("(%.1f%+.1fi) / (%.1f%+.1fi) = %.1f%+.1fi\n", a1, b1, a2, b2, s7, s8);
    }
    
    return 0;
}