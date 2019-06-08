#include "stdio.h"
#include <malloc.h>
constexpr auto MAX_VERTEX_NUM = 50;//最大50个节点
typedef char VertexType[2];
typedef struct edgenode
{
	int adjvex;
	int value;
	struct edgenode* next;
}ArcNode;
typedef struct vexnode
{
	VertexType date;
	ArcNode * fristarc;
}VHeadNode;
typedef struct
{
	int Vertex_Num, Edge_Num;
	VHeadNode adjlist[MAX_VERTEX_NUM];
}Adjlist;
int creat(Adjlist*& G)
{
	int i, b, t, v;
	ArcNode* p;
	G = (Adjlist*)malloc(sizeof(Adjlist*));
	printf("please input vertex and edge:");
	scanf_s("%d%d", &G->Vertex_Num, &G->Edge_Num);
	for (i = 0; i < G->Vertex_Num; i++) 
	{
		G->adjlist[i].fristarc=NULL;
	}
	for (i = 0; i < G->Edge_Num; i++)
	{
		printf("edge[%d]=>", i);
		printf("startversex endversex value：");
		scanf_s("%d%d", &b, &t);
		if (b < G->Vertex_Num && t < G->Vertex_Num)
		{
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = t;
			p->next = G->adjlist[b].fristarc;
			G->adjlist[b].fristarc = p;
		}
		else
		{
			printf("输入错误请重新输入");
			return 0;
		}
	}
	return 1;
}
void Disp_list(Adjlist* &G)
{
	int i;
	ArcNode* p;
	printf("图的领接表图如下：");
	for (i = 0; i < G->Vertex_Num; i++)
	{
		printf("[%d]=>", i);

		p = G->adjlist[i].fristarc;
		while (p != NULL)
		{
			printf("(%d)->", p->adjvex);
			p = p->next;
		}
		printf("\n");
	}
}
int main()
{
	Adjlist *G;
	creat(G);
	Disp_list(G);
	return 0;
}