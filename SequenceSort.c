#include "stdio.h"
typedef struct date
{
    int length;
    int Element[10];
} MyDate;
int SequenceSearch(MyDate *tbl, int k)            //传参tbl和哨兵k
{
    int i;
    tbl->Element[0] = k;                  //把数组第一个位置放置k
    for (i = tbl->length - 1; tbl->Element[i] != k; i--)       //写一个判断数组是否等于k的循环，中止时i就是k的位置
        ;
    return i;
}
int main()
{
    MyDate tbl;
    tbl.length = 10;
    printf("请输入9个数字\n");
    for (int i = 1; i < tbl.length; i++)
    {
        scanf("%d", &tbl.Element[i]);
    }
    int k;
    printf("请输入要找查的数字\n");
    scanf("%d", &k);
    int TblIndex = SequenceSearch(&tbl, k);
    printf("%d", TblIndex);
    return 0;
}