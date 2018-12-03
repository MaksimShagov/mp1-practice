#include <stdio.h>
#define k  10

void pick(int a[], int n)
{
	int i, t, j;
	int min, minind;
	for (i = 0; i < n; i++)
	{
		min = a[i];
		minind = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				minind = j;
			}
			t = a[i];
			a[i] = a[minind];
			a[minind] = t;
		}
	}
}

void paste(int a[], int n)
{
	int i, j, tmp;
	for (i = 1; i < n; i++)
	{
		j = i - 1;
		tmp = a[i];
		while ((j >= 0) && (a[j] > tmp))
		{
			a[j+1] = a[j];
			a[j] = tmp;
			j--;
		}
	}
}


void bubble_sort(int a[], int n)
{
	int i, j, tmp;
	for (i = 0; i < n - 1; i++)
		for (j = 1; j < n - i; j++)
			if (a[j - 1] > a[j])
			{
			tmp = a[j - 1];
			a[j - 1] = a[j];
			a[j] = tmp;
			}
}

void counting_sort(int a[], int n)
{
	int count[k];
	int i, j, b;
	b = 0;
	for (i = 0; i < k; i++)
	{
		count[i] = 0;
	}
	for  (i = 0; i < n; i++)
	{
		count[a[i]]++;
	}
	for (i = 0; i < k; i++)
	{
		a[b] = i;
		b++;
	}
}

void main()
{
	int a[k];
	for (i = 0; i < k; i++)
	{
		scanf("%d", &(a[i]));
	}

	for (i = 0; i < k; i++)
	{
		printf("%d", a[i]);
	}
}