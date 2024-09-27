#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef enum {false, true} bool;
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�0��ʼ�洢 */
void PrintList( List L ); /* ����ʵ�֣�ϸ�ڲ��� */
bool Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;

    L = ReadInput();
    scanf("%d", &X);
    if ( Insert( L, X ) == false )
        printf("Insertion failed.\n");
    PrintList( L );

    return 0;
}


/* ��Ĵ��뽫��Ƕ������ */
bool Insert( List L, ElementType X ){
    int j,i;
    if (L->Last >= MAXSIZE - 1 ){
        return false;
    }
    for (int p = 0; p < MAXSIZE; p++)
    {
        if(L->Data[p]==X){
            return false;
        }
        if(L->Data[p]<X){
            i = p;
            break;
        }
    }
    
    if ((i < 0) || (i > L->Last + 1)){
        return false;
    }
    else{
        for (j = L->Last; j >= i; j--)
            L->Data[j + 1] = L->Data[j];
        L->Data[i] = X;
        L->Last++;
        return true;
    }
}