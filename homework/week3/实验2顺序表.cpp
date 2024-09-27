#include <stdio.h>  
//const int MaxSize = 100 + 5;  //˳������󳤶�  
#define MaxSize (5)   //��C�﷨������һ�����ų���    
typedef int ElemType;    //��ǰ˳������������������     
typedef struct{ 
    ElemType a[MaxSize];//˳����Ԫ��   
    int n;  //˳���ĳ���      
}SeqList;   
//���ϵͳ�˵�  
void printMenu();    
//0.���˳���sq    
void print(SeqList sq);  
//1.����˳���sq��д����Ҫ��ָ��     
void create(SeqList *sq);    
//2.����һ��Ԫ��item��˳����λ�ã��Ҳ�������-1    
int findPos(SeqList sq,ElemType item);  
//3.��˳���ĵ�i��λ�ò���һ��Ԫ��item������ɹ�����1��ʧ�ܷ���-1  
int insert(SeqList *sq,int i,ElemType item);    
//4.ɾ��˳����i��λ�õ�Ԫ��   
int del(SeqList *sq,int i);  
//5.�޸�˳����i��λ�õ�Ԫ��   
int modify(SeqList *sq,int i,ElemType item);     
//6.��˳���sq����   
void sort(SeqList *sq); 
//7.�������˳����в���һ��Ԫ��item    
void insertSorted(SeqList *sq,ElemType item);   
//8.�ϲ�2�������s1��s2���±�sq  
void mergeSorted(SeqList *sq,SeqList s1,SeqList s2);    

