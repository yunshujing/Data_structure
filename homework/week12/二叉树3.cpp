void layOrder(BTree T){
    BTree A[100];
    BTree p;
    int rear = 0, front = 0, f = 1, ff = 1;
    if (T == NULL)
        return;
    else{
        A[rear++] = T;
        while (rear != front){
            p = A[front++];
            // visit(p);
            if (f == 0){
                if (p->lchild || p->rchild){
                    ff = 0;
                    break;
                }
            }
            else{
                if (p->lchild && p->rchild){
                    A[rear++] = p->lchild;
                    A[rear++] = p->rchild;
                }
                else if (p->lchild){
                    A[rear++] = p->lchild;
                    f = 0;
                }
                else if (p->rchild){
                    ff = 0;
                    break;
                }
                else{
                    f = 0;
                }
            }
        }
    }
    if (ff){
        printf("是完全二叉树\n");
    }
    else{
        printf("非完全二叉树\n");
    }
}