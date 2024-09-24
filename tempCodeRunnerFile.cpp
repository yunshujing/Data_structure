void Print(Complex x){
    if (!(abs(x.real)<0.1)){printf("%+d", x.real);}
    if (x.imag > 0){
        if (x.real != 0){printf(" + ");}
        if (x.imag != 1){printf("%di", x.imag);}
        else{printf("i");}
    }
    else if (x.imag < 0){ 
        if (x.real != 0){printf(" - ");}
        if (x.imag != -1){printf("%di", -x.imag);}
        else{printf("i");}
    }
    if (x.real == 0 && x.imag == 0){printf("0");}
}




void bubble_sort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        bool flag = 0; 
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1; 
            }
        }
        if (!flag) {
            break;
        }
    }
}
#include <stdio.h>
typedef struct {
    int real;
    int imag;
} Complex;
Complex create(int a, int b) {
    Complex comp;
    comp.real = a;
    comp.imag = b;
    return comp;
}

int GetCompReal(Complex x) {
    return x.real;
}
int GetCompImag(Complex x) {
    return x.imag;
}

Complex Add(Complex x, Complex y) {
    Complex result;
    result.real = x.real + y.real;
    result.imag = x.imag + y.imag;
    return result;
}
Complex Subtract(Complex x, Complex y) {
    Complex result;
    result.real = x.real - y.real;
    result.imag = x.imag - y.imag;
    return result;
}
Complex Multiply(Complex x, Complex y) {
    Complex result;
    result.real = x.real * y.real - x.imag * y.imag;
    result.imag = x.real * y.imag + x.imag * y.real;
    return result;
}