#include <stdio.h>
int main() {  
    int n, m;  
    scanf("%d %d", &n, &m);  
    int arr[n];  
    for (int i = 0; i < n; i++) {  
        scanf("%d", &arr[i]);  
    }
    m = m % n;
    for (int i = m; i < n+m-1; i++) {  
        printf("%d ", arr[i%n]);  
    }
    printf("%d", arr[(n+m-1)%n]);
    return 0;  
}
