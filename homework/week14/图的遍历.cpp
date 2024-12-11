//1.邻接表建有向图：单链表    
/****************************  
graph:图  
edge :边  
vertex:顶点 vex  
adjacent:邻接的 adj  
dfs:depth first search  深度优先搜索，栈（递归算法或手写栈）  
bfs:breadth first search广度优先搜索，队列  
//有向图   
4 5  
A B C D  
A B  
A C  
D A   
B C  
C D  
//无向图  
9 10  
1 2 3 4 5 6 7 8 9  
1 2  
1 3  
2 4  
2 5  
2 9  
3 6  
3 8  
4 7  
6 8  
7 9   
*******************************/    
#include <stdio.h>    //scanf printf getchar    
#include <string.h> //memset-内存初始化     
#include <stdlib.h> //malloc free     
#define N (100 + 5)    
#define INF (0x3f3f3f3f)//无穷大，16进制 00111111     
typedef char vexType;   //顶点类型为字符型     
int visited[N];         //状态数组，标记当前点有没有被访问过
//邻接边    
typedef struct edge{    
    int adjvex;         //邻接点的下标，从0开始    
    int weight;         //边的权重，可选项     
    struct edge *next;  //下一个邻接点的地址      
}ELink;     
//邻接点    
typedef struct{    
    vexType vertex;     //顶点的数据     
    ELink *edge;        //邻接边     
}VLink;    
//邻接表存图    
typedef struct{    
    int n,m;            //n个顶点，m条边    
    VLink vex[N];       //邻接点数组    
}adjListGraph;    
//1.邻接表建图    
void createGraph(adjListGraph *graph);     
//2.打印图    
void printGraph(adjListGraph graph);    
//3.输出图的度数(入度，出度，度数）    
void printDegree(adjListGraph graph);     
//4.1深度优先遍历-从下标为n的点出发    
void dfs(adjListGraph graph,int n);     
//4.2深度优先遍历-搜所有的点     
void dfsAll(adjListGraph graph);     
//5.1广度优先遍历-从下标为n的点出发    
void bfs(adjListGraph graph,int n);     
//5.2广度优先遍历-搜所有的点     
void bfsAll(adjListGraph graph);     
    
//循环队列-代码     
#define M (1000 + 5)    
typedef int ElemType;   //队列元素类型   
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
    //stdio - stdin 和 stdout    
    //stdin - standard input 标准输入设备（键盘）     
    //stdout- standard output标准输出设备（显示器）     
    //freopen("邻接表.txt","r",stdin);   //输入重定向为文件     
