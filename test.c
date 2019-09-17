#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10

typedef struct BinrayTree
{
    char Mychar;
    BinrayTree *lchild, *rchild;
} TreeNode, *Tree;
typedef struct
{
    Tree data[MaxSize];
    int top;
} Stack;
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
void push(Stack *S, Tree T)
{
    Tree t = T;
    if ((S->top) == MaxSize - 1)
    {
        printf("栈已满");
        return;
    }
    else
    {
        S->data[++(S->top)] = t;
        return;
    }
}
Tree pop(Stack *S)
{
    if (S->top == -1)
    {
        printf("栈已空");
        return NULL;
    }
    else
    {
        return S->data[(S->top)--];
    }
}
int IsEmpty(Stack S)
{
    S.top = S.top + 1;
    return S.top;
}
void InOrderTraversal(Tree T, Stack *S)
{
    Tree t = T;
    Stack S 
    while (/* condition */)
    {
        /* code */
    }
}
int main()
{
    Tree T;
    CreatBinrayTree(&T);
    Stack S;
    S.top = -1;
    push(&S, T);
    pop(&S);
    IsEmpty(S);
    int i = 0;
    return 0;
}