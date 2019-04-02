#include "Vector.h"

void main()
{
	Vector a, b;
	int s, q, w, i, *flag;
	double tmp;
	printf("������� ����������� ��������\n");
	do
	{
		scanf("%d %d", &q, &w);
		a = create(q);
		for (i = 0; i < a.dim; i++)
		{
			scanf("%lf", &a.comp[i]);
		}
		b = create(w);
		for (i = 0; i < b.dim; i++)
		{
			scanf("%lf", &b.comp[i]);
		}
	} while ((q != 0) && (w != 0));
	print_vector(a);
	print_vector(b);
	printf("�������� ������� ��� ����������");
	printf("1 - ��������. 2 - ��������. 3 - ��������� ������������ ��������. 4 - ����. 5 - ����� �������");
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		if (!sum(a, b).comp) printf_vector(sum(a, b));
		else
		{
			printf("������ - ������ ����������� ��������\n");
			return;
		}
		break;
	case 2:
		if (!sub(a, b).comp) printf_vector(sub(a, b));
		else
		{
			printf("������ - ������ ����������� ��������\n");
			return;
		}
		break;
	case 3:
		tmp = scalar(a, b, flag);
		if (*flag == 0)
		{
			printf("������ - ������ ����������� ��������\n");
			return;
		}
		printf("��������� ������������ = %lf", tmp);
		break;
	case 4:
		tmp = angle(a, b, flag);
		if (*flag == 0)
		{
			printf("������ - ������ ����������� ��������\n");
			return;
		}
		printf("���� ����� ��������� = %lf", tmp);
		break;
	case 5:
		printf("\n����� ������� 1 - �, 2 - b");
		scanf("%d", &s);
		if (s == 1)
		{
			tmp = length(a, flag);
			if (*flag == 0)
			{
				printf("������ - ������ ����������� ��������\n");
				return;
			}
			printf("����� ������� � = %lf", tmp);
		}
		else 
		{
			tmp = length(b, flag);
			if (*flag == 0)
			{
				printf("������ - ������ ����������� ��������\n");
				return;
			}
			printf("����� ������� b = %lf", tmp);
		}
		break;
	}
}