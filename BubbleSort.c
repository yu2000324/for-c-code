#include "stdio.h"
constexpr auto N = 10;
int main()
{
	int i, j, tmp;
	int Bubble[N];
	printf("please input Array number:");
	for (i = 0; i < N; i++)
	{
		scanf("%d", &Bubble[i]);
	}
	for (i = 0; i < N - 1; i++)
	{
		for (j = i; j < N - 1; j++)
		{
			if (Bubble[j] > Bubble[j + 1])
			{
				tmp = Bubble[j];
				Bubble[j] = Bubble[j + 1];
				Bubble[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		printf("%d ", Bubble[i]);
	}
}