#include <stdio.h>
#include <stdlib.h>
#define MaxSzie 10

typedef struct BinrayTree
{
    char Mychar;
    BinrayTree *lchild, *rchild;
} TreeNode, *Tree;
typedef struct MyQueue
{
    int Rear, Front;
    Tree Data[MaxSzie];
} Queue;

void CreatBinrayTree(Tree *T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        (*T) = NULL;
    }
    else
    {
        (*T) = (TreeNode *)malloc(sizeof(TreeNode));
        if (!*T) //内存分配失败退出程序
        {
            exit(-1);
        }
        (*T)->Mychar = ch;
        CreatBinrayTree(&(*T)->lchild);
        CreatBinrayTree(&(*T)->rchild);
    }
}

void PushQueue(Queue *Q, Tree T)
{
    Tree t = T;
    if ((Q->Rear + 1) % MaxSzie == Q->Front)
    {
        printf("队列已满");
        return;
    }
    Q->Rear = Q->Rear + 1;
    Q->Data[Q->Rear] = t;
}
Tree PopQueue(Queue *Q)
{
    if ((Q->Rear) % MaxSzie == Q->Front)
    {
        printf("队列已空");
        return NULL;
    }
    Q->Front = Q->Front + 1;
    return Q->Data[Q->Front];
}
Queue GradationTraversal(Tree T)
{
    Tree t = T;
    Queue Q;
    Q.Rear = 0;
    Q.Front = 0;
    PushQueue(&Q, t);
    while ((Q.Rear) % MaxSzie != Q.Front)
    {
        t = PopQueue(&Q);
        printf("%c", t->Mychar);
        if (t->lchild != NULL)
        {
            PushQueue(&Q, t->lchild);
        }
        if (t->rchild)
        {
            PushQueue(&Q, t->rchild);
        }
    }
}
int main()
{
    Tree T;
    CreatBinrayTree(&T);
    GradationTraversal(T);
    return 0;
}