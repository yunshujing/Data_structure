//����ͼ�Ĵ洢-�ڽӾ���  
/**************************** 
4 6 
A B C D 
A B 
A C 
A D 
B C 
B D 
C D  
*****************************/   
#include <stdio.h>  
#include <string.h>  
#define N (100 + 5)  
#define INF 0x3f3f3f3f   
typedef char VexType;   //���⣬��������Ϊ�ַ�����  
typedef int EdgeType;   //���⣬�ڽӾ�������Ϊ����   
//ͼ�ṹ-����ͱ� G = <V,E>  
typedef struct{  
    int n,m;            //n������m����  
    VexType vex[N];     //��������  
    EdgeType edge[N][N];//�ڽӾ���   
}adjGraph;   
adjGraph createGraph(); //�ڽӾ���ͼ  
void print(adjGraph g); //���ͼ����Ϣ(���㡢�ڽӾ���  
void printDegree(adjGraph g);//���ͼ��ÿ������Ķ���   

int main()  
{  
    //1.��ͼ  
    adjGraph g = createGraph();  
    //2.���ͼ����Ϣ  
    print(g);  
    printDegree(g);   
    return 0;  
}   
//�ڽӾ���ͼ  
adjGraph createGraph()  
{  
    adjGraph g;  
    //0.�ڽӾ����ʼ��Ϊ0  
    memset(g.edge,0,sizeof(g.edge));   
    scanf("%d%d",&g.n,&g.m);    //���붥�����ͱ���  
    getchar();      //���ջ��з�   
    //1.����n������  
    for(int i = 0;i < g.n;i++){  
        scanf("%c ",&g.vex[i]);  
    }   
    //2.����m���ߣ������ڽӾ����ͼ   
    for(int i = 0;i < g.m;i++){  
        char v1,v2;  
        scanf("\n%c %c",&v1,&v2);   //���뵱ǰ�ߵ�2������  
        int n1 = v1 - 'A',n2 = v2 - 'A';  
        //����ͼ���ڽӾ����Ӧ��n1��n2�к�n2��n1�ж���ֵΪ1  
        g.edge[n1][n2] = g.edge[n2][n1] = 1;   
    }  
    return g;  
}  
//���ͼ����Ϣ(���㡢�ڽӾ���  
void print(adjGraph g)  
{  
    printf("ͼ��%d�����㣬%d����\n",g.n,g.m);  
    printf("ͼ�Ķ����ǣ�");  
    for(int i = 0;i < g.n;i++){  
        printf("%c ",g.vex[i]);  
    }  
    //����ڽӾ���  
    printf("\nͼ���ڽӾ����ǣ�\n");  
    for(int i = 0;i < g.n;i++){  
        for(int j = 0;j < g.n;j++){  
            printf("%4d",g.edge[i][j]);  
        }  
        printf("\n");  
    }    
}  
//���ͼ��ÿ������Ķ���
void printDegree(adjGraph g)
{
    int degree;
    printf("\nͼ��ÿ������Ķ������£�\n");

    for (int i = 0; i < g.n; i++)
    {
        degree = 0;
        for (int j = 0; j < g.n; j++)
        {
            // ����ͼ�У�����Ķ����������ڽӾ����Ӧ�У����У���ֵΪ1��Ԫ�ظ���
            if (g.edge[i][j] == 1)
            {
                degree++;
            }
        }
        printf("���� %c �Ķ���Ϊ��%d\n", g.vex[i], degree);
    }
}