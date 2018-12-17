#include <stdio.h>
#include <stdlib.h>
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

void merge(int a[], int l, int m, int r)
{
    int i, j, v = 0, c;
    int *arr;
    arr = (int*)malloc((r - l + 1) * sizeof(int));
    i = l;
    j = m + 1;
    while ((i <= m) && (j <= r))
    {
        if (a[i] < a[j])
        {
            arr[v++] = a[i++];
        }
        else
        {
            arr[v++] = a[j++];
        }
    }
    while (i <= m)
    {
        arr[v++] = a[i++];
    }
    while (j <= r)
    {
        arr[v++] = a[j++];
    }
    for (v = l; v <= r; v++)
	{
        a[v] = arr[v - l];
    }
}

void mergesort(int a[], int l, int r, int fileid)
{
    int m;
    if (l >= r) return;
    m = (l + r) / 2;
    mergesort(a, l, m, fileid);
	mergesort(a, m + 1, r, fileid);
}

void hoarasort(int* a, int first, int last)
{
 
int i = first, j = last;
int tmp, x = a[(first + last) / 2];
 
do {
   while (a[i] < x)
     i++;
   while (a[j] > x)
     j--;
 
   if (i <= j) 
   {
     if (i < j)
     {
       tmp=a[i];
       a[i]=a[j];
       a[j]=tmp;
     }
     i++;
     j--;
   }
} while (i <= j);
 
if (i < last)
   hoarasort(a, i, last);
if (first < j)
   hoarasort(a, first,j);
}

void main()
{
	int i, p, w, e;
	int a[k];
	w=0; e=10;
	for (i = 0; i < k; i++)
	{
		scanf("%d", &(a[i]));
	}
	printf("выберите сортировку ");
	scanf("%d", &p);
	switch (p)
	{
	case 1: bubble_sort(a, k);break;
	case 2: counting_sort(a, k);break;
	case 3: paste(a, k);break;
	case 4: pick(a, k);break;
	case 5: merge(a, e, w, e);break;
	case 6: hoarasort(a, w, e-1);break;
	}
	for (i = 0; i < k; i++)
	{
		printf("%d", a[i]);
	}
}