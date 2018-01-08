//相关注释在数据结==结构书P34
#include<stdio.h>
#define MAXSIZE 100
typedef struct
{
	int date;
	int cur;
}componet,SLinkList[MAXSIZE];

void InitSpace_SL(SLinkList *space)//初始化一维数组space，将其各分量链成一个备用链表，space[0]->cur为头指针
{
	for (int i = 0; i < MAXSIZE - 1; i++)
	{
		space[i]->cur = i + 1;
	}
	space[MAXSIZE - 1]->cur = 0;
}

int Malloc_SL(SLinkList *space)//若备用链表非空，则返回分配的结点下标，否则返回0.(割下表头后的一个Node)
{
	int i = space[0]->cur;
	if (space[0]->cur)
	{
		space[0]->cur = space[i]->cur;
	}
	return i;
}

void Free_SL(SLinkList *space, int k)//将下标为k的空闲结点回收到备用链表
{
	space[k]->cur = space[0]->cur;
	space[0]->cur = k;
}

void difference(SLinkList *space, int S)//依次输入集合A和B，在一维数组space中建立表示集合(A-B)U（B-A)的静态链表，S为其头指针。                                         
{                                        //假设备用空间足够大，space[0].cur为其头指针
	InitSpace_SL(space);
	S = Malloc_SL(space);
	int r = S, lenA, lenB;
	scanf("%d%d", &lenA, &lenB);
	for (int j = 1; j <= lenA; j++)
	{
		int i = Malloc_SL(space);
		scanf("%d", space[i]->date);
		space[r]->cur = i;
		r = i;
	}
	space[r]->cur = 0;

	for (int j = 1; j <= lenB; j++)
	{
		int ch, p = S, k = space[S]->cur;
		scanf("%d", &ch);
		while (k != space[r]->cur&&space[k]->date != ch)
		{
			p = k;
			k = space[k]->cur;
		}
		if (space[k]->cur == space[r]->cur)
		{
			int temp = Malloc_SL(space);
			space[temp]->date = ch;
			space[temp]->cur = 0;//space[r].cur = 0
			space[r]->cur = temp;
			r = temp;
		}
		else
		{
			space[p]->cur = space[k]->cur;
			Free_SL(space, k);
			if (k == r)
			{
				r = p;
			}
		}
	}
}
