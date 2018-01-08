//利用链表创建多项式的抽象数据结构，失败了，明天再看看。问题出在指针的传递上，创建链表的方式有问题。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	float coef;
	int expn;
}term,int_;

struct polynomial
{
	term term;
	struct polynomial *next;
};
typedef struct polynomial polynomial;

int creatNode(polynomial *p)
{
	p = (polynomial *)calloc(1, sizeof(polynomial));
	if (p = NULL)
	{
		printf("Error!");
		exit(1);
		return 0;
	}
	return 1;
}

void creatList(polynomial *L,int n)
{
	creatNode(L);
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		polynomial *P;
		creatNode(P);
		scanf("%f%d", &P->term.coef, &P->term.expn);
		P->next = L->next;
		L->next = P;
	}
}

int main()
{
	polynomial *S1, *S2, *h1, *h2, *ans;
	creatList(S1, 3);
	creatList(S2, 3);
	creatList(ans, 6);
	h1 = S1->next;
	h2 = S2->next;
	while (h1 || h2)
	{
		if (h1->term.expn < h2->term.expn)
		{
			polynomial *temp = h1->next;
			h1->next = ans->next;
			ans->next = h1;
			h1 = temp;
		}
		else if(h1->term.expn > h2->term.expn)
		{
			polynomial *temp = h2->next;
			h2->next = ans->next;
			ans->next = h2;
			h2 = temp;
		}
		else
		{
			h1->term.coef += h2->term.coef;
			polynomial *temp = h1->next, *temp2 = h2;
			h1->next = ans->next;
			ans->next = h1;
			h1 = temp;
			h2 = h2->next;
			free(temp2);
		}
	}
	if (h1 == NULL)
	{
		ans->next = h2;
	}
	else
	{
		ans->next = h1;
	}
	free(S1);
	free(S2);
	h1 = ans;
	while (h1)
	{
		printf("%f^%d", h1->term.coef, h1->term.expn);
		h1 = h1->next;
	}
	getchar();
	getchar();
	return 0;
}