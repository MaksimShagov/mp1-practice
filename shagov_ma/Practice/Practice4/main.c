#include <stdio.h>
#include <locale.h>

#define MAX 7
#define MAX_LEN 17

char codes[MAX][2] = { "1", "2", "3", "4", "5", "6", "7" };
char names[MAX][MAX_LEN] = { "����","����","����","���","������","��������","�����" };
int prices[MAX] = { 10, 20, 30, 40, 50, 60, 70 };
int discounts[MAX] = { 2, 3, 23, 11, 5, 9, 9 };
int user_choose1;
int check[100] = { 0 };

void call_menu()
{
	printf("\n���� �������\n");
	printf(" 1 - ����������� �����\n 2 - ����� �������� ���������������� ������\n");
	printf(" 3 - �������� ������ � ������ � ���\n 4 - ������������ ���\n 5 - ��������� �������� �����\n");
	printf(" 6 - ����� �� ���������\n");
}

void scan()
{
	int q;
	do {
		printf("������� �����-���\n");
		scanf("%d", &user_choose1);
		q = scan_error(user_choose1);
	} while (q == 0);
}

int scan_error(int user_choose1)
{
	int i, q;
	for (i = 0; i < MAX; i++)
	{
		q = 0;
		if ((user_choose1 < 10000) && (user_choose1 >= 1) && (user_choose1 == atoi(codes[i])))
		{
			q++;
			break;
		}
	}
	if (q == 0)
	{
		printf("\n������ � ����� �����-����� ���");
		printf("\n������� ����� ����� ���");
	}
	return q;
}

int search(int user_choose1)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		if (user_choose1 == atoi(codes[i]))
			return i;
	}
}

void info_items()
{
	int q;
	if (user_choose1 == -1)
	{
		printf("\n�� �� ������������� �����\n");
		return;
	}
	q = search(user_choose1);
	printf("\n�����  %s\n������ �� ���� %d\n", names[q], discounts[q]);
	printf("����� ���� ��� ������ %d\n�� ������� %.2f", prices[q], prices[q] * (1 - discounts[q] * 0.01f));
}

void print_items()
{
	int i, q = 0;
	for (i = 0; i < MAX; i++)
	{
		if (check[i] != 0)
		{
			q++;
			printf("%d. %s -- %s -- %d -- %.0f\n", q, names[i], codes[i], check[i], prices[i] * (1 - discounts[q] * 0.01f));
		}
	}
}

void add()
{
	check[search(user_choose1)]++;
	printf("\n����� ������� �������� � ���\n");
}

void total_price()
{
	int i = 0;
	float s = 0;
	for (i = 0; i < MAX; i++)
	{
		s += check[i] * prices[i] * (1 - discounts[i] * 0.01f);
	}
	printf("����� ���� %.0f\n", s);
}
void main()
{
	int i, pick, q;
	srand((unsigned int)time(0));
	setlocale(LC_ALL, "Russian");
	do {
		call_menu();
		scanf("%d", &pick);
		switch (pick)
		{
		case 1: scan(); break;
		case 2: info_items(); break;
		case 3: add(); break;
		case 4: print_items(); break;
		case 5: total_price(); break;
		}
	} while (pick != 6);
}