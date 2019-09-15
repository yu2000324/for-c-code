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
        if (!*T)                                         //内存分配失败退出程序
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
    if (T == NULL)
    {
        return;
    }
    printf("%c", T->date);
    display(T->lchild);
    display(T->rchild);
}
int main()
{
    Tree T;
    CreatBinrayTree(&T);
    display(T);
    return 0;
}
