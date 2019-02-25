// QuickSort.cpp: 定义控制台应用程序的入口点。
//

#include<iostream>

const int N  = 10;

int M[N] = { 10,6,8,5,1,9,3,8,2,7 };

using std::cout;
using std::endl;

void QuickSort(int x[], int Left, int Right);
void Swap(int *x,int *y);
void Insertsort(int x[],int Count);
int main()
{
	QuickSort(M, 0, N - 1);
	for (int i = 0; i < 10; i++)
	cout << M[i] << "  ";
    return 0;
}

void QuickSort(int x[], int Left, int Right)
{
	int Pivot;
	int i;
	int j;
	if (Left+3<=Right)
	{
		int Center = (Right - Left) / 2;
		if (x[Left] > x[Center])
			Swap(&x[Left], &x[Center]);
		if (x[Left] > x[Right])
			Swap(&x[Left], &x[Right]);
		if (x[Center] > x[Right])
			Swap(&x[Center], &x[Right]);
		Swap(&x[Center], &x[Right - 1]);
		Pivot = x[Right - 1];
		i = Left;
		j = Right - 1;
		for (;;)
		{
			while (x[++i] < Pivot) {}
			while (x[--j] > Pivot) {}
			if (i < j)
			{
				Swap(&x[i], &x[j]);
			}
			else
				break;
		}
		Swap(&x[i], &x[Right-1]);
		QuickSort(x, Left, i-1);
		QuickSort(x, i+1, Right);
	}
	else
	{
		Insertsort(M+Left, Right - Left+1);
	}
	//for (int k = 0; k < 10; k++)
	//{
	//	cout << M[k] << "  ";
	//}
	//cout << endl;
}

void Swap(int  *x, int  *y)
{
	int Temp;
	Temp = *x;
	*x = *y;
	*y = Temp;
}

void Insertsort(int x[], int Count)
{
	int j=0;
	for (int i = 1; i < Count; i++)
	{
		j = i;
		while (j > 0 && x[j] < x[j - 1])
		{
			Swap(&x[j], &x[j - 1]);
			j--;
		}
	}
}
