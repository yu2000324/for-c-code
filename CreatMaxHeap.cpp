#include "stdio.h"
#include "stdlib.h"
typedef  int DateType;
typedef struct Heap
{
    DateType *HeapData;
    int size;
    int Capacity; 
}*MyHeap;
void CreatMaxHeap(int Maxsize)
{
    MyHeap H=(Heap*)malloc(sizeof(Heap));
    H->HeapData=(DateType*)malloc((Maxsize+1)*sizeof(DateType));
    H->HeapData[0]=1;
    H->HeapData[12]=2;
    printf("%d",H->HeapData[12]);
}
int main()
{
    CreatMaxHeap(10);
    return 0;
}