int main()  
{   
    //��ӡ���˵�     
    printMenu();     
    int choice,p,x;  //�û�ѡ��λ�ã�����Ԫ��  
    SeqList sq;   //��ʼ��˳���Ϊ�ձ�  
    sq.n = 0;    
    //����˵�ѭ��   
    while(~scanf("%d",&choice)){    
        switch(choice){ 
            case 0: printf("0.���˳���\n");   
                    print(sq);  
                    break;      
            case 1: printf("1.����˳���\n");   
                    create(&sq);
                    while(sq.n>MaxSize){
                        printf("������󳤶ȴ���ʧ�ܣ������´���\n"); 
                        create(&sq);
                    }
                    printf("�����ɹ������˳���\n");   
                    print(sq);  
                    break;  
            case 2: printf("2.����һ��Ԫ��item��˳����λ��\n");       
                    //*********����1���벹ȫ����**************   
                    printf("���������Ԫ�أ�");
                    int item;
                    scanf("%d",&item);
                    if(findPos(sq,item)==-1){
                        printf("û���ҵ�Ԫ�أ�\n");
                    }
                    else{
                        printf("�ҵ�Ԫ��λ�ã�%d\n",findPos(sq,item));
                    }
                    //**************************************/   
                    break;  
            case 3: printf("3.��˳����i��λ�ò���һ��Ԫ��item\n");     
                    printf("����������λ�ú�Ԫ�أ�"); 
                    scanf("%d%d",&p,&x);     
                    if(insert(&sq,p,x) == -1){  
                        printf("��������\n"); 
                    }
                    else if(insert(&sq,p,x) == -2){  
                        printf("����λ�ò��ԣ�\n"); 
                    }
                    print(sq);
                    break;  
            case 4: printf("4.ɾ��˳����i��λ�õ�Ԫ��\n");   
                    //*********����2���벹ȫ����**************   
                    printf("������ɾ����λ�ã�"); 
                    scanf("%d",&p);     
                    if(del(&sq,p) == -1){  
                        printf("ɾ��ʧ�ܣ�\n"); 
                    }   
                    else{   
                        print(sq);    
                    }   
                    break;
                    //**************************************/   
                    break;   
            case 5: printf("5.�޸�˳����i��λ�õ�Ԫ��\n");   
                    //*********ѡ��1���벹ȫ����************** 
                    printf("�������޸�˳����λ�ú�Ԫ�أ�"); 
                    scanf("%d%d",&p,&x);     
                    if(modify(&sq,p,x) == -1){  
                        printf("�޸�ʧ�ܣ�\n"); 
                    }   
                    else{   
                        print(sq);    
                    }   
                    break;
                    //**************************************/   
                    break;   
                        
            case 6: printf("6.��˳���sq����\n");  
                    //*********ѡ��2���벹ȫ����**************
                    sort(&sq);
                    print(sq);
                    //**************************************/   
                    break;   
            case 7: printf("7.�������˳����в���һ��Ԫ��item\n");    
                    //*********ѡ��3���벹ȫ����**************
                    printf("ע�⣺���㷨���Զ�������ٲ��룡\n");
                    sort(&sq);
                    printf("���������Ԫ�أ�");
                    scanf("%d",&x);
                    if(findPos(sq,x)!=-1){
                        printf("�������и�Ԫ�أ��Ƿ�������룺��Y/N)");
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
            case 8: printf("8.�ϲ������\n");  
                    SeqList s1,s2;  
                    printf("������2���������ش�С�������򣩣�\n");  
                    create(&s1);
                    while(s1.n>MaxSize){
                        printf("������󳤶ȴ���ʧ�ܣ������´���\n"); 
                        create(&s1);
                    }
                    printf("�����ɹ�������������ڶ�����������Ȳ�����%d��\n",MaxSize-s1.n); 
                    create(&s2); 
                    while(s2.n>MaxSize-s1.n){
                        printf("������󳤶ȴ���ʧ�ܣ������´���\n"); 
                        create(&s2);
                    }
                    printf("�����ɹ�\n"); 
                    //*********����3���벹ȫ����**************
                    mergeSorted(&sq, s1, s2);
                    print(sq);
                    //**************************************/   
                    break;
            case 19:printMenu();    
                    return 0;   
            case 20:printf("ϵͳ�����˳�����ӭ�ٴ�ʹ�ã�\n");   
                    break;  
            default:    
                    printf("���ѡ���������������룡\n"); 
        }   
    }    
            
    return 0;   
}    
//���ϵͳ�˵�  
void printMenu()    
{   
    printf("��ӭ����˳��������ϵͳ!\n");  
    printf("--------------------------------------------\n");    
    printf("0.���˳���\n");
    printf("1.����˳���\n");    
    printf("2.����һ��Ԫ��item��˳����λ��\n");       
    printf("3.��˳����i��λ�ò���һ��Ԫ��item\n");     
    printf("4.ɾ��˳����i��λ�õ�Ԫ��\n");        
    printf("5.�޸�˳����i��λ�õ�Ԫ��\n");     
    printf("*******************************************\n");                    
    printf("6.��˳���sq����\n");    
    printf("7.�������˳����в���һ��Ԫ��item\n");  
    printf("8.�ϲ������\n");    
    printf("*******************************************\n");                        
    printf("9.Ԥ������\n");  
    printf("*******************************************\n");     
    printf("19.���ϵͳ�˵�\n");                
    printf("20.�˳�ϵͳ\n");     
    printf("--------------------------------------------\n");       
}   

//0.���˳���sq    
void print(SeqList sq){
    printf("˳���ĳ����ǣ�%d\n",sq.n);    
    for(int i = 0;i < sq.n;i++){    
        printf("%d ",sq.a[i]);  
    }   
    printf("\n");    
}   
//1.����˳���sq��д����Ҫ��ָ��     
void create(SeqList *sq){   
    printf("������˳����Ԫ�أ�ctrl+z�������룩��\n"); 
    int n = 0,x;    
    while(~scanf("%d",&x)){//while(scanf("%d",&x) == 1) 
        sq->a[n] = x;   
        n++;    
    }   
    sq->n = n;   
}   
//2.����һ��Ԫ��item��˳����λ�ã��Ҳ�������-1    
int findPos(SeqList sq,ElemType item){  
    //*********����4���벹ȫ����**************   
    for (int i = 0; i < sq.n; i++){
        if(sq.a[i]==item){
            return i+1;
        }
    }
    //**************************************/    
    return -1;  
}   
//3.��˳���ĵ�i��λ�ò���һ��Ԫ��item������ɹ�����1��ʧ�ܷ���-1  
int insert(SeqList *sq,int i,ElemType item){    
    //0.�������߲���λ�ò��ԣ�����ʧ��   
    if(sq->n == MaxSize ){ 
        return -1;  
    } 
    if(i < 1 || i > sq->n + 1){
        return -2;
    }
    //1.[i - 1,n - 1]��Ԫ�شӺ���ǰ���κ���һ��λ��  
    for(int j = sq->n - 1;j >= i - 1;j--){  
        sq->a[j + 1] = sq->a[j];    
    }   
    //2.����Ԫ��item��i-1   
    sq->a[i - 1] = item;    
    //3.�޸ı�ĳ���     
    (sq->n)++;  
    return 1;    
}   
//4.ɾ��˳����i��λ�õ�Ԫ��   
int del(SeqList *sq,int i){   
    //*********����5���벹ȫ����**************
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
//5.�޸�˳����i��λ�õ�Ԫ��   
int modify(SeqList *sq,int i,ElemType item){  
    //*********ѡ��4���벹ȫ����**************   
    if(i>0&&i<sq->n+1){
        sq->a[i-1] = item;
        return 1;
    }
    //**************************************/    
    return -1;  
}    
//6.��˳���sq����   
void sort(SeqList *sq){ 
    //*********ѡ��5���벹ȫ����**************
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
//7.�������˳����в���һ��Ԫ��item    
void insertSorted(SeqList *sq,ElemType item){   
    //*********ѡ��6���벹ȫ����**************  
    if (sq->n >= MaxSize){
        printf("����ռ䲻�㣡\n");
        return;
    }
    for (int p = 0; p < sq->n; p++)
    {
        if(sq->a[p]>=item){
            insert(sq, p+1, item);
            printf("����ɹ���\n");
            return;
        }
    }
    //**************************************/    
}   
//8.�ϲ�2�������s1��s2���±�sq  
void mergeSorted(SeqList *sq,SeqList s1,SeqList s2){    
    //*********����6���벹ȫ����**************   
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
