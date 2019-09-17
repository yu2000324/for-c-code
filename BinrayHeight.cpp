#include <stdio.h>
#include <stdlib.h>
typedef struct BinrayTree
{
    char date;
    BinrayTree *lchild, *rchild;
} TreeNode, *Tree;
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
        (*T)->date = ch;
        CreatBinrayTree(&(*T)->lchild);
        CreatBinrayTree(&(*T)->rchild);
    }
}
void display(Tree T)
{
    if (T != NULL)
    {
        printf("%c", T->date);
        display(T->lchild);
        display(T->rchild);
    }
}
int HeightBinray(Tree T)
{
    int HL, HR, MaxH;
    if (T != NULL)
    {
        HL = HeightBinray(T->lchild);           //HL,HR,MaxH值都未初始化，由return 到最后一个节点赋值0
        HR = HeightBinray(T->rchild);           
        MaxH = (HR > HL) ? HR : HL;
        return MaxH + 1;                       //回溯时给HL或者HR赋值并且给自己加1,最后作为出口return给调用函数
    }
    else
    {
        return 0;
    }
}
int main()
{
    Tree T;
    CreatBinrayTree(&T);
    display(T);
    int i =HeightBinray(T);
    printf("\n%d",i);
    return 0;
}