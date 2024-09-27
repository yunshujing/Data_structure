#include <stdio.h>
void merge(int *a1, int m, int *a2, int n) {
    int i = 0, j = 0, k = 0,res[m + n];
    while (i < m && j < n) {
        if (a1[i] <= a2[j]) {
            res[k++] = a1[i++];
        } else {
            res[k++] = a2[j++];
        }
    }
    while (i < m) {
        res[k++] = a1[i++];
    }
    while (j < n) {
        res[k++] = a2[j++];
    }
    for (int x = 0; x < m + n; x++) {
        printf("%d", res[x]);
        if (x < m + n - 1) {
            printf(" ");
        }
    }
}

int main() {
    int m, n;
    scanf("%d", &m);
    int a1[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &a1[i]);
    }
    scanf("%d", &n);
    int a2[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a2[i]);
    }
    merge(a1, m, a2, n);

    return 0;
}
