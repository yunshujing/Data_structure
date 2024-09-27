#include <stdio.h>  
//const int MaxSize = 100 + 5;  //顺序表的最大长度  
#define MaxSize (5)   //纯C语法，定义一个符号常量    
typedef int ElemType;    //当前顺序表的数据类型是整型     
typedef struct{ 
    ElemType a[MaxSize];//顺序表的元素   
    int n;  //顺序表的长度      
}SeqList;   
//输出系统菜单  
void printMenu();    
//0.输出顺序表sq    
void print(SeqList sq);  
//1.创建顺序表sq，写操作要用指针     
void create(SeqList *sq);    
//2.查找一个元素item在顺序表的位置；找不到返回-1    
int findPos(SeqList sq,ElemType item);  
//3.在顺序表的第i个位置插入一个元素item，插入成功返回1；失败返回-1  
int insert(SeqList *sq,int i,ElemType item);    
//4.删除顺序表第i个位置的元素   
int del(SeqList *sq,int i);  
//5.修改顺序表第i个位置的元素   
int modify(SeqList *sq,int i,ElemType item);     
//6.对顺序表sq排序   
void sort(SeqList *sq); 
//7.在有序的顺序表中插入一个元素item    
void insertSorted(SeqList *sq,ElemType item);   
//8.合并2个有序表s1和s2到新表sq  
void mergeSorted(SeqList *sq,SeqList s1,SeqList s2);    

int main()  
{   
    //打印主菜单     
    printMenu();     
    int choice,p,x;  //用户选择，位置，插入元素  
    SeqList sq;   //初始化顺序表为空表  
    sq.n = 0;    
    //进入菜单循环   
    while(~scanf("%d",&choice)){    
        switch(choice){ 
            case 0: printf("0.输出顺序表\n");   
                    print(sq);  
                    break;      
            case 1: printf("1.创建顺序表\n");   
                    create(&sq);
                    while(sq.n>MaxSize){
                        printf("超出最大长度创建失败，请重新创建\n"); 
                        create(&sq);
                    }
                    printf("创建成功，输出顺序表\n");   
                    print(sq);  
                    break;  
            case 2: printf("2.查找一个元素item在顺序表的位置\n");       
                    //*********必做1，请补全代码**************   
                    printf("请输入查找元素：");
                    int item;
                    scanf("%d",&item);
                    if(findPos(sq,item)==-1){
                        printf("没有找到元素！\n");
                    }
                    else{
                        printf("找到元素位置：%d\n",findPos(sq,item));
                    }
                    //**************************************/   
                    break;  
            case 3: printf("3.在顺序表第i个位置插入一个元素item\n");     
                    printf("请输入插入的位置和元素："); 
                    scanf("%d%d",&p,&x);     
                    if(insert(&sq,p,x) == -1){  
                        printf("表已满！\n"); 
                    }
                    else if(insert(&sq,p,x) == -2){  
                        printf("插入位置不对！\n"); 
                    }
                    print(sq);
                    break;  
            case 4: printf("4.删除顺序表第i个位置的元素\n");   
                    //*********必做2，请补全代码**************   
                    printf("请输入删除的位置："); 
                    scanf("%d",&p);     
                    if(del(&sq,p) == -1){  
                        printf("删除失败！\n"); 
                    }   
                    else{   
                        print(sq);    
                    }   
                    break;
                    //**************************************/   
                    break;   
            case 5: printf("5.修改顺序表第i个位置的元素\n");   
                    //*********选做1，请补全代码************** 
                    printf("请输入修改顺序表的位置和元素："); 
                    scanf("%d%d",&p,&x);     
                    if(modify(&sq,p,x) == -1){  
                        printf("修改失败！\n"); 
                    }   
                    else{   
                        print(sq);    
                    }   
                    break;
                    //**************************************/   
                    break;   
                        
            case 6: printf("6.对顺序表sq排序\n");  
                    //*********选做2，请补全代码**************
                    sort(&sq);
                    print(sq);
                    //**************************************/   
                    break;   
            case 7: printf("7.在有序的顺序表中插入一个元素item\n");    
                    //*********选做3，请补全代码**************
                    printf("注意：该算法将自动排序后再插入！\n");
                    sort(&sq);
                    printf("请输入插入元素：");
                    scanf("%d",&x);
                    if(findPos(sq,x)!=-1){
                        printf("表中已有该元素，是否继续插入：（Y/N)");
                        char w;
                        getchar();
                        scanf("%c",&w);
                        if(w=='Y'||w=='y'){
                            insertSorted(&sq, x);
                            print(sq);
                        }
                        if(w=='N'||w=='n'){
                            print(sq);
                        }
                    }
                    else{
                        insertSorted(&sq, x);
                        print(sq);
                    }
                    //**************************************/   
                    break;   
            case 8: printf("8.合并有序表\n");  
                    SeqList s1,s2;  
                    printf("请输入2个有序表（务必从小到大排序）：\n");  
                    create(&s1);
                    while(s1.n>MaxSize){
                        printf("超出最大长度创建失败，请重新创建\n"); 
                        create(&s1);
                    }
                    printf("创建成功，请继续创建第二个有序表（长度不超过%d）\n",MaxSize-s1.n); 
                    create(&s2); 
                    while(s2.n>MaxSize-s1.n){
                        printf("超出最大长度创建失败，请重新创建\n"); 
                        create(&s2);
                    }
                    printf("创建成功\n"); 
                    //*********必做3，请补全代码**************
                    mergeSorted(&sq, s1, s2);
                    print(sq);
                    //**************************************/   
                    break;
            case 19:printMenu();    
                    return 0;   
            case 20:printf("系统即将退出，欢迎再次使用！\n");   
                    break;  
            default:    
                    printf("你的选择有误，请重新输入！\n"); 
        }   
    }    
            
    return 0;   
}    
//输出系统菜单  
void printMenu()    
{   
    printf("欢迎进入顺序表操作子系统!\n");  
    printf("--------------------------------------------\n");    
    printf("0.输出顺序表\n");
    printf("1.创建顺序表\n");    
    printf("2.查找一个元素item在顺序表的位置\n");       
    printf("3.在顺序表第i个位置插入一个元素item\n");     
    printf("4.删除顺序表第i个位置的元素\n");        
    printf("5.修改顺序表第i个位置的元素\n");     
    printf("*******************************************\n");                    
    printf("6.对顺序表sq排序\n");    
    printf("7.在有序的顺序表中插入一个元素item\n");  
    printf("8.合并有序表\n");    
    printf("*******************************************\n");                        
    printf("9.预留功能\n");  
    printf("*******************************************\n");     
    printf("19.输出系统菜单\n");                
    printf("20.退出系统\n");     
    printf("--------------------------------------------\n");       
}   

