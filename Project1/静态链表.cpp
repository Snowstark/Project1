//���ע�������ݽ�==�ṹ��P34
#include<stdio.h>
#define MAXSIZE 100
typedef struct
{
	int date;
	int cur;
}componet,SLinkList[MAXSIZE];

void InitSpace_SL(SLinkList *space)//��ʼ��һά����space���������������һ����������space[0]->curΪͷָ��
{
	for (int i = 0; i < MAXSIZE - 1; i++)
	{
		space[i]->cur = i + 1;
	}
	space[MAXSIZE - 1]->cur = 0;
}

int Malloc_SL(SLinkList *space)//����������ǿգ��򷵻ط���Ľ���±꣬���򷵻�0.(���±�ͷ���һ��Node)
{
	int i = space[0]->cur;
	if (space[0]->cur)
	{
		space[0]->cur = space[i]->cur;
	}
	return i;
}

void Free_SL(SLinkList *space, int k)//���±�Ϊk�Ŀ��н����յ���������
{
	space[k]->cur = space[0]->cur;
	space[0]->cur = k;
}

void difference(SLinkList *space, int S)//�������뼯��A��B����һά����space�н�����ʾ����(A-B)U��B-A)�ľ�̬����SΪ��ͷָ�롣                                         
{                                        //���豸�ÿռ��㹻��space[0].curΪ��ͷָ��
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
