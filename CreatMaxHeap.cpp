#include "stdio.h"
#include "stdlib.h"
typedef int DateType;
typedef struct Heap
{
    DateType *HeapData;
    int size;
    int Capacity;
} * MyHeap;
MyHeap CreatMaxHeap(int Maxsize)
{
    MyHeap H = (Heap *)malloc(sizeof(Heap));
    H->HeapData = (DateType *)malloc((Maxsize + 1) * sizeof(DateType));
    H->size = 0;
    H->Capacity = Maxsize;
    H->HeapData[0] = 10000;
    return H;
}
void AddNum(MyHeap H, int Num)
{
    H->HeapData[H->size + 1] = Num;
    H->size++;
}
int IsFull(MyHeap H)
{
    if (H->size == H->Capacity)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int IsEmpty(MyHeap H)
{
    if (H->size == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void InSert(MyHeap H, int InsertNum)
{
    int i = 0;
    if (IsFull(H) != 0)
    {
        printf("堆已满");
        return;
    }
    i = ++H->size;
    for (; H->HeapData[i / 2] < InsertNum; i = i / 2)
    {
        H->HeapData[i] = H->HeapData[i / 2];
    }
    H->HeapData[i] = InsertNum;
}
void DeleteMax(MyHeap H)
{
    int Parent, Child, Temp;
    if (!IsEmpty(H))
    {
        printf("堆已空");
    }
    Temp = H->HeapData[H->size--];
    H->HeapData[1] = Temp;
    for (Parent = 1; Parent * 2 <= H->size; Parent = Child)
    {
        Child = Parent * 2;
        if (Child != H->size && H->HeapData[Child] < H->HeapData[Child + 1])
        {
            Child++;
        }
        if (H->HeapData[Parent] > H->HeapData[Child])
        {
            break;
        }
        else
        {
            Temp=H->HeapData[Parent];
            H->HeapData[Parent] = H->HeapData[Child];
            H->HeapData[Child]=Temp;
        }
    }
}
void PercDown(MyHeap H,int index)
{
    int Parent, Child, Temp;
    if (!IsEmpty(H))
    {
        printf("堆已空");
    }
    Temp = H->HeapData[index];
    for (Parent = index; Parent * 2 <= H->size; Parent = Child)
    {
        Child = Parent * 2;
        if (Child != H->size && H->HeapData[Child] < H->HeapData[Child + 1])
        {
            Child++;
        }
        if (H->HeapData[Parent] > H->HeapData[Child])
        {
            break;
        }
        else
        {
            Temp=H->HeapData[Parent];
            H->HeapData[Parent] = H->HeapData[Child];
            H->HeapData[Child]=Temp;
        }
    } 
}
void BuildHeap(MyHeap H)
{
    for (int index=H->size/2; index>=1; index--)
    {
        PercDown(H,index);
    }
}
int main()
{
    int Num;
    MyHeap H = CreatMaxHeap(10);
    do
    {
        scanf("%d", &Num);
        if (Num == 0)
        {
            break;
        }
        AddNum(H, Num);
    } while (1);
    //InSert(H, 20);
    //DeleteMax(H);
    BuildHeap(H);
    for (int i = 0; i <= H->size; i++)
    {
        printf("%d\t", H->HeapData[i]);
    }
    return 0;
}