//0.输出顺序表sq    
void print(SeqList sq){
    printf("顺序表的长度是：%d\n",sq.n);    
    for(int i = 0;i < sq.n;i++){    
        printf("%d ",sq.a[i]);  
    }   
    printf("\n");    
}   
//1.创建顺序表sq，写操作要用指针     
void create(SeqList *sq){   
    printf("请输入顺序表的元素（ctrl+z结束输入）：\n"); 
    int n = 0,x;    
    while(~scanf("%d",&x)){//while(scanf("%d",&x) == 1) 
        sq->a[n] = x;   
        n++;    
    }   
    sq->n = n;   
}   
//2.查找一个元素item在顺序表的位置；找不到返回-1    
int findPos(SeqList sq,ElemType item){  
    //*********必做4，请补全代码**************   
    for (int i = 0; i < sq.n; i++){
        if(sq.a[i]==item){
            return i+1;
        }
    }
    //**************************************/    
    return -1;  
}   
//3.在顺序表的第i个位置插入一个元素item，插入成功返回1；失败返回-1  
int insert(SeqList *sq,int i,ElemType item){    
    //0.表满或者插入位置不对，插入失败   
    if(sq->n == MaxSize ){ 
        return -1;  
    } 
    if(i < 1 || i > sq->n + 1){
        return -2;
    }
    //1.[i - 1,n - 1]的元素从后往前依次后移一个位置  
    for(int j = sq->n - 1;j >= i - 1;j--){  
        sq->a[j + 1] = sq->a[j];    
    }   
    //2.插入元素item到i-1   
    sq->a[i - 1] = item;    
    //3.修改表的长度     
    (sq->n)++;  
    return 1;    
}   
//4.删除顺序表第i个位置的元素   
int del(SeqList *sq,int i){   
    //*********必做5，请补全代码**************
    if( i < 1 || i >= sq->n ){ 
        return -1;  
    } 
    for(int j = i-1;j < sq->n;j++){  
        sq->a[j] = sq->a[j+1];    
    }    
    (sq->n)--;  
    return 1;
    //**************************************/
}    
//5.修改顺序表第i个位置的元素   
int modify(SeqList *sq,int i,ElemType item){  
    //*********选做4，请补全代码**************   
    if(i>0&&i<sq->n+1){
        sq->a[i-1] = item;
        return 1;
    }
    //**************************************/    
    return -1;  
}    
//6.对顺序表sq排序   
void sort(SeqList *sq){ 
    //*********选做5，请补全代码**************
    int temp;  
    for (int round = 0; round < sq->n - 1; round++) {
        for (int i = 0; i < sq->n - round - 1; i++) { 
            if (sq->a[i] > sq->a[i + 1]) {
                temp = sq->a[i];  
                sq->a[i] = sq->a[i + 1];  
                sq->a[i + 1] = temp; 
            }
        }
    }
    //**************************************/    
}   
//7.在有序的顺序表中插入一个元素item    
void insertSorted(SeqList *sq,ElemType item){   
    //*********选做6，请补全代码**************  
    if (sq->n >= MaxSize){
        printf("插入空间不足！\n");
        return;
    }
    for (int p = 0; p < sq->n; p++)
    {
        if(sq->a[p]>=item){
            insert(sq, p+1, item);
            printf("插入成功！\n");
            return;
        }
    }
    //**************************************/    
}   
//8.合并2个有序表s1和s2到新表sq  
void mergeSorted(SeqList *sq,SeqList s1,SeqList s2){    
    //*********必做6，请补全代码**************   
    int i = 0, j = 0, k = 0; 
    while (i < s1.n && j < s2.n) {  
        if (s1.a[i] < s2.a[j]) {  
            sq->a[k++] = s1.a[i++];  
        } else {  
            sq->a[k++] = s2.a[j++];  
        }  
    }  
    while (i < s1.n) {  
        sq->a[k++] = s1.a[i++];  
    }  
    while (j < s2.n) {  
        sq->a[k++] = s2.a[j++];  
    }    
    sq->n = k;
    //**************************************/    
}
