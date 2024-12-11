//1.�ڽӱ�����ͼ��������    
/****************************  
graph:ͼ  
edge :��  
vertex:���� vex  
adjacent:�ڽӵ� adj  
dfs:depth first search  �������������ջ���ݹ��㷨����дջ��  
bfs:breadth first search�����������������  
//����ͼ   
4 5  
A B C D  
A B  
A C  
D A   
B C  
C D  
//����ͼ  
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
#include <string.h> //memset-�ڴ��ʼ��     
#include <stdlib.h> //malloc free     
#define N (100 + 5)    
#define INF (0x3f3f3f3f)//�����16���� 00111111     
typedef char vexType;   //��������Ϊ�ַ���     
int visited[N];         //״̬���飬��ǵ�ǰ����û�б����ʹ�
//�ڽӱ�    
typedef struct edge{    
    int adjvex;         //�ڽӵ���±꣬��0��ʼ    
    int weight;         //�ߵ�Ȩ�أ���ѡ��     
    struct edge *next;  //��һ���ڽӵ�ĵ�ַ      
}ELink;     
//�ڽӵ�    
typedef struct{    
    vexType vertex;     //���������     
    ELink *edge;        //�ڽӱ�     
}VLink;    
//�ڽӱ��ͼ    
typedef struct{    
    int n,m;            //n�����㣬m����    
    VLink vex[N];       //�ڽӵ�����    
}adjListGraph;    
//1.�ڽӱ�ͼ    
void createGraph(adjListGraph *graph);     
//2.��ӡͼ    
void printGraph(adjListGraph graph);    
//3.���ͼ�Ķ���(��ȣ����ȣ�������    
void printDegree(adjListGraph graph);     
//4.1������ȱ���-���±�Ϊn�ĵ����    
void dfs(adjListGraph graph,int n);     
//4.2������ȱ���-�����еĵ�     
void dfsAll(adjListGraph graph);     
//5.1������ȱ���-���±�Ϊn�ĵ����    
void bfs(adjListGraph graph,int n);     
//5.2������ȱ���-�����еĵ�     
void bfsAll(adjListGraph graph);     
    
//ѭ������-����     
#define M (1000 + 5)    
typedef int ElemType;   //����Ԫ������   
typedef struct{    
    ElemType data[M];   //���е�����     
    int front,rear;     //����ͷ����β��     
}SqCyQueue;    
//0.��ʼ������    
void init(SqCyQueue *q);     
//1.�����Ƿ�Ϊ�գ����Ϊ�շ���1�����򷵻�0     
int isEmpty(SqCyQueue q);     
//2.�����Ƿ�������������˷���1�����򷵻�0     
int isFull(SqCyQueue q);     
//3.��ӣ�����ɹ�����1�����򷵻�0     
int push(SqCyQueue *q,ElemType item);    
//4.���ӣ�����ɹ�����1�����򷵻�0     
int pop(SqCyQueue *q,ElemType *item);     
    
int main(){    
    //stdio - stdin �� stdout    
    //stdin - standard input ��׼�����豸�����̣�     
    //stdout- standard output��׼����豸����ʾ����     
    //freopen("�ڽӱ�.txt","r",stdin);   //�����ض���Ϊ�ļ�     
//  freopen("output.txt","w",stdout);   //����ض���Ϊ�ļ�    
    memset(visited,0,sizeof(visited));  //��ʼ�����еĵ㶼û���ʹ�     
    adjListGraph g;    
    createGraph(&g);    
    printGraph(g);
    printDegree(g); 
    int n = 0;  
    printf("\n��%c�����������ȱ���\n",g.vex[n].vertex);     
    //�ӵ�1���㿪ʼ����     
    dfs(g,n); 
	printf("\n������ȱ���-�����еĵ� \n"); 
	dfsAll(g); 
	memset(visited,0,sizeof(visited));    
    printf("\n��%c�����������ȱ���\n",g.vex[n].vertex);     
    //�ӵ�1���㿪ʼ����     
    bfs(g,n);
    printf("\n������ȱ���-�����еĵ� \n"); 
	bfsAll(g);
    return 0;    
}     
//1.�ڽӱ�ͼ    
void createGraph(adjListGraph *graph)    
{    
    //1. ����n�������m����    
    scanf("%d%d",&graph->n,&graph->m);    
    //2.����n�����㣬����ͼ��n���ڽӵ���     
    for(int i = 0;i < graph->n;i++){    
        //������ַ������ǲ�����Ч��    
        while(1){    
            char c = getchar();    
            if(c >= 'A' && c <= 'Z' ||c >= '0' && c <= '9'){    
                graph->vex[i].vertex = c;    
                graph->vex[i].edge = NULL;       //ָ���ʼ��Ϊ��     
                break;    
            }    
        }     
    }    
    //3.��������m���ߵ�2������v1��v2 ��Ȩֵw   
    for(int i = 0;i < graph->m;i++){    
        char v1,v2; 
		int w;   
        scanf("\n%c %c",&v1,&v2); 
		//scanf("\n%d",&w);    
        //3.1���ڽӵ�����vex�в���v1��v2���±�k1��k2    
        int k1,k2;    
        for(int j = 0;j < graph->n;j++){    
            if(graph->vex[j].vertex == v1)    
                k1 = j;    
            if(graph->vex[j].vertex == v2)    
                k2 = j;    
        }     
    //  printf("k1 = %d,k2 = %d\n",k1,k2);    
        //��k2Ϊ�±괴���ڽӱ�    
        //1�������ڴ沢��ʼ��     
        ELink *p = (ELink*)malloc(sizeof(ELink));    
        p->adjvex = k2; 
		//p->weight=w;   
        p->next = NULL;     
        //2)�������߼���k1��Ӧ���ڽӵ�    
        //*************a.ͷ�巨*****************   
        p->next = graph->vex[k1].edge;//�½��ָ���ͷ   
        graph->vex[k1].edge = p;     //��ͷָ���½��   
        /*//*************b.β�巨*****************    
        //�������Ϊ�գ����½��p��Ϊ����ı�ͷ    
        if(graph->vex[k1].edge == NULL)    
            graph->vex[k1].edge = p;    
        //�������ѵ������β����Ȼ����½��p���뵽�����β��     
        else{    
            ELink *tail = graph->vex[k1].edge;    
            while(tail->next != NULL)    
                tail = tail->next;     
            tail->next = p;    
        }
        */    
        //����ͼ�Ļ��������һ���ߣ���k1Ϊ�±괴���ڽӱ�    
        //1�������ڴ沢��ʼ��     
        ELink *q = (ELink*)malloc(sizeof(ELink));    
        q->adjvex = k1;    
        q->next = NULL;     
        //2)�������߼���k2��Ӧ�����ڽӵ�    
        //*************a.ͷ�巨*****************   
        q->next = graph->vex[k2].edge;//�½��ָ���ͷ   
        graph->vex[k2].edge = q;     //��ͷָ���½��   
        /*//*************b.β�巨*****************  
        //�������Ϊ�գ����½��q��Ϊ����ı�ͷ    
        if(graph->vex[k2].edge == NULL)    
            graph->vex[k2].edge = q;    
        //�������ѵ������β����Ȼ����½��p���뵽�����β��     
        else{    
            ELink *tail = graph->vex[k2].edge;    
            while(tail->next != NULL)    
                tail = tail->next;     
            tail->next = q;    
        }               
        */    
    }    
}     
//2.��ӡͼ    
void printGraph(adjListGraph graph)    
{    
    //����ͼ��n���ڽӵ�     
    for(int i = 0;i < graph.n;i++){    
        //1.�����������    
        printf("%c",graph.vex[i].vertex);    
        //2.�����ǰ�ڽӵ�������ڽӱ�    
        //��������    
        ELink *p = graph.vex[i].edge;   //��ʼ��Ϊ����ı�ͷ    
        while(p){    
            int t = p->adjvex;       //�ڽӵ��±�     
            printf(" -> %d",t);      //����±�     
        //  printf(" -> %c",graph.vex[t].vertex);    
            p = p->next;    
        }     
        printf("\n");    
    }     
}     
//3.���ͼ�Ķ���(��ȣ����ȣ�������    
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
		printf("���%c����ȣ�%d ���ȣ�%d �ȣ�%d\n",graph.vex[i].vertex, in,out,count);
	}  
}
//4.1������ȱ���-���±�Ϊn�ĵ����    
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
//4.2������ȱ���-�����еĵ�     
void dfsAll(adjListGraph graph){    
	for (int i = 0; i < graph.n; i++)
		visited[i] = 0;//���ʱ�־�����ʼ��
	for (int i = 0; i < graph.n; i++)
		if (!visited[i]) dfs(graph, i);//����δ���ʵĶ������DFS

}     
//5.1������ȱ���-���±�Ϊn�ĵ����
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
//5.2������ȱ���-�����еĵ�     
void bfsAll(adjListGraph graph)    
{    
    for (int i = 0; i < graph.n; i++)
		visited[i] = 0;//���ʱ�־�����ʼ��
	for (int i = 0; i < graph.n; i++)
		if (!visited[i]) bfs(graph, i);//����δ���ʵĶ������BFS
}     
    
//0.��ʼ������    
void init(SqCyQueue *q)    
{    
    q->front = q->rear = 0;     
}     
//1.���Ƿ�Ϊ�գ����Ϊ�շ���1�����򷵻�0     
int isEmpty(SqCyQueue q)    
{    
    return q.front == q.rear;    
}    
//2.�����Ƿ�������������˷���1�����򷵻�0     
int isFull(SqCyQueue q)    
{    
    return (q.rear + 1) % M == q.front;    
}    
//3.��ӣ�����ɹ�����1�����򷵻�0     
int push(SqCyQueue *q,ElemType item)    
{    
    if(isFull(*q)){    
        printf("�������������ʧ�ܣ�\n");    
        return 0;    
    }    
    q->data[q->rear] = item;    
    q->rear = (q->rear + 1) % M;    
    return 1;    
}    
//4.���ӣ�����ɹ�����1�����򷵻�0     
int pop(SqCyQueue *q,ElemType *item)    
{    
    if(isEmpty(*q)){    
        printf("����Ϊ�գ�����ʧ�ܣ�\n");         
        return 0;    
    }    
    *item = q->data[q->front];    
    q->front = (q->front + 1) % M;    
    return 1;     
}    