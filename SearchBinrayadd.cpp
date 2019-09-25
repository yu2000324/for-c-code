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
Tree InsertNode(Tree T,int AddNum)
{
    if (!T)
    {
        T=(TreeNode*)malloc(sizeof(TreeNode));
        T->data=AddNum;
        T->lchild=T->rchild=NULL;
    }
    if (T->data>AddNum)
    {
        T->lchild=InsertNode(T->lchild,AddNum);
    }
    else if (T->data<AddNum)
    {
        T->rchild=InsertNode(T->rchild,AddNum);
    }
    return T; 
}
int main()
{
    Tree T;
    CreatBinrayTree(&T);
    InsertNode(T,19);
    return 0;
}
