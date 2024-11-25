// ѭ������(˳��)
#include <stdio.h>
#define M (10000)
typedef int ElemType;
typedef struct{
    ElemType data[M]; // ���е�����
    int front, rear;  // ����ͷ����β��
} SqCyQueue;
// 0.��ʼ������
void init(SqCyQueue *q);
// 1.�����Ƿ�Ϊ�գ����Ϊ�շ���1�����򷵻�0
int isEmpty(SqCyQueue q);
// 2.�����Ƿ�������������˷���1�����򷵻�0
int isFull(SqCyQueue q);
// 3.��ӣ�����ɹ�����1�����򷵻�0
int push(SqCyQueue *q, ElemType item);
// 4.���ӣ�����ɹ�����1�����򷵻�0
int pop(SqCyQueue *q, ElemType *item);
// 5.ȡ����Ԫ�أ�����ɹ�����1�����򷵻�0
int getFront(SqCyQueue *q, ElemType *item);
// 6.������е�Ԫ�ظ���
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
// 0.��ʼ������
void init(SqCyQueue *q){
    q->front = q->rear = 0;
}
// 1.���Ƿ�Ϊ�գ����Ϊ�շ���1�����򷵻�0
int isEmpty(SqCyQueue q){
    return q.front == q.rear;
}
// 2.�����Ƿ�������������˷���1�����򷵻�0
int isFull(SqCyQueue q){
    return (q.rear + 1) % M == q.front;
}
// 3.��ӣ�����ɹ�����1�����򷵻�0
int push(SqCyQueue *q, ElemType item){
    if (isFull(*q)){
        printf("�������������ʧ�ܣ�\n");
        return 0;
    }
    q->data[q->rear] = item;
    q->rear = (q->rear + 1) % M;
    return 1;
}
int pop(SqCyQueue *q, ElemType *item){
    if (isEmpty(*q)){
        printf("����ʧ��");
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