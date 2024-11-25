// 循环队列(顺序)
#include <stdio.h>
#define M (10000)
typedef int ElemType;
typedef struct{
    ElemType data[M]; // 队列的数据
    int front, rear;  // 队列头部和尾部
} SqCyQueue;
// 0.初始化队列
void init(SqCyQueue *q);
// 1.队列是否为空，如果为空返回1，否则返回0
int isEmpty(SqCyQueue q);
// 2.队列是否已满，如果满了返回1，否则返回0
int isFull(SqCyQueue q);
// 3.入队，如果成功返回1，否则返回0
int push(SqCyQueue *q, ElemType item);
// 4.出队，如果成功返回1，否则返回0
int pop(SqCyQueue *q, ElemType *item);
// 5.取队首元素，如果成功返回1，否则返回0
int getFront(SqCyQueue *q, ElemType *item);
// 6.求队列中的元素个数
int getSize(SqCyQueue q);
void circle(int n, int k, int m);
void circle(int n, int k, int m){
    SqCyQueue q;
    init(&q);
    for (int i = 1; i <= n; i++){
        push(&q, i);
    }
    for (int i = 1; i < k; i++){
        int x;
        pop(&q, &x);
        push(&q, x);
    }
    while (!isEmpty(q)){
        for (int i = 1; i < m; i++){
            int y;
            pop(&q, &y);
            push(&q, y);
        }
        int out;
        pop(&q, &out);
        printf("%d ", out);
    }
}
int main(){
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    circle(n, k, m);
}
// 0.初始化队列
void init(SqCyQueue *q){
    q->front = q->rear = 0;
}
// 1.队是否为空，如果为空返回1，否则返回0
int isEmpty(SqCyQueue q){
    return q.front == q.rear;
}
// 2.队列是否已满，如果满了返回1，否则返回0
int isFull(SqCyQueue q){
    return (q.rear + 1) % M == q.front;
}
// 3.入队，如果成功返回1，否则返回0
int push(SqCyQueue *q, ElemType item){
    if (isFull(*q)){
        printf("队列已满，入队失败！\n");
        return 0;
    }
    q->data[q->rear] = item;
    q->rear = (q->rear + 1) % M;
    return 1;
}
int pop(SqCyQueue *q, ElemType *item){
    if (isEmpty(*q)){
        printf("出队失败");
        return 0;
    }
    *item = q->data[q->front];
    q->front = (q->front + 1) % M;
    return 1;
}
int getFront(SqCyQueue *q, ElemType *item){
    if (isEmpty(*q)){
        printf("queue is empty");
        return 0;
    }
    *item = q->data[q->front];
    return 1;
}
int getSize(SqCyQueue q){
    return (q.rear - q.front + M) % M;
}