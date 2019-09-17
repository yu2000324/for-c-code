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
Stack InOrderTraversal(Tree T)
{
    Tree t = T;
    Stack S;
    S.top = -1;
    while (t != NULL || IsEmpty(S) != 0)
    {
        while (t != NULL)
        {
            push(&S, t);
            printf("%c",t->Mychar);
            t = t->lchild;
        }
        if (IsEmpty(S) != 0)
        {
            t = pop(&S);
            t = t->rchild;
        }
    }
    return S;
}
int main()
{
    Tree T;
    CreatBinrayTree(&T);
    InOrderTraversal(T);
    return 0;
}