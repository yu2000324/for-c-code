#include <stdio.h>
#include <stdlib.h>
typedef struct BinrayTree
{
    char date;
    BinrayTree *lchild, *rchild;
} TreeNode, *Tree;
void CreatBinrayTree(Tree *T)
{
    (*T) = (TreeNode *)malloc(sizeof(TreeNode));
    (*T)->date = 'A';
    (*T)->lchild = NULL;
    (*T)->rchild = NULL;
}
int main()
{
    Tree T;
    CreatBinrayTree(&T);

    return 0;
}
