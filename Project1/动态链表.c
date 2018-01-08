#include<stdio.h>

typedef struct  Node
{
	int date;
	struct Node *p;
}Node;

int creatNode(Node *p)
{
	p = (Node * )calloc(1, sizeof(Node));
	if (p = NULL)
	{
		printf("Error!");
		exit(1);
		return 0;
	}
	return 1;
}

int ListInsert_L(Node *L, int i, int n)
{
	Node *p = L;
	int j = 0;
	for (j; p&& j < i - 1; j++)
	{
		p = p->p;
	}
	if (!p || j > i - 1)
	{
		return 0;
	}
	Node *s;
	creatNode(s);
	s->date = n;
	s->p = p->p;
	p->p = s;
	return 1;
}

int ListDelete_L(Node *L, int i, int *e)
{
	Node *p = L;
	int j = 0;
	while (p->p&&j < i - 1 )
	{
		p = p->p;
		j++;
	}
	if (!p || j > i - 1)
	{
		return 0;
	}
	Node *temp = p->p;
	*e = temp->date;
	p->p = temp->p;
	free(temp);
	return 1;
}

void CreatList_L(Node *L, int n)
{
	creatNode(L);
	L->p = NULL;
	for (int i = n; i > 0; i--)
	{
		Node *p;
		creatNode(p);
		scanf("%d", &p->date);
		p->p = L->p;
		L->p = p->p;
	}
}

void MergeList_L(Node *La, Node *Lb, Node *Lc)
//已知la与lb按非递减排列
{
	Node *pa = La->p, *pb = Lb->p, *pc;
	Lc = pc = La;
	while (pa&&pb)
	{
		if (pa->date > pb->date)
		{
			pc->p = pa;
			pc = pa;
			pa = pa->p;
		}
		else
		{
			pc->p = pb;
			pc = pb;
			pb = pb->p;
		}
	}
	pc->p = pa ? pa : pb;
	free(Lb);
	free(La);
}

int main()
{
	Node *p[10];
	Node *L;
	L = (Node*)calloc(1, sizeof(Node));
	L->date = 3;
	L->p = NULL;
	p[1] = (Node*)calloc(1, sizeof(Node));
	p[1]->p = L->p;
	L->p = p[1];
	for (int i = 1; i < 10; i++)
	{
		p[i] = (Node*)calloc(1, sizeof(Node));
		p[i]->p = p[i - 1]->p;
		p[i - 1]->p = p[i];
	}
	return 0;
}