#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef int VexType;
typedef VexType Mgraph[MAX][MAX];/* Mgraph�Ƕ�ά�������ͱ�ʶ�� */
/* ����������ʾ */
void creat_mg(Mgraph G);
void out_mg(Mgraph G);  /* G1���ڽӾ���Ķ�ά������ */
void printDegree(Mgraph G);
Mgraph G1;
int n, e, v0;
/* ������ */
int main(){
    creat_mg(G1);
    out_mg(G1);
    printDegree(G1);
}
 /* �����ڽӾ��� */
void creat_mg(Mgraph G){
    int i, j, k;
    printf("\n  n,e=?");
    scanf("%d%d", &n, &e);/* ���붥����n,e */
    for (int i =1; i <= n; i++){
        for (int j = 0; j <= n;j++){
            G[i][j] = 0;
        }
    }
    for (int k = 1; k <= e;k++){
        printf("\n  vi,vj=?");
        scanf("%d%d", &i, &j);
        G[i][j] = 1;
        G[j][i] = 1;
    }
}
void out_mg(Mgraph G){
    int i, j, k;
    char ch;
    for (i = 1; i <= n;i++){
        printf("\n");
        for (j = 1; j <= n;j++){
            printf("%5d", G[i][j]);
        }
    }
    for (i = 1; i <= n;i++){
        for (j = 1; j <= n; j++)
        {
            if(G[i][j]==1){
                printf("\n ���ڱ�< %d,%d >",i, j);
            }
            
        }
    }
}
void printDegree(Mgraph G){
    int degree;
    for (int i = 1; i <= n; i++) {
        degree = 0;
        for (int j = 1; j <= n; j++) {
            if (G[i][j] == 1) {
                degree++;
            }
        }
        printf("\n���� %d �Ķ�Ϊ %d", i, degree);
    }
}