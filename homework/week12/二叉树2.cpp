#include <stdio.h> //输入输出-scanf printf  
#include <stdlib.h>//分配内存-malloc free  
#include <string.h>//字符串函数strlen  
const int N = 100 + 5;   
//定义二叉树的结点-二叉链表 Binary Tree   
typedef struct node{  
    char data;  //结点数据-字符类型  
    struct node *lchild,*rchild;    //左孩子和右孩子   
}BNode,*BTree;   
//11.22二叉树的创建和遍历   
//1.先序遍历DLR，树根->左子树->右子树   
void preOrder(BTree T);   
//2.中序遍历LDR，左子树->树根->右子树   
void inOrder(BTree T);   
//3.后序遍历LRD，左子树->右子树->树根  
void postOrder(BTree T);  
//1129二叉树的还原和应用  
//1.根据先序遍历和中序遍历还原二叉树   
BTree createTreePreIn(char *pre,char *in,int len);   
//2.根据后序遍历和中序遍历还原二叉树-自己完成   
BTree createTreeInPost(char *in,char *post,int len);   
//3.求二叉树的高度  
int getHeight(BTree T);  
//4.求二叉树的叶子数  
int getLeafCnt(BTree T);  
//5.求二叉树的结点数   
int getNodeCnt(BTree T);   
/*************** 
abdefgc 
dbfegac
dfgebca 
-+a*b-cd/ef 
a+b*c-d-e/f 
abcd-*+ef/-
ABDEJCFIG 
DBJEAFICG 
DJEBIFGCA 
**************/   
int main(){  
    //freopen("btree1.in","r",stdin);   
    char pre[N],in[N]; 
	printf("1.根据先序遍历和中序遍历还原二叉树:\n");
    scanf("%s%s",pre,in);
    int n = strlen(pre);    //求字符串的长度  
    BTree T = createTreePreIn(pre,in,n);  
    printf("\n先序遍历：");  
    preOrder(T);   
    printf("\n中序遍历：");  
    inOrder(T);   
    printf("\n后序遍历：");  
    postOrder(T);     
    printf("\n二叉树的高度：%d",getHeight(T));  
    printf("\n二叉树的叶子数：%d",getLeafCnt(T));     
    printf("\n二叉树的结点数：%d",getNodeCnt(T));         
    printf("\n\n");  
	char post[N];    
    printf("2.根据后序遍历和中序遍历还原二叉树:\n");
    scanf("%s%s",in,post);
    n = strlen(in);    //求字符串的长度  
    T = createTreeInPost(in,post,n);  
    printf("\n先序遍历：");  
    preOrder(T);   
    printf("\n中序遍历：");  
    inOrder(T);   
    printf("\n后序遍历：");  
    postOrder(T);     
    printf("\n二叉树的高度：%d",getHeight(T));  
    printf("\n二叉树的叶子数：%d",getLeafCnt(T));     
    printf("\n二叉树的结点数：%d",getNodeCnt(T));         
    printf("\n\n"); 
    return 0;  
}  

//1.根据先序遍历和中序遍历还原二叉树   
//先序确定树根，中序分左右   
//pre-先序遍历字符串，in-中序遍历字符串，len-长度   
BTree createTreePreIn(char *pre,char *in,int len){  
    //1.边界条件，字符串长度为0，则为空树  
    if(len == 0)    return NULL;  
    //创建一棵二叉树，分配内存   
    BTree T =  (BTree)malloc(sizeof(BNode));  
    //2.先序确定树根   
    T->data = pre[0];      
    //3.中序分左右  
    int n = -1;  
    for(int i = 0;i < len;i++){  
        if(in[i] == pre[0])  
            n = i;  
    }   
    //3.1创建左子树,递归调用   
    T->lchild = createTreePreIn(pre + 1,in,n);  
    //3.2创建右子树   
    T->rchild = createTreePreIn(pre + 1 + n,in + n + 1,len - 1 - n);  
    return T;  
}

//2.根据后序遍历和中序遍历还原二叉树-自己完成   
BTree createTreeInPost(char *in,char *post,int len){
	//1.边界条件，字符串长度为0，则为空树  
    if(len == 0)    return NULL;  
    //创建一棵二叉树，分配内存   
    BTree T =  (BTree)malloc(sizeof(BNode));  
    //2.后序确定树根   
    T->data = post[len-1];      
    //3.中序分左右  
    int n = len;  
    for(int i = 0;i < len;i++){  
        if(in[i] == post[n-1])  
            n=i;  
    }   
    //3.1创建左子树,递归调用   
    T->lchild = createTreeInPost(in,post,n);  
    //3.2创建右子树   
    T->rchild = createTreeInPost(in+n+1,post+n,len - 1 - n);  
    return T;  
}  

//3.求二叉树的高度  
int getHeight(BTree T){  
    if(T == NULL)   return 0;   //空树高度为0  
    int lt = getHeight(T->lchild);   //左子树高度   
    int rt = getHeight(T->rchild);  //右子树高度  
    int n = lt;   
    if(rt > n)  
        n = rt;  
    return n + 1;   //返回左子树和右子树高度最大值+1   
}  

//4.求二叉树的叶子数  
int getLeafCnt(BTree T){  
	int cnt=0;
    if(T!=NULL)
    { 
        if (T->lchild == NULL && T->rchild == NULL){
            cnt++;
        }
        cnt+=getLeafCnt(T->lchild);
        cnt+=getLeafCnt(T->rchild);
    } 
	return cnt;  
}

//5.求二叉树的结点数   
int getNodeCnt(BTree T){  
    int cnt=0; // 对于每个根节点(递归中形参的不同导致对应的根节点不同)
    if(T!=NULL)
    {
        cnt++; // 如果树根指针不为空 代表此时从这个根节点开始 计数器先+1统计根节点
        // 对于每个根节点的左右子树 递归求对每个不同的根节点来说的节点个数
        cnt+=getNodeCnt(T->lchild);
        cnt+=getNodeCnt(T->rchild);
    }
    // 递归出口 也可以显式地表示为if(T==NULL)
    return cnt;
}   

//访问树根  
void visit(BTree T){  
    printf("%c",T->data);      
}   

//1.先序遍历DLR，树根->左子树->右子树   
void preOrder(BTree T){  
    if(T == NULL) return;  
    visit(T);  
    preOrder(T->lchild);  
    preOrder(T->rchild);   
}   

//2.中序遍历LDR，左子树->树根->右子树   
void inOrder( BTree T ){
    if(T == NULL) return;
    else{
        inOrder(T->lchild);
        visit(T);
        inOrder(T->rchild);
    }
}  

//3.后序遍历LRD，左子树->右子树->树根  
void postOrder( BTree T ){
    if(T == NULL) return;
    else{
        postOrder(T->lchild);
        postOrder(T->rchild);
        visit(T);
    }
}  