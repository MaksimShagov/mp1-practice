#include "Vector.h"

void main()
{
	Vector a, b;
	int s, q, w, i, *flag;
	double tmp;
	printf("Введите размерность векторов\n");
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
	printf("Выберете функцию для сортировки");
	printf("1 - Сложение. 2 - Разность. 3 - Скалярное произведение векторов. 4 - Угол. 5 - Длина вектора");
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		if (!sum(a, b).comp) printf_vector(sum(a, b));
		else
		{
			printf("Ошибка - разная размерномть векторов\n");
			return;
		}
		break;
	case 2:
		if (!sub(a, b).comp) printf_vector(sub(a, b));
		else
		{
			printf("Ошибка - разная размерномть векторов\n");
			return;
		}
		break;
	case 3:
		tmp = scalar(a, b, flag);
		if (*flag == 0)
		{
			printf("Ошибка - разная размерномть векторов\n");
			return;
		}
		printf("Скалярное произведение = %lf", tmp);
		break;
	case 4:
		tmp = angle(a, b, flag);
		if (*flag == 0)
		{
			printf("Ошибка - разная размерномть векторов\n");
			return;
		}
		printf("Угол между векторами = %lf", tmp);
		break;
	case 5:
		printf("\nДлину вектора 1 - а, 2 - b");
		scanf("%d", &s);
		if (s == 1)
		{
			tmp = length(a, flag);
			if (*flag == 0)
			{
				printf("Ошибка - разная размерномть векторов\n");
				return;
			}
			printf("Длина вектора а = %lf", tmp);
		}
		else 
		{
			tmp = length(b, flag);
			if (*flag == 0)
			{
				printf("Ошибка - разная размерномть векторов\n");
				return;
			}
			printf("Длина вектора b = %lf", tmp);
		}
		break;
	}
}