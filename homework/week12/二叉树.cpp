/********************************* 
ABD##E##CF#G### 
***********************************/  
#include <stdio.h>    //输入输出printf,scanf  
#include <stdlib.h>   //内存分配malloc,free  
//二叉树的实现-二叉链表（左孩子，右孩子）  
typedef struct node{  
    char data;  //结点数据-字符类型  
    struct node *lchild,*rchild;    //左右孩子指针   
}BNode,*BTree;   
//0.创建二叉树-根据用户的输入   
BTree createTree();   
//访问二叉树T，打印根结点的数据   
void visit(BTree T);       
//1.先序遍历DLR，树根-左子树-右子树   
void preOrder(BTree T);   
//2.中序遍历LDR，左子树-树根-右子树   
void inOrder(BTree T);   
//3.后序遍历LRD，左子树-右子树-树根  
void postOrder(BTree T);   
//4.层次遍历-BFS(Breadth First Search)-用队列实现   
void layOrder(BTree T);   

//循环队列-代码   
#define M (1000 + 5)  
typedef BTree ElemType;   
typedef struct{  
    ElemType data[M];   //队列的数据   
    int front,rear;     //队列头部和尾部   
}SqCyQueue;  
//0.初始化队列  
void init(SqCyQueue *q);   
//1.队列是否为空，如果为空返回1，否则返回0   
int isEmpty(SqCyQueue q);   
//2.队列是否已满，如果满了返回1，否则返回0   
int isFull(SqCyQueue q);   
//3.入队，如果成功返回1，否则返回0   
int push(SqCyQueue *q,ElemType item);  
//4.出队，如果成功返回1，否则返回0   
int pop(SqCyQueue *q,ElemType *item);   


int main(){
    //1.创建二叉树  
    BTree T = createTree();  
    //2.遍历并输出  
    printf("\n先序遍历：");  
    preOrder(T);   
    printf("\n中序遍历：");  
    inOrder(T);       
    printf("\n后序遍历：");  
    postOrder(T);   
    printf("\n层次遍历：");  
    layOrder(T);      
    return 0;  
}  

//0.创建二叉树-根据用户的输入   
BTree createTree(){  
    BTree T = NULL;  
    char ch;  
    while(1){  
        scanf("%c",&ch);    //输入数据  
        if(ch != '\n' && ch != ' ')   
            break;  
    }  
    if(ch != '#'){  
        //创建二叉树的根结点，分配内存并初始化指针   
        T = (BTree)malloc(sizeof(BNode));  
        T->lchild = T->rchild = NULL;  
        T->data = ch;    //读入结点的数据  
        //递归创建左子树和右子树  
        T->lchild = createTree();  
        T->rchild = createTree();      
    }   
    return T;  
}

//访问二叉树T，打印根结点的数据   
void visit(BTree T)  {  
    printf("%c",T->data);   
}   

//1.先序遍历DLR，树根-左子树-右子树   
void preOrder(BTree T)  {  
    if(T == NULL)   //空树直接返回      
        return;   
    visit(T);       //访问树根   
    preOrder(T->lchild);//先序遍历左子树   
    preOrder(T->rchild);//先序遍历右子树   
}

void inOrder( BTree T ){
    if(T == NULL) return;
    else{
        inOrder(T->lchild);
        visit(T);
        inOrder(T->rchild);
    }
}

void postOrder( BTree T ){
    if(T == NULL) return;
    else{
        postOrder(T->lchild);
        postOrder(T->rchild);
        visit(T);
    }
}

void layOrder(BTree T){
    BTree A[100];
    BTree p;
    int rear=0,front=0;
    if(T == NULL) return;
    else{
        A[rear++]=T;
        while(rear!=front){
            p=A[front++];
            visit(p);
            if(p->lchild)
                A[rear++]=p->lchild;
            if(p->rchild)
                A[rear++]=p->rchild;
        }
    }
}