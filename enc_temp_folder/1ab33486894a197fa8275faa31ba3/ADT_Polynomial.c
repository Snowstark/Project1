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

polynomial* creatList(int n)
{
	polynomial *head,*cur;
	head = (polynomial*)calloc(1, sizeof(polynomial));
	if (head == NULL)
	{
		printf("Error!\n");
		exit(1);
	}
	cur = head;
	head->term.coef = -1;
	head->term.expn = n;
	head->next = NULL;

	for (int i = 0; i < n; i++)
	{
		polynomial *P;
		P = (polynomial*)calloc(1, sizeof(polynomial));
		if (P == NULL)
		{
			printf("Error!\n");
			exit(1);
		}
		printf("Please input the %dst term of the polynomial:(eg:2.3x^3)\n", i + 1);
		scanf("%fx^%d", &P->term.coef, &P->term.expn);
		P->next = NULL;
		cur->next = P;
		cur = P;
	}
	return head;
}

int main()
{
	polynomial *S1, *S2, *h1, *h2, *ans,*cur;
	printf("The first polynomial\n");
	S1 = creatList(3);
	printf("\nThe second polynomial\n");
	S2 = creatList(3);
	ans = (polynomial*)calloc(1, sizeof(polynomial));
	ans->next = NULL;
	ans->term.coef = -1;
	ans->term.expn = -1;

	cur = ans;
	h1 = S1->next;
	h2 = S2->next;
	while (h1 && h2)
	{
		if (h1->term.expn < h2->term.expn)
		{
			polynomial *temp = h1;

			cur->next = temp;

			cur = cur->next;
			h1 = h1->next;
			temp->next = NULL;
		}
		else if(h1->term.expn > h2->term.expn)
		{
			polynomial *temp = h2;

			cur->next = temp;

			cur = cur->next;
			h2 = h2->next;
			temp->next = NULL;
		}
		else
		{
			polynomial *temp1 = h1,*temp2 = h2;

			h1->term.coef += h2->term.coef;
			cur->next = temp1;

			cur = cur->next;
			h1 = h1->next;
			h2 = h2->next;
			temp1->next = NULL;

			free(temp2);
		}
	}
	if (h1 == NULL)
	{
		cur->next = h2;
	}
	else
	{
		cur->next = h1;
	}
	free(S1);
	free(S2);
	cur = ans->next;
	printf("The final polynomial:\n");
	printf("F(x) = ");
	while (cur)
	{
		if (cur->next == NULL)
		{
			printf("%.2fx^%d\n", cur->term.coef, cur->term.expn);
		}
		else
		{
			printf("%.2fx^%d + ", cur->term.coef, cur->term.expn);
		}
		cur = cur->next;
	}
	getchar();
	getchar();
	getchar();
	getchar();
	return 0;
}
void win(int n)
{
	printf("%d", n);
}