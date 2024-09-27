
#include <stdio.h>  
#include <string.h>
void swap(char (*str1)[11], char (*str2)[11]) {  
    char temp[11];   
    strcpy(temp, *str1);  
    strcpy(*str1, *str2); 
    strcpy(*str2, temp); 
}  
int main() {  
    int N, K;  
    scanf("%d %d", &N, &K);  
    char strings[N][11];  
    for (int i = 0; i < N; i++) {  
        scanf("%10s", strings[i]);
    }  
    for (int round = 0; round < K; round++) {  
        for (int i = 0; i < N - 1 - round; i++) {  
            if (strcmp(strings[i], strings[i + 1]) > 0) {  
                swap(&strings[i], &strings[i + 1]); 
            }  
        }  
    }  
    for (int i = 0; i < N; i++) {  
        printf("%s\n", strings[i]);  
    }  
    return 0;  
}