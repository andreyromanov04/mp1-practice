#include <stdio.h>
#define N 13
void scan(int num[N], int price[N], int disc[N], int code[N]);
void check(int num[N], int price[N], int disc[N]);
void itog(int num[N], int price[N], int disc[N]);
void main()
{
	int code[N] = { 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1000, 2001, 2002, 2003 };
	int price[N] = { 103, 680, 180, 236, 450, 103, 189, 167, 205, 380, 304, 199, 534 };
	int disc[N] = { 12, 15, 30, 20, 43, 16, 45, 10, 14, 23, 50, 47, 25 };
	int num[N] = { 0 };
	scan(num, price, disc, code);
	check(num, price, disc);
	itog(num, price, disc);
}
void scan(int num[N], int price[N], int disc[N], int code[N])
{
	int z, i;
	char name[N][40] = { "bread", "honey", "cream", "peach", "apple", "choco", "lemon", "sugar", "yeast", "water", "flour", "juice", "grape" };
	printf("Assortment:\n");
	for (i = 0; i < N; i++)
	{
		printf("%s - %d\n", &name[i], code[i]);
	}
	printf("\nVvedite shtrih-cod tovara. Esli vse tovari otskanirovani, vvedite 999\n");
	printf("CODE       NAME      PRICE        DISCOUNT\n");
	do
	{
		scanf("%d", &z);
		switch (z)
		{

		case 1001:
		{
			z = 0;
			num[z]++;
			break;
		}
		case 1002:
		{
			z = 1;
			(num[z])++;
			break;
		}
		case 1003:
		{
			z = 2;
			(num[z])++;
			break;
		}
		case 1004:
		{
			z = 3;
			(num[z])++;
			break;
		}
		case 1005:
		{
			z = 4;
			(num[z])++;
			break;
		}
		case 1006:
		{
			z = 5;
			(num[z])++;
			break;
		}
		case 1007:
		{
			z = 6;
			(num[z])++;
			break;
		}
		case 1008:
		{
			z = 7;
			(num[z])++;
			break;
		}
		case 1009:
		{
			z = 8;
			(num[z])++;
			break;
		}
		case 1000:
		{
			z = 9;
			(num[z])++;
			break;
		}
		case 2001:
		{
			z = 10;
			(num[z])++;
			break;
		}
		case 2002:
		{
			z = 11;
			(num[z])++;
			break;
		}
		case 2003:
		{
			z = 12;
			(num[z])++;
			break;
		}
		default:
		{
			printf("This code is not correct. Please, try again\n");
			continue;
		}
		}
		if (z != 999)
		{
			printf("      -   %s   -   %d     -      %d\n", name[z], price[z], disc[z]);
		}
		if ((z == 999) && (num[0] + num[1] + num[2] + num[2] + num[4] + num[5] + num[6] + num[7] + num[8] + num[9] + num[10] + num[11] + num[12] + num[0]) == 0)
		{
			printf("You must scan at least one position");
			z = 0;
		}
	} while ((z != 999));
}
void check(int num[N], int price[N], int disc[N])
{
	int i;
	float s = 0;
	char name[N][40] = { "bread", "honey", "cream", "peach", "apple", "choco", "lemon", "sugar", "yeast", "water", "flour", "juice", "grape" };
	printf("\n\n    CHEK:\n\n");
	printf("NAME       PRICE     DISCOUNT     NUMBER     TOTAL\n");
	for (i = 0; i < N; i++)
	{
		if (num[i] != 0)
		{
			s = price[i] * (1 - disc[i] * 0.01) * num[i];
			printf("%s   -   %d   -     %d     -     %d    -   %f\n", name[i], price[i], disc[i], num[i], s);
			s = 0;
		}
	}
}
void itog(int num[N], int price[N], int disc[N])
{
	float d, a = 0, o = 0;
	int i;
	for (i = 0; i < N; i++)
	{
		if (num[i] != 0)
		{
			a += price[i] * (1 - disc[i] * 0.01) * num[i];
			o += price[i] * num[i];
		}
	}
	d = ((o - a) / o) * 100;
	printf("\n\n       TOTAL PRICE    TOTAL DISCOUNT    TO BE PAID\n");
	printf("        %f      %f       %f", o, d, a);
}




