#include "Vector.h"

void main()
{
	Vector a, b;
	int s, q, w, i;
	double tmp, *flag;
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
		if (scalar(a, b, flag) == -1)
		{
			printf("Ошибка - разная размерномть векторов\n");
			return;
		}
		printf("Скалярное произведение = %lf", *flag);
		break;
	case 4:
		if (angle(a, b, flag) == -1)
		{
			printf("Ошибка - разная размерномть векторов\n");
			return;
		}
		printf("Угол между векторами = %lf", *flag);
		break;
	case 5:
		printf("\nДлину вектора 1 - а, 2 - b");
		scanf("%d", &s);
		if (s == 1)
		{
			if (length(a, flag) == -1)
			{
				printf("Ошибка - разная размерномть векторов\n");
				return;
			}
			printf("Длина вектора а = %lf", *flag);
		}
		else 
		{
			if (length(b, flag) == -1)
			{
				printf("Ошибка - разная размерномть векторов\n");
				return;
			}
			printf("Длина вектора b = %lf", *flag);
		}
		break;
	}
}
