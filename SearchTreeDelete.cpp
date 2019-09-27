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
            T = T->lchild;
        }
    }
    printf("%d\n", T->data);
    return T;
}
Tree DeleteNode(Tree T, int AddNum) //使用递归的方式找查并删除节点
{
    Tree tmp; //设置一个中间节点;用于存放最小值的节点
    if (!T)
    {
        printf("要删除的元素未找到");
    }
    else if (T->data > AddNum)
    {
        T->lchild = DeleteNode(T->lchild, AddNum); //递归找查把左边return的节点存放在左边
    }
    else if (T->data < AddNum)
    {
        T->rchild = DeleteNode(T->rchild, AddNum); //递归找查把左边return的节点存放在左边
    }
    else
    {
        if (T->lchild && T->rchild) //如果两边都有节点的情况
        {
            tmp = FindMin(T->rchild);                   //tmp存最小值的节点
            T->data = tmp->data;                        //修改该节点的值
            T->rchild = DeleteNode(T->rchild, T->data); //把T的右节点作为根节点再次递归删除最小的节点
        }
        else
        {
            tmp = T;
            if (!T->lchild) //如果左边为空
            {
                T = T->rchild; //右边的节点替代该节点
            }
            else
            {
                T = T->lchild; //右边为空，左边的节点取代右边
            }
            free(tmp); //释放tmp;
        }
    }
    return T;
}
int main()
{
    Tree T;
    CreatBinrayTree(&T);
    DeleteNode(T, 15);
    return 0;
}