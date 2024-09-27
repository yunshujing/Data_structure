#include <stdio.h>
#define MaxSize (100)     //��C�﷨������һ�����ų��� 
typedef int ElemType;     //��ǰ˳������������������ 
typedef struct{
    ElemType a[MaxSize];//˳����Ԫ�� 
    int n;    //˳���ĳ���     
}SeqList;

//���˳���sq��ϸ�ڲ��� 
void print(SeqList sq); 
//����˳���sq��ϸ�ڲ��� 
void create(SeqList *sq); 
//ɾ��˳����i��λ�õ�Ԫ��
int del(SeqList *sq,int i); 
int main()
{
    SeqList sq;
    create(&sq);
    int i;
    scanf("%d",&i);
    int res = del(&sq,i);
    if(res == -1){
        printf("Delete Error.The value of i is illegal!");    
    }else if(res == 1){
        printf("Delete Success.The elements of the SequenceList are:\n");    
        print(sq);
    }
    return 0;
} 
// ����������д��

//ɾ��˳����i��λ�õ�Ԫ��
int del(SeqList *sq,int i){
    int j;i--;
    if ((i < 0) || (i > sq->n - 1))
        return -1;
    else{
        for (j = i; j < sq->n - 1; j++)
            sq->a[j] = sq->a[j + 1];
        sq->n--;
        return 1;
    }
}