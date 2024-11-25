#include <iostream>
using namespace std;
#define max 11
typedef struct leaf
{
    int lchild = -1;
    int rchild = -1;
} leaf;

signed main(){
    int N, count = 0, track[max] = {0}, root;
    int child[max] = {-1};
    leaf tree[max];
    int queue[max] = {0};
    cin >> N;
    for (int i = 0; i < N; i++){// child[] 为所有的子树
        char left, right;
        cin >> left >> right;
        if (left != '-')
        {
            tree[i].lchild = left - '0';
            child[count++] = tree[i].lchild;
        }
        if (right != '-')
        {
            tree[i].rchild = right - '0';
            child[count++] = tree[i].rchild;
        }
    } 
    for (int i = 0; i < count; i++){
        track[child[i]] = -1;
    }
    for (int i = 0; i < N; i++){
        if (!track[i])
        {
            root = i;
            break;
        }
    }
    int front = 0;
    int rear = 1;
    queue[0] = root;
    while (front != rear){
        if (tree[queue[front]].lchild != -1){
            queue[rear] = tree[queue[front]].lchild;
            rear++;
        }
        if (tree[queue[front]].rchild != -1){
            queue[rear] = tree[queue[front]].rchild;
            rear++;
        }
        front++;
    }
    int flag = 0;
    for (int i = 0; i < rear; i++){
        if (tree[queue[i]].lchild == -1 && tree[queue[i]].rchild == -1){
            if (!flag){
                cout << queue[i];
                flag = 1;
            }
            else cout << " " << queue[i];
        }
    }
    return 0;
}