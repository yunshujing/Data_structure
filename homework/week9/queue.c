// 循环队列(顺序)
#include <stdio.h>
#define M (5)
typedef char ElemType;
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
int main(){
    printf("*****主菜单*******\n");
    printf("1.建立循环队列\n");
    printf("2.入队一个元素\n");
    printf("3.出队一个元素\n");
    printf("4.退出\n");
    SqCyQueue q;
    init(&q); // 初始化队列
    ElemType x;
    for (;;){
        printf("请选择(1-4):\n");
        int m;
        scanf("%d", &m);
        if (m < 0 || m > 4){
            printf("您的选择有误！请重选！\n");
        }
        else if (m == 4){
            printf("期待你的下次使用！\n");
            break;
        }
        else if (m == 1){
            init(&q); // 复位
            printf("队列已经创建,队中有%d个元素！\n", getSize(q));
        }
        else if (m == 2){
            printf("请输入入队的元素:");
            getchar(); // 吸收回车键
            while (~scanf("%c", &x)){
                if (x >= 'a' && x <= 'z'){
                    if (!push(&q, x))
                        break;
                }
            }
            printf("入队成功,队中有%d个元素！\n", getSize(q));
        }
        else if (m == 3){
            if (pop(&q, &x))
                printf("出队的元素是%c,队中有%d个元素！\n", x, getSize(q));
        }
    }
    return 0;
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