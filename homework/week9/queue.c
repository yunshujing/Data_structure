// ѭ������(˳��)
#include <stdio.h>
#define M (5)
typedef char ElemType;
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
int main(){
    printf("*****���˵�*******\n");
    printf("1.����ѭ������\n");
    printf("2.���һ��Ԫ��\n");
    printf("3.����һ��Ԫ��\n");
    printf("4.�˳�\n");
    SqCyQueue q;
    init(&q); // ��ʼ������
    ElemType x;
    for (;;){
        printf("��ѡ��(1-4):\n");
        int m;
        scanf("%d", &m);
        if (m < 0 || m > 4){
            printf("����ѡ����������ѡ��\n");
        }
        else if (m == 4){
            printf("�ڴ�����´�ʹ�ã�\n");
            break;
        }
        else if (m == 1){
            init(&q); // ��λ
            printf("�����Ѿ�����,������%d��Ԫ�أ�\n", getSize(q));
        }
        else if (m == 2){
            printf("��������ӵ�Ԫ��:");
            getchar(); // ���ջس���
            while (~scanf("%c", &x)){
                if (x >= 'a' && x <= 'z'){
                    if (!push(&q, x))
                        break;
                }
            }
            printf("��ӳɹ�,������%d��Ԫ�أ�\n", getSize(q));
        }
        else if (m == 3){
            if (pop(&q, &x))
                printf("���ӵ�Ԫ����%c,������%d��Ԫ�أ�\n", x, getSize(q));
        }
    }
    return 0;
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