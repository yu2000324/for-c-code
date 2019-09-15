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
    char data[MaxSize];
    int top;
} Stack;
void push(Stack *S, char Mychar)
{
    if ((S->top) == MaxSize - 1)
    {
        printf("栈已满");
        return;
    }
    else
    {
        S->data[++(S->top)] = Mychar;
        return;
    }
}
char pop(Stack *S)
{
    if (S->top == -1)
    {
        printf("栈已空");
        return ' ';
    }
    else
    {
        return S->data[(S->top)--];
    }
}
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
int main()
{
    Tree T;
    CreatBinrayTree(&T);
    Stack S;
    S.top = -1;
    //push(&S, 'A');
    char i = pop(&S);
    printf("\n");
    printf("%d\n", S.top);
    printf("%c\n", S.data[0]);
    printf("%c", i);
    return 0;
}