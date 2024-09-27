#include <stdio.h>
#define MaxSize (100)     //纯C语法，定义一个符号常量 
typedef int ElemType;     //当前顺序表的数据类型是整型 
typedef struct{
    ElemType a[MaxSize];//顺序表的元素 
    int n;    //顺序表的长度     
}SeqList;

//输出顺序表sq，细节不表 
void print(SeqList sq); 
//创建顺序表sq，细节不表 
void create(SeqList *sq); 
//删除顺序表第i个位置的元素
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
// 请在这里填写答案

//删除顺序表第i个位置的元素
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