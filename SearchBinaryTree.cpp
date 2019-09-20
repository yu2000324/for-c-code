#include <stdio.h>
#include <stdlib.h>
typedef struct BinrayTree
{
    int data;
    BinrayTree *lchild, *rchild;
} TreeNode, *Tree;
void CreatBinrayTree(Tree *T)
{
    int MyNum;
    scanf("%d", &MyNum);
    if (MyNum == -1)
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
        (*T)->data = MyNum;
        CreatBinrayTree(&(*T)->lchild);
        CreatBinrayTree(&(*T)->rchild);
    }
}
void display(Tree T)
{
    if (T == NULL)
    {
        return;
    }
    printf("%d ", T->data);
    display(T->lchild);
    display(T->rchild);
}
Tree SearchBinary(Tree T, int IsNum)
{
    if (!T)
    {
        printf("未找到该节点\n");
        return NULL;
    }
    if (T->data > IsNum)
    {
        SearchBinary(T->lchild, IsNum);
    }
    else if (T->data < IsNum)
    {
        SearchBinary(T->rchild, IsNum);
    }
    else if (T->data == IsNum)
    {
        printf("找到该节点\n");
        return T;
    }
}
Tree FindMax(Tree T)
{
    if (!T)
    {
        return NULL;
    }
    if (T->rchild)
    {
        T = T->rchild;
    }
    if (T->rchild == NULL)
    {
        printf("%d\n", T->data);
        return T;
    }
}
Tree FindMin(Tree T)
{
    if (!T)
    {
        return NULL;
    }
    if (T)
    {
        while (T->lchild)
        {
            T=T->lchild;
        }
    }
    printf("%d\n",T->data);
    return T;
}
int main()
{
    Tree T;
    CreatBinrayTree(&T);
    display(T);
    printf("\n");
    SearchBinary(T, 7);
    FindMin(T);
    FindMax(T);
    return 0;
}