//  freopen("output.txt","w",stdout);   //输出重定向为文件    
    memset(visited,0,sizeof(visited));  //初始化所有的点都没访问过     
    adjListGraph g;    
    createGraph(&g);    
    printGraph(g);
    printDegree(g); 
    int n = 0;  
    printf("\n从%c点出发深度优先遍历\n",g.vex[n].vertex);     
    //从第1个点开始深搜     
    dfs(g,n); 
	printf("\n深度优先遍历-搜所有的点 \n"); 
	dfsAll(g); 
	memset(visited,0,sizeof(visited));    
    printf("\n从%c点出发广度优先遍历\n",g.vex[n].vertex);     
    //从第1个点开始广搜     
    bfs(g,n);
    printf("\n广度优先遍历-搜所有的点 \n"); 
	bfsAll(g);
    return 0;    
}     
//1.邻接表建图    
void createGraph(adjListGraph *graph)    
{    
    //1. 输入n个顶点和m条边    
    scanf("%d%d",&graph->n,&graph->m);    
    //2.输入n个顶点，存入图的n个邻接点中     
    for(int i = 0;i < graph->n;i++){    
        //读入的字符数据是不是有效的    
        while(1){    
            char c = getchar();    
            if(c >= 'A' && c <= 'Z' ||c >= '0' && c <= '9'){    
                graph->vex[i].vertex = c;    
                graph->vex[i].edge = NULL;       //指针初始化为空     
                break;    
            }    
        }     
    }    
    //3.依次输入m条边的2个顶点v1和v2 和权值w   
    for(int i = 0;i < graph->m;i++){    
        char v1,v2; 
		int w;   
        scanf("\n%c %c",&v1,&v2); 
		//scanf("\n%d",&w);    
        //3.1在邻接点数组vex中查找v1和v2的下标k1和k2    
        int k1,k2;    
        for(int j = 0;j < graph->n;j++){    
            if(graph->vex[j].vertex == v1)    
                k1 = j;    
            if(graph->vex[j].vertex == v2)    
                k2 = j;    
        }     
    //  printf("k1 = %d,k2 = %d\n",k1,k2);    
        //以k2为下标创建邻接边    
        //1）分配内存并初始化     
        ELink *p = (ELink*)malloc(sizeof(ELink));    
        p->adjvex = k2; 
		//p->weight=w;   
        p->next = NULL;     
        //2)把这条边加入k1对应的邻接点    
        //*************a.头插法*****************   
        p->next = graph->vex[k1].edge;//新结点指向表头   
        graph->vex[k1].edge = p;     //表头指向新结点   
        /*//*************b.尾插法*****************    
        //如果链表为空，则新结点p即为链表的表头    
        if(graph->vex[k1].edge == NULL)    
            graph->vex[k1].edge = p;    
        //否则先搜到链表的尾部，然后把新结点p加入到链表的尾部     
        else{    
            ELink *tail = graph->vex[k1].edge;    
            while(tail->next != NULL)    
                tail = tail->next;     
            tail->next = p;    
        }
        */    
        //无向图的话，另外加一条边，以k1为下标创建邻接边    
        //1）分配内存并初始化     
        ELink *q = (ELink*)malloc(sizeof(ELink));    
        q->adjvex = k1;    
        q->next = NULL;     
        //2)把这条边加入k2对应的逆邻接点    
        //*************a.头插法*****************   
        q->next = graph->vex[k2].edge;//新结点指向表头   
        graph->vex[k2].edge = q;     //表头指向新结点   
        /*//*************b.尾插法*****************  
        //如果链表为空，则新结点q即为链表的表头    
        if(graph->vex[k2].edge == NULL)    
            graph->vex[k2].edge = q;    
        //否则先搜到链表的尾部，然后把新结点p加入到链表的尾部     
        else{    
            ELink *tail = graph->vex[k2].edge;    
            while(tail->next != NULL)    
                tail = tail->next;     
            tail->next = q;    
        }               
        */    
    }    
}     
//2.打印图    
void printGraph(adjListGraph graph)    
{    
    //遍历图的n个邻接点     
    for(int i = 0;i < graph.n;i++){    
        //1.输出顶点数据    
        printf("%c",graph.vex[i].vertex);    
        //2.输出当前邻接点关联的邻接边    
        //遍历链表    
        ELink *p = graph.vex[i].edge;   //初始化为链表的表头    
        while(p){    
            int t = p->adjvex;       //邻接点下标     
            printf(" -> %d",t);      //输出下标     
        //  printf(" -> %c",graph.vex[t].vertex);    
            p = p->next;    
        }     
        printf("\n");    
    }     
}     
//3.输出图的度数(入度，出度，度数）    
void printDegree(adjListGraph graph)    
{    
    int i,j,in,out,count;
	for(i=0;i<graph.n;i++){
		in=out=count=0;
		for(j=0;j<graph.n;j++){
			ELink *tail1 = graph.vex[i].edge;    
	        while(tail1){
				if (tail1->adjvex==j){
					out++;
					break;
				} 
				tail1 = tail1->next;  
			}
			ELink *tail2 = graph.vex[j].edge;    
	        while(tail2){
				if (tail2->adjvex==i){
					in++;
					break;
				}
				tail2 = tail2->next;   
			}
		}
		count=in+out;
		printf("结点%c：入度：%d 出度：%d 度：%d\n",graph.vex[i].vertex, in,out,count);
	}  
}
//4.1深度优先遍历-从下标为n的点出发    
void dfs(adjListGraph graph,int n){    
	ELink *p;
	printf("%c ",graph.vex[n].vertex);
	visited[n]=1;
	p=graph.vex[n].edge;
	while(p){
		if(!visited[p->adjvex]) dfs(graph,p->adjvex);
		p=p->next;
	}
}     
//4.2深度优先遍历-搜所有的点     
void dfsAll(adjListGraph graph){    
	for (int i = 0; i < graph.n; i++)
		visited[i] = 0;//访问标志数组初始化
	for (int i = 0; i < graph.n; i++)
		if (!visited[i]) dfs(graph, i);//对尚未访问的顶点调用DFS

}     
//5.1广度优先遍历-从下标为n的点出发
void bfs(adjListGraph graph,int n){   
	int vj,v;
	ELink *p;
	SqCyQueue Q;
	init(&Q);
	push(&Q,n);
	visited[n]=1;
	while(!isEmpty(Q)){
		pop(&Q,&v);
		printf("%c ",graph.vex[v].vertex);
		visited[v]=1;
		p=graph.vex[v].edge;
		while(p!=NULL){
			vj=p->adjvex;
			if(visited[vj]==0){
				visited[vj]=1;
				push(&Q,vj);
			}
			p=p->next;
		}
	} 
}     
//5.2广度优先遍历-搜所有的点     
void bfsAll(adjListGraph graph)    
{    
    for (int i = 0; i < graph.n; i++)
		visited[i] = 0;//访问标志数组初始化
	for (int i = 0; i < graph.n; i++)
		if (!visited[i]) bfs(graph, i);//对尚未访问的顶点调用BFS
}     
    
//0.初始化队列    
void init(SqCyQueue *q)    
{    
    q->front = q->rear = 0;     
}     
//1.队是否为空，如果为空返回1，否则返回0     
int isEmpty(SqCyQueue q)    
{    
    return q.front == q.rear;    
}    
//2.队列是否已满，如果满了返回1，否则返回0     
int isFull(SqCyQueue q)    
{    
    return (q.rear + 1) % M == q.front;    
}    
//3.入队，如果成功返回1，否则返回0     
int push(SqCyQueue *q,ElemType item)    
{    
    if(isFull(*q)){    
        printf("队列已满，入队失败！\n");    
        return 0;    
    }    
    q->data[q->rear] = item;    
    q->rear = (q->rear + 1) % M;    
    return 1;    
}    
//4.出队，如果成功返回1，否则返回0     
int pop(SqCyQueue *q,ElemType *item)    
{    
    if(isEmpty(*q)){    
        printf("队列为空，出队失败！\n");         
        return 0;    
    }    
    *item = q->data[q->front];    
    q->front = (q->front + 1) % M;    
    return 1;     
}    