#include "stdio.h"
#include"stdlib.h"
typedef struct date
{
    int length;
    int Element[9];
} MyDate;
int BinraySearch(MyDate *tbl, int k)
{
    int left, right, mid, NotFound;
    left = 1; //初始化left
    right = tbl->length;
    NotFound = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (k < tbl->Element[mid - 1])
        {
            right = mid - 1;
        }
        else if (k > tbl->Element[mid - 1])
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return NotFound;
}
int main()
{
    MyDate tbl;
    tbl.length = 9;
    printf("请输入9个数字\n");
    for (int i = 0; i < tbl.length; i++)
    {
        scanf("%d", &tbl.Element[i]);
    }
    int k;
    printf("请输入要找查的数字\n");
    scanf("%d", &k);
    int TblIndex = BinraySearch(&tbl, k);
    printf("%d", TblIndex);
    system("pause");
    return 0;
}